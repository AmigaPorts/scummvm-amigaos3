/* ScummVM - Scumm Interpreter
 * Copyright (C) 2003-2005 Andreas 'Sprawl' Karlsson - Original EPOC port, ESDL
 * Copyright (C) 2003-2005 Lars 'AnotherGuest' Persson - Original EPOC port, Audio System
 * Copyright (C) 2005 Jurgen 'SumthinWicked' Braam - EPOC/CVS maintainer
 * Copyright (C) 2005 The ScummVM project
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
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * $Header$
 */

#if defined (__SYMBIAN32__) 
#include "common/stdafx.h"
#include "../fs.h"

#include <dirent.h>
#include <eikenv.h>
#include <f32file.h>

/*
 * Implementation of the ScummVM file system API based on POSIX.
 */

class SymbianFilesystemNode : public AbstractFilesystemNode {
protected:
	String _displayName;
	bool _isDirectory;
	bool _isValid;
	String _path;
	bool _isPseudoRoot;

public:
	SymbianFilesystemNode(bool aIsRoot);
	SymbianFilesystemNode(const String &path);
	SymbianFilesystemNode(const SymbianFilesystemNode *node);
	virtual String displayName() const { return _displayName; }
	virtual bool isValid() const { return _isValid; }
	virtual bool isDirectory() const { return _isDirectory; }
	virtual String path() const { return _path; }

	virtual FSList listDir(ListMode mode = kListDirectoriesOnly) const;
	virtual AbstractFilesystemNode *parent() const;
};


static const char *lastPathComponent(const Common::String &str) {
	const char *start = str.c_str();
	const char *cur = start + str.size() - 2;
	
	while (cur > start && *cur != '\\') {
		--cur;
	}
	
	return cur+1;
}

AbstractFilesystemNode *FilesystemNode::getRoot() {
	return new SymbianFilesystemNode(true);
}

AbstractFilesystemNode *FilesystemNode::getNodeForPath(const String &path) {
	return new SymbianFilesystemNode(path);
}

SymbianFilesystemNode::SymbianFilesystemNode(bool aIsRoot) {
	_path = "";
	_isValid = true;
	_isDirectory = true;
	_isPseudoRoot = aIsRoot;
	_displayName = "Root";

}

// SumthinWicked says: added next function myself, since it was not in 0.7.1.
// might still be a little buggy, or simply the reason ScummVM can't run any 
// games on the phone yet :P
SymbianFilesystemNode::SymbianFilesystemNode(const String &path) {
	if (path.size() == 0)
		_isPseudoRoot = true;
	_path = path;
	const char *dsplName = NULL, *pos = path.c_str();
	while (*pos)
		if (*pos++ == '/')
			dsplName = pos;
	_displayName = String(dsplName);
	_isValid = true;
	_isDirectory = true;
}

SymbianFilesystemNode::SymbianFilesystemNode(const SymbianFilesystemNode *node) {
	_displayName = node->_displayName;
	_isValid = node->_isValid;
	_isDirectory = node->_isDirectory;
	_path = node->_path;
	_isPseudoRoot = node->_isPseudoRoot;
}

FSList SymbianFilesystemNode::listDir(ListMode mode) const {
	assert(_isDirectory);
	FSList myList;

	if (_isPseudoRoot) {
		// Drives enumeration
		TDriveList drivelist;
		CEikonEnv::Static()->FsSession().DriveList(drivelist);
		for (int loop=0;loop<KMaxDrives;loop++) {
			if(drivelist[loop]>0) {
				SymbianFilesystemNode entry(false);		
				char drive_name[2];
				drive_name[0] = loop+'A';
				drive_name[1] = '\0';
				entry._displayName = drive_name;
				entry._isDirectory = true;
				entry._isValid = true;
				entry._isPseudoRoot = false;
				char path[10];
				sprintf(path,"%c:\\",loop+'A');
				entry._path=path;
				myList.push_back(wrap(new SymbianFilesystemNode(&entry)));
			}
		}
	} else {
		TPtrC8 ptr((const unsigned char*)_path.c_str(),_path.size());
		TFileName fname;
		fname.Copy(ptr);
		TBuf8<256>nameBuf;
		CDir* dirPtr;
		if(CEikonEnv::Static()->FsSession().GetDir(fname,KEntryAttNormal|KEntryAttDir,0,dirPtr)==KErrNone) {
			CleanupStack::PushL(dirPtr);
			TInt cnt=dirPtr->Count();
			for(TInt loop=0;loop<cnt;loop++) {
				TEntry fileentry=(*dirPtr)[loop];
				nameBuf.Copy(fileentry.iName);
				SymbianFilesystemNode entry(false);
				entry._isPseudoRoot = false;
				
				entry._displayName =(char*)nameBuf.PtrZ();
				entry._path = _path;
				entry._path +=(char*)nameBuf.PtrZ();
				entry._isDirectory = fileentry.IsDir();
				
				// Honor the chosen mode
				if ((mode == kListFilesOnly && entry._isDirectory) ||
					(mode == kListDirectoriesOnly && !entry._isDirectory))
					continue;
				
				if (entry._isDirectory)
					entry._path += "\\";
				myList.push_back(wrap(new SymbianFilesystemNode(&entry)));
			}
			CleanupStack::PopAndDestroy(dirPtr);
		}

	}
	return myList;
}

AbstractFilesystemNode *SymbianFilesystemNode::parent() const {
	SymbianFilesystemNode *p =NULL;

	// Root node is its own parent. Still we can't just return this
	// as the GUI code will call delete on the old node.
	if (!_isPseudoRoot && _path.size() > 3) {
		p=new SymbianFilesystemNode(false);
		const char *start = _path.c_str();
		const char *end = lastPathComponent(_path);

		p->_path = String(start, end - start);
		p->_isValid = true;
		p->_isDirectory = true;
		p->_displayName = lastPathComponent(p->_path);
	}
	else
	{
		p=new SymbianFilesystemNode(true);
	}
	return p;
}

#endif // defined(__SYMBIAN32__)
