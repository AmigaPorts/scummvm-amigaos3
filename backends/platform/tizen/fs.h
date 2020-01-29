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

#ifndef TIZEN_FILESYSTEM_H
#define TIZEN_FILESYSTEM_H

#include <FBaseString.h>
#include <FBaseUtilStringUtil.h>
#include <FIoDirectory.h>
#include <FIoFile.h>

#include "config.h"
#include "common/scummsys.h"
#include "common/stream.h"
#include "backends/fs/abstract-fs.h"

using namespace Tizen::Io;
using namespace Tizen::Base;
using namespace Tizen::Base::Utility;

//
// converts a Tizen (wchar) String into a scummVM (char) string
//
Common::String fromString(const Tizen::Base::String &in);

//
// Enumerates the possible system paths
//
enum SystemPath { kData, kResource, kSdCard, kMedia, kShared };

/**
 * Implementation of the ScummVM file system API based on TIZEN.
 *
 * Parts of this class are documented in the base interface class, AbstractFSNode.
 */
class TizenFilesystemNode : public AbstractFSNode {
public:
	/**
	 * Creates a TizenFilesystemNode for a given path.
	 *
	 * @param path the path the new node should point to.
	 */
	TizenFilesystemNode(const Common::String &path);

	/**
	 * Creates a TizenFilesystemNode from the given Tizen internal path
	 *
	 * @param path the path the new node should point to.
	 */
	TizenFilesystemNode(SystemPath systemPath);

	Common::String getDisplayName() const { return _displayName; }
	Common::String getName() const { return _displayName; }
	Common::String getPath() const { return _path; }

	bool exists() const;
	bool isDirectory() const;
	bool isReadable() const;
	bool isWritable() const;

	AbstractFSNode *getChild(const Common::String &n) const;
	bool getChildren(AbstractFSList &list, ListMode mode, bool hidden) const;
	AbstractFSNode *getParent() const;

	Common::SeekableReadStream *createReadStream();
	Common::WriteStream *createWriteStream();
	bool createDirectory();

protected:
	TizenFilesystemNode(const Common::String &root, const Common::String &p);
	void init(const Common::String &nodePath);

	Common::String _displayName;
	Common::String _path;
	String _unicodePath;
	bool _isValid;
	bool _isVirtualDir;
	FileAttributes _attr;
};

#endif
