/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */
#include "common/debug.h"
#include "common/file.h"
#include "common/error.h"

#include "hdb/hdb.h"

namespace HDB {

FileMan::FileMan() {
	_mpcFile = new Common::File;
}

bool FileMan::openMPC(const Common::String &filename) {
	uint32 offset;

	if (!_mpcFile->open(filename)) {
		error("FileMan::openMSD(): Error reading the MSD file");
		return false;
	}

	_dataHeader.id = _mpcFile->readUint32BE();

	if (_dataHeader.id == MKTAG('M', 'P', 'C', 'C')) {
		_compressed = true;
		debug("COMPRESSED FILE");
		return false;
	}
	else if (_dataHeader.id == MKTAG('M', 'P', 'C', 'U')) {
		_compressed = false;

		offset = _mpcFile->readUint32LE();
		_mpcFile->seek((int32)offset);

		// Note: The MPC archive format assumes the offset to be uint32,
		// but Common::File::seek() takes the offset as int32.

		_dataHeader.dirSize = _mpcFile->readUint32LE();

		debug(8, "MPC: Read %d entries", _dataHeader.dirSize);

		for (uint32 fileIndex = 0; fileIndex < _dataHeader.dirSize; fileIndex++) {
			MPCEntry *dirEntry = new MPCEntry();

			for (int i = 0; i < 64; i++) {
				dirEntry->filename[i] = _mpcFile->readByte();
			}

			dirEntry->offset = _mpcFile->readUint32LE();
			dirEntry->length = _mpcFile->readUint32LE();
			dirEntry->ulength = _mpcFile->readUint32LE();
			dirEntry->type = (DataType)_mpcFile->readUint32LE();

			_dir.push_back(dirEntry);
		}

		return true;

	}

	error("Invalid MPC File.");
	return false;

}

void FileMan::closeMPC() {
	_dir.clear();
	_mpcFile->close();
}

void FileMan::seek(int32 offset, int flag) {
	_mpcFile->seek(offset, flag);
}

Common::SeekableReadStream *FileMan::findFirstData(const char *string, DataType type) {
	Common::String fileString;
	MPCEntry *file = NULL;

	char fname[128];
	strcpy(fname, string);
	char *pDest = strrchr(fname, '.');
	if (pDest)
		*pDest = '_';

	debug(4, "Looking for Data: '%s' <- '%s'", fname, string);

	// Find MPC Entry
	for (MPCIterator it = _dir.begin(); it != _dir.end(); it++) {
		fileString = (*it)->filename;
		if (fileString.equals(fname)) {
			if ((*it)->type == type) {
				file = *it;
				break;
			} else {
				debug(4, "Found Data but type mismatch: '%s', target: %d, found: %d", fname, type, (*it)->type);
			}
		}
	}

	if (file == NULL) {
		debug(4, "Couldn't find Data: '%s'", fname);
		return NULL;
	}

	// Load corresponding file into a buffer
	_mpcFile->seek(file->offset);
	byte *buffer = new byte[file->ulength];

	_mpcFile->read(buffer, file->ulength);

	// Return buffer wrapped in a MemoryReadStream
	return new Common::MemoryReadStream(buffer, file->ulength, DisposeAfterUse::YES);
}

int32 FileMan::getLength(const char *string, DataType type) {
	Common::String fileString;
	MPCEntry *file = NULL;

	char fname[128];
	strcpy(fname, string);
	char *pDest = strrchr(fname, '.');
	if (pDest)
		*pDest = '_';

	// Find MPC Entry
	for (MPCIterator it = _dir.begin(); it != _dir.end(); it++) {
		fileString = (*it)->filename;
		if (fileString.contains(fname)) {
			if ((*it)->type == type) {
				file = *it;
				break;
			}
		}
	}

	if (file == NULL) {
		return 0;
	}

	return file->ulength;
}

int FileMan::getCount(const char *subString, DataType type) {
	int count = 0;
	Common::String fileString;

	for (MPCIterator it = _dir.begin(); it != _dir.end(); it++) {
		fileString = (*it)->filename;
		if (fileString.contains(subString)) {
			if ((*it)->type == type) {
				count++;
			}
		}
	}

	return count;
}

Common::Array<const char *> *FileMan::findFiles(const char *string, DataType type) {
	Common::Array<const char *> *result = new Common::Array<const char *>;
	Common::String fileString;

	// Find MPC Entry
	for (MPCIterator it = _dir.begin(); it != _dir.end(); it++) {
		fileString = (*it)->filename;
		if (fileString.contains(string)) {
			if ((*it)->type == type) {
				result->push_back((*it)->filename);
			}
		}
	}

	return result;
}

#if 0
MPCEntry **FileMan::findNextData(MPCIterator begin) {
	Common::String fileString;

	for (MPCIterator it = begin+1; it != _dir.end(); it++) {
		fileString = (*it)->filename;
		if (fileString.contains((*begin)->filename)) {
			if ((*it)->type == (*begin)->type) {
				return it;
			}
		}
	}
	return NULL;
}

#endif

} // End of Namespace HDB
