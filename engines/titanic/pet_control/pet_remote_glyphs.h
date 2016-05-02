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

#ifndef TITANIC_PET_REMOTE_GLYPHS_H
#define TITANIC_PET_REMOTE_GLYPHS_H

#include "titanic/pet_control/pet_glyphs.h"
#include "titanic/pet_control/pet_gfx_element.h"

namespace Titanic {

enum RemoteGlyph {
	GLYPH_SUMMON_ELEVATOR = 0, GLYPH_SUMMON_PELLERATOR = 1,
	GLYPH_TELEVISION_CONTROL = 2
};

enum RemoteMessage {
	RMSG_LEFT = 0, RMSG_RIGHT = 1, RMSG_UP = 2, RMSG_DOWN = 3, RMSG_ACTIVATE = 4
};

class CPetRemote;

class CPetRemoteGlyphs : public CPetGlyphs {
public:
	/**
	 * Returns the owning CPetRemote
	 */
	CPetRemote *getOwner() const;

	/**
	 * Generates a PET message
	 */
	void generateMessage(RemoteMessage msgNum, const CString &name, int num = -1);
};

class CPetRemoteGlyph : public CPetGlyph {
protected:
	CPetGfxElement *_gfxElement;
protected:
	CPetRemoteGlyph() : CPetGlyph(), _gfxElement(nullptr) {}

	/**
	 * Set defaults for the glyph
	 */
	void setDefaults(const CString &name, CPetControl *petControl);

	/**
	 * Get the owner
	 */
	CPetRemoteGlyphs *getOwner() const;

	/**
	 * Get an element by id from the parent Remote section
	 */
	CPetGfxElement *getElement(uint id) const;
};

class CBasicRemoteGlyph : public CPetRemoteGlyph {
private:
	CString _gfxName, _tooltip, _msgString;
public:
	CBasicRemoteGlyph(const CString &gfxName, const CString &tooltip,
		const CString &msgString) : CPetRemoteGlyph(), 
		_gfxName(gfxName), _tooltip(tooltip), _msgString(msgString) {}

	/**
	 * Setup the glyph
	 */
	virtual bool setup(CPetControl *petControl, CPetGlyphs *owner);

	/**
	 * Handles any secondary drawing of the glyph
	 */
	virtual void draw2(CScreenManager *screenManager);

	/**
	 * Called for mouse button down messages
	 */
	virtual bool MouseButtonDownMsg(const Point &pt);

	/**
	 * Handles mouse button up messages
	 */
	virtual bool MouseButtonUpMsg(const Point &pt);
	
	/**
	 * Returns the tooltip text for when the glyph is selected
	 */
	virtual void getTooltip(CPetText *text);
};

class CToggleRemoteGlyph : public CPetRemoteGlyph {
protected:
	CPetGfxElement *_gfxElement;
	bool _flag;
public:
	CToggleRemoteGlyph() : CPetRemoteGlyph(), _gfxElement(nullptr), _flag(false) {}

	/**
	 * Setup the glyph
	 */
	virtual bool setup(CPetControl *petControl, CPetGlyphs *owner);

	/**
	 * Handles any secondary drawing of the glyph
	 */
	virtual void draw2(CScreenManager *screenManager);

	/**
	 * Called for mouse button down messages
	 */
	virtual bool MouseButtonDownMsg(const Point &pt);
};

class CSummonElevatorGlyph : public CBasicRemoteGlyph {
public:
	CSummonElevatorGlyph() : CBasicRemoteGlyph(
		"3PetLift", "Summon Elevator", "Lift") {}
};

class CSummonPelleratorGlyph : public CBasicRemoteGlyph {
public:
	CSummonPelleratorGlyph() : CBasicRemoteGlyph(
		"3PetPellerator", "Summon Pellerator", "Pellerator") {}
};

class CTelevisionControlGlyph : public CPetRemoteGlyph {
private:
	bool _flag;
	CPetGfxElement *_up, *_down, *_onOff;
public:
	CTelevisionControlGlyph() : CPetRemoteGlyph(), _flag(false),
		_up(nullptr), _down(nullptr), _onOff(nullptr) {}

	/**
	 * Setup the glyph
	 */
	virtual bool setup(CPetControl *petControl, CPetGlyphs *owner);

	/**
	 * Handles any secondary drawing of the glyph
	 */
	virtual void draw2(CScreenManager *screenManager);

	/**
	 * Called for mouse button down messages
	 */
	virtual bool MouseButtonDownMsg(const Point &pt);

	/**
	 * Handles mouse button up messages
	 */
	virtual bool MouseButtonUpMsg(const Point &pt);
	
	/**
	 * Returns the tooltip text for when the glyph is selected
	 */
	virtual void getTooltip(CPetText *text);
};

class CEntertainmentDeviceGlyph : public CToggleRemoteGlyph {
public:
	int _field3C;
	CPetGfxElement *_gfxElement2, *_gfxElement3;
public:
	CEntertainmentDeviceGlyph() : CToggleRemoteGlyph(),
		_field3C(0), _gfxElement2(nullptr), _gfxElement3(nullptr) {}

	/**
	 * Setup the glyph
	 */
	virtual bool setup(CPetControl *petControl, CPetGlyphs *owner);

};

} // End of namespace Titanic

#endif /* TITANIC_PET_REMOTE_GLYPHS_H */
