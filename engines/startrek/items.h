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

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef STARTREK_ITEMS_H
#define STARTREK_ITEMS_H

namespace StarTrek {

struct Item {
	bool have;
	int16 field2;
	char name[10];
	int16 index;
};

// This is copied to StarTrekEngine::_itemList when the engine initializes.
// (TODO: it's possible that only the "have" variable ever changes, in which case the
// whole thing doesn't need to be copied.)
const Item g_itemList[] = {
	{  true,   0x40,  "iphasers",  0x00  },
	{  true,   0x41,  "iphaserk",  0x01  },
	{  false,  0x42,  "ihand",     0x02  },
	{  false,  0x43,  "irock",     0x03  },
	{  true,   0x44,  "istricor",  0x04  },
	{  true,   0x45,  "imtricor",  0x05  },
	{  false,  0x46,  "ideadguy",  0x06  },
	{  true,   0x47,  "icomm",     0x07  },
	{  false,  0x48,  "ipbc",      0x08  },
	{  false,  0x49,  "iRLG",      0x09  },
	{  false,  0x4A,  "iWrench",   0x0A  },
	{  false,  0x4B,  "iInsulat",  0x0B  },
	{  false,  0x4C,  "iSample",   0x0C  },
	{  false,  0x4D,  "iCure",     0x0D  },
	{  false,  0x4E,  "iDishes",   0x0E  },
	{  false,  0x4F,  "iRT",       0x0F  },
	{  false,  0x50,  "iRTWB",     0x10  },
	{  false,  0x51,  "iCombBit",  0x11  },
	{  false,  0x52,  "iJnkmetl",  0x12  },
	{  false,  0x53,  "iWiring",   0x13  },
	{  false,  0x54,  "iWirscrp",  0x14  },
	{  false,  0x55,  "iPWF",      0x15  },
	{  false,  0x56,  "iPWE",      0x16  },
	{  false,  0x57,  "iDeadPh",   0x17  },
	{  false,  0x58,  "iBomb",     0x18  },
	{  false,  0x59,  "iMetal",    0x19  },
	{  false,  0x5A,  "iSkull",    0x1A  },
	{  false,  0x5B,  "iMineral",  0x1B  },
	{  false,  0x5C,  "iMeteor",   0x1C  },
	{  false,  0x5D,  "iShells",   0x1D  },
	{  false,  0x5E,  "iDeGrime",  0x1E  },
	{  false,  0x5F,  "iLenses",   0x1F  },
	{  false,  0x60,  "iDisks",    0x20  },
	{  false,  0x61,  "iAntigra",  0x21  },
	{  false,  0x62,  "iN2gas",    0x22  },
	{  false,  0x63,  "iO2gas",    0x23  },
	{  false,  0x64,  "iH2gas",    0x24  },
	{  false,  0x65,  "iN2O",      0x25  },
	{  false,  0x66,  "iNH3",      0x26  },
	{  false,  0x67,  "iH2O",      0x27  },
	{  false,  0x68,  "iWRod",     0x28  },
	{  false,  0x69,  "iIRod",     0x29  },
	{  false,  0x6A,  "iRedGem",   0x2A  },
	{  false,  0x6B,  "iRedGem",   0x2B  },
	{  false,  0x6C,  "iRedGem",   0x2C  },
	{  false,  0x6D,  "iGrnGem",   0x2D  },
	{  false,  0x6E,  "iGrnGem",   0x2E  },
	{  false,  0x6F,  "iGrnGem",   0x2F  },
	{  false,  0x70,  "iBluGem",   0x30  },
	{  false,  0x71,  "iBluGem",   0x31  },
	{  false,  0x72,  "iBluGem",   0x32  },
	{  false,  0x73,  "iConect",   0x33  },
	{  false,  0x74,  "iS8Rocks",  0x34  },
	{  false,  0x75,  "iIDCard",   0x35  },
	{  false,  0x76,  "iSnake",    0x36  },
	{  false,  0x77,  "iFern",     0x37  },
	{  false,  0x78,  "iCrystal",  0x38  },
	{  false,  0x79,  "iKnife",    0x39  },
	{  false,  0x7A,  "idetoxin",  0x3A  },
	{  false,  0x7B,  "iberry",    0x3B  },
	{  false,  0x7C,  "idoover",   0x3C  },
	{  false,  0x7D,  "ialiendv",  0x3D  },
	{  false,  0x7E,  "icapsule",  0x3E  },
	{  true,   0x7F,  "imedkit",   0x3F  },
	{  false,  0x80,  "iBeam",     0x40  },
	{  false,  0x81,  "iDrill",    0x41  },
	{  false,  0x82,  "iHypo",     0x42  },
	{  false,  0x83,  "iFusion",   0x43  },
	{  false,  0x84,  "iCable1",   0x44  },
	{  false,  0x85,  "iCable2",   0x45  },
	{  false,  0x86,  "iLMD",      0x46  },
	{  false,  0x87,  "iDeck",     0x47  },
	{  false,  0x88,  "iTech",     0x48  },

	// 64 blank rows?
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
	{  false,  0x00,  "",          0x00  },
};

const int NUM_ITEMS = sizeof(g_itemList) / sizeof(struct Item);

}

#endif
