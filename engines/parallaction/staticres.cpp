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
 * $URL$
 * $Id$
 *
 */

#include "common/stdafx.h"

#include "parallaction/parallaction.h"


namespace Parallaction {

byte Gfx::_mouseArrow[256] = {
	0x12, 0x11, 0x11, 0x11, 0x13, 0x12, 0x12, 0x12, 0x13, 0x12, 0x12, 0x11, 0x13, 0x12, 0x12, 0x00,
	0x13, 0x12, 0x12, 0x11, 0x13, 0x12, 0x12, 0x12, 0x13, 0x12, 0x12, 0x12, 0x13, 0x12, 0x12, 0x12,
	0x13, 0x12, 0x12, 0x12, 0x13, 0x12, 0x12, 0x12, 0x13, 0x12, 0x12, 0x13, 0x13, 0x13, 0x12, 0x00,
	0x13, 0x00, 0x12, 0x00, 0x13, 0x00, 0x12, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x11, 0x11, 0x11, 0x11, 0x12, 0x12, 0x12, 0x11, 0x12, 0x12, 0x12, 0x00, 0x12, 0x12, 0x12, 0x00,
	0x12, 0x12, 0x12, 0x00, 0x12, 0x12, 0x12, 0x11, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12,
	0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x13, 0x12, 0x12, 0x12, 0x00, 0x12, 0x12, 0x12, 0x00,
	0x13, 0x13, 0x12, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x11, 0x11, 0x11, 0x11, 0x12, 0x12, 0x12, 0x00, 0x12, 0x12, 0x12, 0x00, 0x12, 0x12, 0x12, 0x00,
	0x12, 0x12, 0x12, 0x00, 0x12, 0x12, 0x12, 0x00, 0x12, 0x12, 0x12, 0x11, 0x12, 0x12, 0x12, 0x12,
	0x12, 0x12, 0x12, 0x13, 0x12, 0x12, 0x12, 0x00, 0x12, 0x12, 0x12, 0x00, 0x13, 0x12, 0x12, 0x00,
	0x00, 0x12, 0x13, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x11, 0x11, 0x11, 0x00, 0x12, 0x12, 0x12, 0x00, 0x12, 0x12, 0x12, 0x00, 0x12, 0x12, 0x11, 0x00,
	0x12, 0x12, 0x12, 0x00, 0x12, 0x12, 0x12, 0x00, 0x12, 0x12, 0x12, 0x00, 0x12, 0x12, 0x12, 0x11,
	0x12, 0x12, 0x12, 0x00, 0x12, 0x12, 0x12, 0x00, 0x13, 0x12, 0x12, 0x00, 0x00, 0x12, 0x13, 0x00,
	0x00, 0x12, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


byte _amigaTopazFont[2600] =
{
  0x00, 0x00, 0x03, 0xf3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x79, 0x00, 0x00, 0x03, 0xe9, 0x00, 0x00, 0x02, 0x79,
  0x70, 0xff, 0x4e, 0x75, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00,
  0x00, 0x1a, 0x0f, 0x80, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46, 0x45, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x1a, 0x00, 0x00, 0x00, 0x00, 0x09, 0x74, 0x00, 0x08,
  0x00, 0x40, 0x00, 0x08, 0x00, 0x06, 0x00, 0x01, 0x00, 0x00, 0x20, 0xff, 0x00, 0x00, 0x00, 0x6e,
  0x00, 0xbe, 0x00, 0x00, 0x06, 0x5e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18,
  0x6c, 0x6c, 0x18, 0x00, 0x38, 0x18, 0x0c, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x3c, 0x18,
  0x3c, 0x3c, 0x1c, 0x7e, 0x1c, 0x7e, 0x3c, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x7c, 0x3c,
  0x7c, 0x1e, 0x78, 0x7e, 0x7e, 0x3c, 0x66, 0x3c, 0x06, 0xc6, 0x60, 0xc6, 0xc6, 0x3c, 0x7c, 0x78,
  0x7c, 0x3c, 0x7e, 0x66, 0x66, 0xc6, 0xc3, 0xc3, 0xfe, 0x3c, 0xc0, 0x3c, 0x10, 0x00, 0x18, 0x00,
  0x60, 0x00, 0x06, 0x00, 0x1c, 0x00, 0x60, 0x18, 0x0c, 0x60, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x18, 0x70, 0x72, 0x0f, 0x00, 0x18,
  0x00, 0x1c, 0x42, 0xc3, 0x18, 0x3c, 0x66, 0x7e, 0x1c, 0x00, 0x3e, 0x7e, 0x7e, 0x3c, 0x18, 0x78,
  0x78, 0x18, 0x00, 0x3e, 0x00, 0x00, 0x30, 0x38, 0x00, 0x40, 0x40, 0xc0, 0x18, 0x3c, 0x3c, 0x7e,
  0x06, 0x66, 0x18, 0x7e, 0x7e, 0x36, 0x0c, 0x0c, 0x18, 0x3c, 0xc6, 0x3c, 0x60, 0x76, 0x18, 0x00,
  0x0c, 0x7e, 0x71, 0x66, 0x00, 0x66, 0x60, 0x0e, 0x7e, 0x66, 0x18, 0x6e, 0x3c, 0x00, 0x18, 0x7e,
  0x06, 0x66, 0x18, 0x00, 0x7e, 0x34, 0x0c, 0x0c, 0x18, 0x0c, 0x60, 0x00, 0x18, 0x3c, 0x0c, 0x00,
  0x0c, 0x00, 0x71, 0x00, 0x00, 0x00, 0x18, 0x0c, 0x7e, 0x00, 0x18, 0x3c, 0x00, 0x18, 0x6c, 0x6c,
  0x3e, 0x66, 0x6c, 0x18, 0x18, 0x18, 0x66, 0x18, 0x00, 0x00, 0x00, 0x06, 0x66, 0x38, 0x66, 0x66,
  0x3c, 0x60, 0x30, 0x06, 0x66, 0x66, 0x18, 0x18, 0x06, 0x00, 0x60, 0x66, 0xc6, 0x66, 0x66, 0x30,
  0x6c, 0x60, 0x60, 0x66, 0x66, 0x18, 0x06, 0xcc, 0x60, 0xee, 0xe6, 0x66, 0x66, 0xcc, 0x66, 0x66,
  0x18, 0x66, 0x66, 0xc6, 0x66, 0x66, 0x0c, 0x30, 0x60, 0x0c, 0x38, 0x00, 0x18, 0x00, 0x60, 0x00,
  0x06, 0x00, 0x30, 0x00, 0x60, 0x00, 0x00, 0x60, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x18, 0x9c, 0x3c, 0x7e, 0x00, 0x0c, 0x36,
  0x3c, 0x66, 0x18, 0x60, 0x66, 0x81, 0x24, 0x33, 0x06, 0x81, 0x00, 0x66, 0x18, 0x0c, 0x0c, 0x30,
  0x00, 0x7a, 0x00, 0x00, 0x70, 0x44, 0xcc, 0xc6, 0xc6, 0x23, 0x00, 0x66, 0x18, 0x00, 0x1c, 0x00,
  0x24, 0x60, 0x00, 0x1c, 0x18, 0x18, 0x00, 0x66, 0xcc, 0x00, 0x60, 0x3c, 0x30, 0xc6, 0x18, 0x00,
  0x8e, 0x00, 0xc6, 0x66, 0x60, 0x38, 0x00, 0x00, 0x00, 0x3c, 0x66, 0x00, 0x00, 0x00, 0x0c, 0x00,
  0x24, 0x00, 0x00, 0x18, 0x18, 0x18, 0x00, 0x18, 0x66, 0x3c, 0x18, 0x18, 0x18, 0x00, 0x18, 0x7e,
  0x8e, 0x66, 0x18, 0x00, 0x18, 0x18, 0x00, 0x66, 0x00, 0x18, 0x00, 0x18, 0x00, 0xfe, 0x60, 0xac,
  0x68, 0x30, 0x30, 0x0c, 0x3c, 0x18, 0x00, 0x00, 0x00, 0x0c, 0x6e, 0x78, 0x06, 0x06, 0x6c, 0x7c,
  0x60, 0x06, 0x66, 0x66, 0x18, 0x18, 0x18, 0x7e, 0x18, 0x06, 0xde, 0x66, 0x66, 0x60, 0x66, 0x60,
  0x60, 0x60, 0x66, 0x18, 0x06, 0xd8, 0x60, 0xfe, 0xf6, 0x66, 0x66, 0xcc, 0x66, 0x70, 0x18, 0x66,
  0x66, 0xc6, 0x3c, 0x3c, 0x18, 0x30, 0x30, 0x0c, 0x6c, 0x00, 0x0c, 0x3c, 0x7c, 0x3c, 0x3e, 0x3c,
  0x7c, 0x3e, 0x7c, 0x18, 0x0c, 0x66, 0x18, 0xec, 0x7c, 0x3c, 0x7c, 0x3e, 0x7c, 0x3c, 0x7c, 0x66,
  0x66, 0xc6, 0xc6, 0x66, 0x7e, 0x18, 0x18, 0x18, 0x00, 0xf0, 0x66, 0x18, 0x3e, 0x30, 0x66, 0x3c,
  0x18, 0x3c, 0x00, 0x9d, 0x44, 0x66, 0x00, 0xb9, 0x00, 0x3c, 0x7e, 0x18, 0x18, 0x60, 0x66, 0x7a,
  0x18, 0x00, 0x30, 0x44, 0x66, 0x4c, 0x4c, 0x66, 0x18, 0x66, 0x18, 0x3c, 0x3c, 0x3c, 0x3c, 0x60,
  0x7e, 0x3c, 0x7e, 0x7e, 0x7e, 0x60, 0xd8, 0x3c, 0x60, 0x66, 0xc6, 0xe6, 0x3c, 0x3c, 0x3c, 0x3c,
  0x6c, 0x66, 0x6c, 0x66, 0x66, 0x66, 0x7e, 0x7e, 0x66, 0x3c, 0x18, 0x3c, 0x18, 0x3c, 0x3c, 0x3c,
  0x3c, 0x18, 0x3c, 0x7e, 0x3c, 0x3e, 0x6c, 0x00, 0x18, 0x3c, 0x00, 0x7c, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x66, 0x1e, 0x3c, 0x66, 0x00, 0x7e, 0x7e, 0x00, 0x18, 0x00, 0x6c, 0x3c, 0xd8, 0x76, 0x00,
  0x30, 0x0c, 0xff, 0x7e, 0x00, 0x7e, 0x00, 0x18, 0x7e, 0x18, 0x0c, 0x1c, 0xcc, 0x06, 0x7c, 0x0c,
  0x3c, 0x3e, 0x00, 0x00, 0x60, 0x00, 0x06, 0x0c, 0xd6, 0x7e, 0x7c, 0x60, 0x66, 0x78, 0x78, 0x6e,
  0x7e, 0x18, 0x06, 0xf0, 0x60, 0xd6, 0xde, 0x66, 0x7c, 0xcc, 0x7c, 0x3c, 0x18, 0x66, 0x66, 0xd6,
  0x18, 0x18, 0x30, 0x30, 0x18, 0x0c, 0xc6, 0x00, 0x00, 0x06, 0x66, 0x60, 0x66, 0x66, 0x30, 0x66,
  0x66, 0x18, 0x0c, 0x6c, 0x18, 0xfe, 0x66, 0x66, 0x66, 0x66, 0x66, 0x60, 0x30, 0x66, 0x66, 0xc6,
  0x6c, 0x66, 0x0c, 0x70, 0x18, 0x0e, 0x00, 0xc3, 0x66, 0x18, 0x6c, 0x78, 0x3c, 0x18, 0x00, 0x66,
  0x00, 0xb1, 0x3c, 0xcc, 0x00, 0xa5, 0x00, 0x00, 0x18, 0x30, 0x0c, 0x00, 0x66, 0x3a, 0x18, 0x00,
  0x30, 0x38, 0x33, 0x58, 0x58, 0x2c, 0x30, 0x7e, 0x18, 0x66, 0x66, 0x66, 0x66, 0x78, 0x60, 0x66,
  0x60, 0x4c, 0x60, 0x6e, 0xf0, 0x18, 0x60, 0x30, 0xe6, 0xf6, 0x66, 0x66, 0x66, 0x66, 0x38, 0x66,
  0x70, 0x30, 0x66, 0x66, 0x4c, 0x4c, 0x6c, 0x06, 0x18, 0x06, 0x3c, 0x06, 0x06, 0x66, 0x66, 0x3c,
  0x66, 0x0c, 0x66, 0x66, 0x78, 0x18, 0x18, 0x60, 0x7c, 0x66, 0x3c, 0x3c, 0x3c, 0x3c, 0x7e, 0x66,
  0x78, 0x60, 0x66, 0x66, 0x0c, 0x0c, 0x00, 0x18, 0x00, 0xfe, 0x06, 0x36, 0xdc, 0x00, 0x30, 0x0c,
  0x3c, 0x18, 0x00, 0x00, 0x00, 0x30, 0x76, 0x18, 0x18, 0x06, 0xfe, 0x06, 0x66, 0x18, 0x66, 0x06,
  0x00, 0x00, 0x18, 0x7e, 0x18, 0x18, 0xde, 0x66, 0x66, 0x60, 0x66, 0x60, 0x60, 0x66, 0x66, 0x18,
  0x06, 0xd8, 0x60, 0xc6, 0xce, 0x66, 0x60, 0xcc, 0x6c, 0x0e, 0x18, 0x66, 0x3c, 0xfe, 0x3c, 0x18,
  0x60, 0x30, 0x0c, 0x0c, 0x00, 0x00, 0x00, 0x3e, 0x66, 0x60, 0x66, 0x7e, 0x30, 0x66, 0x66, 0x18,
  0x0c, 0x78, 0x18, 0xd6, 0x66, 0x66, 0x66, 0x66, 0x60, 0x3c, 0x30, 0x66, 0x66, 0xd6, 0x38, 0x66,
  0x18, 0x18, 0x18, 0x18, 0x00, 0x0f, 0x66, 0x18, 0x3e, 0x30, 0x42, 0x3c, 0x18, 0x3c, 0x00, 0x9d,
  0x00, 0x66, 0x00, 0xb9, 0x00, 0x00, 0x18, 0x7c, 0x78, 0x00, 0x66, 0x0a, 0x00, 0x00, 0x30, 0x00,
  0x66, 0x32, 0x3e, 0xd9, 0x60, 0x66, 0x18, 0x7e, 0x40, 0x7e, 0x7e, 0x60, 0x78, 0x40, 0x78, 0x18,
  0x78, 0x66, 0xd8, 0x18, 0x60, 0x0c, 0xf6, 0xde, 0x66, 0x66, 0x66, 0x66, 0x6c, 0x66, 0xe0, 0x0c,
  0x66, 0x66, 0x18, 0x18, 0x66, 0x3e, 0x18, 0x3e, 0x60, 0x3e, 0x3e, 0x7e, 0x7e, 0x60, 0x7e, 0x18,
  0x7e, 0x66, 0x6c, 0x18, 0x18, 0x3c, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x00, 0x66, 0x18, 0x3c,
  0x66, 0x66, 0x18, 0x18, 0x00, 0x00, 0x00, 0x6c, 0x7c, 0x6a, 0xce, 0x00, 0x18, 0x18, 0x66, 0x18,
  0x18, 0x00, 0x18, 0x60, 0x66, 0x18, 0x30, 0x66, 0x0c, 0x66, 0x66, 0x18, 0x66, 0x0c, 0x18, 0x18,
  0x06, 0x00, 0x60, 0x00, 0xc0, 0x66, 0x66, 0x30, 0x6c, 0x60, 0x60, 0x66, 0x66, 0x18, 0x66, 0xcc,
  0x60, 0xc6, 0xc6, 0x66, 0x60, 0xdc, 0x66, 0x66, 0x18, 0x66, 0x3c, 0xee, 0x66, 0x18, 0xc0, 0x30,
  0x06, 0x0c, 0x00, 0x00, 0x00, 0x66, 0x66, 0x60, 0x66, 0x60, 0x30, 0x3e, 0x66, 0x18, 0x0c, 0x6c,
  0x18, 0xc6, 0x66, 0x66, 0x7c, 0x3e, 0x60, 0x06, 0x30, 0x66, 0x3c, 0xfe, 0x6c, 0x3c, 0x30, 0x18,
  0x18, 0x18, 0x00, 0x3c, 0x66, 0x18, 0x0c, 0x30, 0x00, 0x18, 0x18, 0x06, 0x00, 0x81, 0x7e, 0x33,
  0x00, 0xa5, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x66, 0x0a, 0x00, 0x00, 0x00, 0x7c, 0xcc, 0x66,
  0x62, 0x33, 0x66, 0x66, 0x18, 0x66, 0x66, 0x66, 0x66, 0x60, 0x60, 0x66, 0x60, 0x32, 0x60, 0x3e,
  0xcc, 0x18, 0x7e, 0x66, 0xde, 0xce, 0x66, 0x66, 0x66, 0x66, 0xc6, 0x66, 0x60, 0x66, 0x66, 0x66,
  0x32, 0x32, 0x66, 0x66, 0x18, 0x66, 0x60, 0x66, 0x66, 0x60, 0x60, 0x60, 0x60, 0x30, 0x60, 0x3e,
  0x66, 0x18, 0x18, 0x06, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x18, 0x66, 0x18, 0x06, 0x66, 0x66,
  0x30, 0x30, 0x00, 0x18, 0x00, 0x6c, 0x18, 0xcc, 0x7b, 0x00, 0x0c, 0x30, 0x00, 0x00, 0x18, 0x00,
  0x18, 0xc0, 0x3c, 0x18, 0x7e, 0x3c, 0x0c, 0x3c, 0x3c, 0x18, 0x3c, 0x38, 0x18, 0x18, 0x00, 0x00,
  0x00, 0x18, 0x78, 0x66, 0x7c, 0x1e, 0x78, 0x7e, 0x60, 0x3e, 0x66, 0x3c, 0x3c, 0xc6, 0x7e, 0xc6,
  0xc6, 0x3c, 0x60, 0x7e, 0x66, 0x3c, 0x18, 0x3c, 0x18, 0xc6, 0xc3, 0x18, 0xfe, 0x3c, 0x03, 0x3c,
  0x00, 0x00, 0x00, 0x3e, 0x7c, 0x3c, 0x3e, 0x3c, 0x30, 0x06, 0x66, 0x0c, 0x0c, 0x66, 0x0c, 0xc6,
  0x66, 0x3c, 0x60, 0x06, 0x60, 0x7c, 0x1c, 0x3e, 0x18, 0x6c, 0xc6, 0x18, 0x7e, 0x0e, 0x18, 0x70,
  0x00, 0xf0, 0x7e, 0x18, 0x00, 0x7e, 0x00, 0x18, 0x18, 0x3c, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x81,
  0x00, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x7f, 0x0a, 0x00, 0x18, 0x00, 0x00, 0x00, 0xcf, 0xc4, 0x67,
  0x3c, 0x67, 0x3e, 0x66, 0x3c, 0x66, 0x66, 0x7f, 0x7e, 0x3c, 0x7e, 0x7e, 0x7e, 0x18, 0x30, 0x3c,
  0x18, 0x3c, 0xce, 0x18, 0x3c, 0x3c, 0x3c, 0x3c, 0x00, 0x3f, 0x7e, 0x3c, 0x3c, 0x3c, 0x7e, 0x7e,
  0x6c, 0x3f, 0x1e, 0x3e, 0x3c, 0x3e, 0x3e, 0x3c, 0x3c, 0x3c, 0x3c, 0x7e, 0x3c, 0x06, 0x18, 0x0c,
  0x0c, 0x7c, 0x66, 0x18, 0x3c, 0x3c, 0x3c, 0x3c, 0x00, 0x3f, 0x0c, 0x7c, 0x3e, 0x3e, 0x7e, 0x7e,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x60, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x02, 0x0e, 0x01, 0x00, 0x03,
  0x06, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x60, 0x00, 0x30, 0x00,
  0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x03,
  0x06, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x30, 0x00, 0x18, 0x00,
  0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x08, 0x00, 0x08, 0x00, 0x08, 0x00, 0x10, 0x00, 0x08, 0x00, 0x18, 0x00, 0x08, 0x00, 0x20,
  0x00, 0x08, 0x00, 0x28, 0x00, 0x08, 0x00, 0x30, 0x00, 0x08, 0x00, 0x38, 0x00, 0x08, 0x00, 0x40,
  0x00, 0x08, 0x00, 0x48, 0x00, 0x08, 0x00, 0x50, 0x00, 0x08, 0x00, 0x58, 0x00, 0x08, 0x00, 0x60,
  0x00, 0x08, 0x00, 0x68, 0x00, 0x08, 0x00, 0x70, 0x00, 0x08, 0x00, 0x78, 0x00, 0x08, 0x00, 0x80,
  0x00, 0x08, 0x00, 0x88, 0x00, 0x08, 0x00, 0x90, 0x00, 0x08, 0x00, 0x98, 0x00, 0x08, 0x00, 0xa0,
  0x00, 0x08, 0x00, 0xa8, 0x00, 0x08, 0x00, 0xb0, 0x00, 0x08, 0x00, 0xb8, 0x00, 0x08, 0x00, 0xc0,
  0x00, 0x08, 0x00, 0xc8, 0x00, 0x08, 0x00, 0xd0, 0x00, 0x08, 0x00, 0xd8, 0x00, 0x08, 0x00, 0xe0,
  0x00, 0x08, 0x00, 0xe8, 0x00, 0x08, 0x00, 0xf0, 0x00, 0x08, 0x00, 0xf8, 0x00, 0x08, 0x01, 0x00,
  0x00, 0x08, 0x01, 0x08, 0x00, 0x08, 0x01, 0x10, 0x00, 0x08, 0x01, 0x18, 0x00, 0x08, 0x01, 0x20,
  0x00, 0x08, 0x01, 0x28, 0x00, 0x08, 0x01, 0x30, 0x00, 0x08, 0x01, 0x38, 0x00, 0x08, 0x01, 0x40,
  0x00, 0x08, 0x01, 0x48, 0x00, 0x08, 0x01, 0x50, 0x00, 0x08, 0x01, 0x58, 0x00, 0x08, 0x01, 0x60,
  0x00, 0x08, 0x01, 0x68, 0x00, 0x08, 0x01, 0x70, 0x00, 0x08, 0x01, 0x78, 0x00, 0x08, 0x01, 0x80,
  0x00, 0x08, 0x01, 0x88, 0x00, 0x08, 0x01, 0x90, 0x00, 0x08, 0x01, 0x98, 0x00, 0x08, 0x01, 0xa0,
  0x00, 0x08, 0x01, 0xa8, 0x00, 0x08, 0x01, 0xb0, 0x00, 0x08, 0x01, 0xb8, 0x00, 0x08, 0x01, 0xc0,
  0x00, 0x08, 0x01, 0xc8, 0x00, 0x08, 0x01, 0xd0, 0x00, 0x08, 0x01, 0xd8, 0x00, 0x08, 0x01, 0xe0,
  0x00, 0x08, 0x01, 0xe8, 0x00, 0x08, 0x01, 0xf0, 0x00, 0x08, 0x01, 0xf8, 0x00, 0x08, 0x02, 0x00,
  0x00, 0x08, 0x02, 0x08, 0x00, 0x08, 0x02, 0x10, 0x00, 0x08, 0x02, 0x18, 0x00, 0x08, 0x02, 0x20,
  0x00, 0x08, 0x02, 0x28, 0x00, 0x08, 0x02, 0x30, 0x00, 0x08, 0x02, 0x38, 0x00, 0x08, 0x02, 0x40,
  0x00, 0x08, 0x02, 0x48, 0x00, 0x08, 0x02, 0x50, 0x00, 0x08, 0x02, 0x58, 0x00, 0x08, 0x02, 0x60,
  0x00, 0x08, 0x02, 0x68, 0x00, 0x08, 0x02, 0x70, 0x00, 0x08, 0x02, 0x78, 0x00, 0x08, 0x02, 0x80,
  0x00, 0x08, 0x02, 0x88, 0x00, 0x08, 0x02, 0x90, 0x00, 0x08, 0x02, 0x98, 0x00, 0x08, 0x02, 0xa0,
  0x00, 0x08, 0x02, 0xa8, 0x00, 0x08, 0x02, 0xb0, 0x00, 0x08, 0x02, 0xb8, 0x00, 0x08, 0x02, 0xc0,
  0x00, 0x08, 0x02, 0xc8, 0x00, 0x08, 0x02, 0xd0, 0x00, 0x08, 0x02, 0xd8, 0x00, 0x08, 0x02, 0xe0,
  0x00, 0x08, 0x02, 0xe8, 0x00, 0x08, 0x02, 0xf0, 0x00, 0x08, 0x02, 0xf8, 0x00, 0x08, 0x03, 0x00,
  0x00, 0x08, 0x03, 0x00, 0x00, 0x08, 0x03, 0x00, 0x00, 0x08, 0x03, 0x00, 0x00, 0x08, 0x03, 0x00,
  0x00, 0x08, 0x03, 0x00, 0x00, 0x08, 0x03, 0x00, 0x00, 0x08, 0x03, 0x00, 0x00, 0x08, 0x03, 0x00,
  0x00, 0x08, 0x03, 0x00, 0x00, 0x08, 0x03, 0x00, 0x00, 0x08, 0x03, 0x00, 0x00, 0x08, 0x03, 0x00,
  0x00, 0x08, 0x03, 0x00, 0x00, 0x08, 0x03, 0x00, 0x00, 0x08, 0x03, 0x00, 0x00, 0x08, 0x03, 0x00,
  0x00, 0x08, 0x03, 0x00, 0x00, 0x08, 0x03, 0x00, 0x00, 0x08, 0x03, 0x00, 0x00, 0x08, 0x03, 0x00,
  0x00, 0x08, 0x03, 0x00, 0x00, 0x08, 0x03, 0x00, 0x00, 0x08, 0x03, 0x00, 0x00, 0x08, 0x03, 0x00,
  0x00, 0x08, 0x03, 0x00, 0x00, 0x08, 0x03, 0x00, 0x00, 0x08, 0x03, 0x00, 0x00, 0x08, 0x03, 0x00,
  0x00, 0x08, 0x03, 0x00, 0x00, 0x08, 0x03, 0x00, 0x00, 0x08, 0x03, 0x00, 0x00, 0x08, 0x00, 0x00,
  0x00, 0x08, 0x03, 0x08, 0x00, 0x08, 0x03, 0x10, 0x00, 0x08, 0x03, 0x18, 0x00, 0x08, 0x03, 0x20,
  0x00, 0x08, 0x03, 0x28, 0x00, 0x08, 0x03, 0x30, 0x00, 0x08, 0x03, 0x38, 0x00, 0x08, 0x03, 0x40,
  0x00, 0x08, 0x03, 0x48, 0x00, 0x08, 0x03, 0x50, 0x00, 0x08, 0x03, 0x58, 0x00, 0x08, 0x03, 0x60,
  0x00, 0x08, 0x00, 0x68, 0x00, 0x08, 0x03, 0x68, 0x00, 0x08, 0x03, 0x70, 0x00, 0x08, 0x03, 0x78,
  0x00, 0x08, 0x03, 0x80, 0x00, 0x08, 0x03, 0x88, 0x00, 0x08, 0x03, 0x90, 0x00, 0x08, 0x03, 0x98,
  0x00, 0x08, 0x03, 0xa0, 0x00, 0x08, 0x03, 0xa8, 0x00, 0x08, 0x03, 0xb0, 0x00, 0x08, 0x03, 0xb8,
  0x00, 0x08, 0x03, 0xc0, 0x00, 0x08, 0x03, 0xc8, 0x00, 0x08, 0x03, 0xd0, 0x00, 0x08, 0x03, 0xd8,
  0x00, 0x08, 0x03, 0xe0, 0x00, 0x08, 0x03, 0xe8, 0x00, 0x08, 0x03, 0xf0, 0x00, 0x08, 0x03, 0xf8,
  0x00, 0x08, 0x04, 0x00, 0x00, 0x08, 0x04, 0x08, 0x00, 0x08, 0x04, 0x10, 0x00, 0x08, 0x04, 0x18,
  0x00, 0x08, 0x04, 0x20, 0x00, 0x08, 0x04, 0x28, 0x00, 0x08, 0x04, 0x30, 0x00, 0x08, 0x04, 0x38,
  0x00, 0x08, 0x04, 0x40, 0x00, 0x08, 0x04, 0x48, 0x00, 0x08, 0x04, 0x50, 0x00, 0x08, 0x04, 0x58,
  0x00, 0x08, 0x04, 0x60, 0x00, 0x08, 0x04, 0x68, 0x00, 0x08, 0x04, 0x70, 0x00, 0x08, 0x04, 0x78,
  0x00, 0x08, 0x04, 0x80, 0x00, 0x08, 0x04, 0x88, 0x00, 0x08, 0x04, 0x90, 0x00, 0x08, 0x04, 0x98,
  0x00, 0x08, 0x04, 0xa0, 0x00, 0x08, 0x04, 0xa8, 0x00, 0x08, 0x04, 0xb0, 0x00, 0x08, 0x04, 0xb8,
  0x00, 0x08, 0x04, 0xc0, 0x00, 0x08, 0x04, 0xc8, 0x00, 0x08, 0x04, 0xd0, 0x00, 0x08, 0x04, 0xd8,
  0x00, 0x08, 0x04, 0xe0, 0x00, 0x08, 0x04, 0xe8, 0x00, 0x08, 0x04, 0xf0, 0x00, 0x08, 0x04, 0xf8,
  0x00, 0x08, 0x05, 0x00, 0x00, 0x08, 0x05, 0x08, 0x00, 0x08, 0x05, 0x10, 0x00, 0x08, 0x05, 0x18,
  0x00, 0x08, 0x05, 0x20, 0x00, 0x08, 0x05, 0x28, 0x00, 0x08, 0x05, 0x30, 0x00, 0x08, 0x05, 0x38,
  0x00, 0x08, 0x05, 0x40, 0x00, 0x08, 0x05, 0x48, 0x00, 0x08, 0x05, 0x50, 0x00, 0x08, 0x05, 0x58,
  0x00, 0x08, 0x05, 0x60, 0x00, 0x08, 0x05, 0x68, 0x00, 0x08, 0x05, 0x70, 0x00, 0x08, 0x05, 0x78,
  0x00, 0x08, 0x05, 0x80, 0x00, 0x08, 0x05, 0x88, 0x00, 0x08, 0x05, 0x90, 0x00, 0x08, 0x05, 0x98,
  0x00, 0x08, 0x05, 0xa0, 0x00, 0x08, 0x05, 0xa8, 0x00, 0x08, 0x05, 0xb0, 0x00, 0x08, 0x05, 0xb8,
  0x00, 0x08, 0x05, 0xc0, 0x00, 0x08, 0x05, 0xc8, 0x00, 0x08, 0x05, 0xd0, 0x00, 0x08, 0x05, 0xd8,
  0x00, 0x08, 0x05, 0xe0, 0x00, 0x08, 0x05, 0xe8, 0x00, 0x08, 0x00, 0x38, 0x00, 0x08, 0x03, 0x00,
  0x00, 0x08, 0x03, 0x00, 0x00, 0x00, 0x03, 0xec, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x44, 0x00, 0x00, 0x00, 0x5c, 0x00, 0x00, 0x00, 0x62,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xf2
};



const char *_zoneFlagNamesRes_ns[] = {
	"closed",
	"active",
	"remove",
	"acting",
	"locked",
	"fixed",
	"noname",
	"nomasked",
	"looping",
	"added",
	"character",
	"nowalk"
};

const char *_zoneTypeNamesRes_ns[] = {
	"examine",
	"door",
	"get",
	"merge",
	"taste",
	"hear",
	"feel",
	"speak",
	"none",
	"trap",
	"yourself",
	"Command"
};

const char _gameNames[10][20] = {
	"GAME1",
	"GAME2",
	"GAME3",
	"GAME4",
	"GAME5",
	"GAME6",
	"GAME7",
	"GAME8",
	"GAME9",
	"GAME10"
};

const char *_commandsNamesRes_ns[] = {
	"set",
	"clear",
	"start",
	"speak",
	"get",
	"location",
	"open",
	"close",
	"on",
	"off",
	"call",
	"toggle",
	"drop",
	"quit",
	"move",
	"stop"
};

const char *_instructionNamesRes_ns[] = {
	"on",
	"off",
	"x",
	"y",
	"z",
	"f",
	"loop",
	"endloop",
	"show",
	"inc",
	"dec",
	"set",
	"put",
	"call",
	"wait",
	"start",
	"sound",
	"move"
};

const char *_callableNamesRes_ns[] = {
	"Projector",
	"HBOff",
	"StartIntro",
	"EndIntro",
	"MoveSheet",
	"Sketch",
	"Shade",
	"Score",
	"OffSound",
	"StartMusic",
	"CloseMusic",
	"Fade",
	"HBOn",
	"MoveSarc",
	"ContaFoglie",
	"ZeroFoglie",
	"Trasformata",
	"OffMouse",
	"OnMouse",
	"SetMask",
	"EndComment",
	"Frankenstain",
	"Finito",
	"Ridux",
	"TestResult"
};

const char *_zoneTypeNamesRes_br[] = {
	"examine",
	"door",
	"get",
	"merge",
	"taste",
	"hear",
	"feel",
	"speak",
	"none",
	"trap",
	"you",
	"command",
	"path",
	"box"
};

const char *_zoneFlagNamesRes_br[] = {
	"closed",
	"active",
	"remove",
	"acting",
	"locked",
	"fixed",
	"noname",
	"nomasked",
	"looping",
	"added",
	"character",
	"nowalk",
	"yourself",
	"scaled",
	"selfuse"
};

const char *_instructionNamesRes_br[] = {
	"on",
	"off",
	"x",
	"y",
	"z",
	"f",
	"loop",
	"endloop",
	"show",
	"inc",
	"dec",
	"set",
	"put",
	"call",
	"wait",
	"start",
	"process",
	"move",
	"color",
	"sound",
	"mask",
	"print",
	"text",
	"mul",
	"div",
	"if",
	"ifeq",
	"iflt",
	"ifgt",
	"endif",
	"stop"
};

const char *_commandsNamesRes_br[] = {
	"set",
	"clear",
	"start",
	"speak",
	"get"
	"location",
	"open",
	"close",
	"on",
	"off",
	"call",
	"toggle",
	"drop",
	"quit",
	"move",
	"stop",
	"character",
	"followme",
	"onmouse",
	"offmouse",
	"add",
	"leave",
	"inc",
	"dec",
	"text",
	"dummy",
	"dummy",
	"let",
	"music",
	"fix",
	"unfix",
	"zeta",
	"scroll",
	"swap",
	"give",
	"text",
	"part",
	"dummy",
	"return",
	"onsave",
	"offsave"
};

const char *_callableNamesRes_br[] = {
	"blufade",
	"resetpalette",
	"ferrcycle",
	"lipsinc",
	"albycle",
	"password"
};

const char *_audioCommandsNamesRes_br[] = {
	"play",
	"stop",
	"pause",
	"channel_level",
	"fadein",
	"fadeout",
	"volume",
	" ",
	"faderate",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	"loop"
};

typedef void (*callable)(void*);


void _c_play_boogie(void*);
void _c_startIntro(void*);
void _c_endIntro(void*);
void _c_moveSheet(void*);
void _c_sketch(void*);
void _c_shade(void*);
void _c_score(void*);
void _c_fade(void*);
void _c_moveSarc(void*);
void _c_contaFoglie(void*);
void _c_zeroFoglie(void*);
void _c_trasformata(void*);
void _c_offMouse(void*);
void _c_onMouse(void*);
void _c_setMask(void*);
void _c_endComment(void*);
void _c_frankenstein(void*);
void _c_finito(void*);
void _c_ridux(void*);
void _c_testResult(void*);
void _c_null(void*);

void _c_projector(void*);
void _c_HBOff(void*);
void _c_offSound(void*);
void _c_startMusic(void*);
void _c_closeMusic(void*);
void _c_HBOn(void*);

callable _callables[25];

const char *_dinoName = "dino";
const char *_donnaName = "donna";
const char *_doughName = "dough";
const char *_drkiName = "drki";

const char *_minidinoName = "minidino";
const char *_minidonnaName = "minidonna";
const char *_minidoughName = "minidough";
const char *_minidrkiName = "minidrki";


void Parallaction_ns::initResources() {

	_zoneFlagNamesRes = _zoneFlagNamesRes_ns;
	_zoneTypeNamesRes = _zoneTypeNamesRes_ns;
	_commandsNamesRes = _commandsNamesRes_ns;
	_callableNamesRes = _callableNamesRes_ns;
	_instructionNamesRes = _instructionNamesRes_ns;

	_callableNames = new Table(ARRAYSIZE(_callableNamesRes_ns), _callableNamesRes_ns);
	_instructionNames = new Table(ARRAYSIZE(_instructionNamesRes_ns), _instructionNamesRes_ns);
	_zoneFlagNames = new Table(ARRAYSIZE(_zoneFlagNamesRes_ns), _zoneFlagNamesRes_ns);
	_zoneTypeNames = new Table(ARRAYSIZE(_zoneTypeNamesRes_ns), _zoneTypeNamesRes_ns);
	_commandsNames = new Table(ARRAYSIZE(_commandsNamesRes_ns), _commandsNamesRes_ns);

	_localFlagNames = new Table(120);
	_localFlagNames->addData("visited");

	if (getPlatform() == Common::kPlatformPC) {
		_callables[0] = 	_c_play_boogie;
		_callables[1] = 	_c_play_boogie;
		_callables[2] = 	_c_startIntro;
		_callables[3] = 	_c_endIntro;
		_callables[4] = 	_c_moveSheet;
		_callables[5] = 	_c_sketch;
		_callables[6] = 	_c_shade;
		_callables[7] = 	_c_score;
		_callables[8] = 	_c_null;
		_callables[9] = 	_c_null;
		_callables[10] = 	_c_null;
		_callables[11] = 	_c_fade;
		_callables[12] = 	_c_play_boogie;
		_callables[13] = 	_c_moveSarc;
		_callables[14] = 	_c_contaFoglie;
		_callables[15] = 	_c_zeroFoglie;
		_callables[16] = 	_c_trasformata;
		_callables[17] = 	_c_offMouse;
		_callables[18] = 	_c_onMouse;
		_callables[19] = 	_c_setMask;
		_callables[20] = 	_c_endComment;
		_callables[21] = 	_c_frankenstein;
		_callables[22] = 	_c_finito;
		_callables[23] = 	_c_ridux;
		_callables[24] = 	_c_testResult;
	} else {
		_callables[0] = 	_c_projector;
		_callables[1] = 	_c_HBOff;
		_callables[2] = 	_c_startIntro;
		_callables[3] = 	_c_endIntro;
		_callables[4] = 	_c_moveSheet;
		_callables[5] = 	_c_sketch;
		_callables[6] = 	_c_shade;
		_callables[7] = 	_c_score;
		_callables[8] = 	_c_offSound;
		_callables[9] = 	_c_startMusic;
		_callables[10] = 	_c_closeMusic;
		_callables[11] = 	_c_fade;
		_callables[12] = 	_c_HBOn;
		_callables[13] = 	_c_moveSarc;
		_callables[14] = 	_c_contaFoglie;
		_callables[15] = 	_c_zeroFoglie;
		_callables[16] = 	_c_trasformata;
		_callables[17] = 	_c_offMouse;
		_callables[18] = 	_c_onMouse;
		_callables[19] = 	_c_setMask;
		_callables[20] = 	_c_endComment;
		_callables[21] = 	_c_frankenstein;
		_callables[22] = 	_c_finito;
		_callables[23] = 	_c_ridux;
		_callables[24] = 	_c_testResult;
	}

}

void Parallaction_br::initResources() {

	_zoneFlagNamesRes = _zoneFlagNamesRes_br;
	_zoneTypeNamesRes = _zoneTypeNamesRes_br;
	_commandsNamesRes = _commandsNamesRes_br;
	_callableNamesRes = _callableNamesRes_br;
	_instructionNamesRes = _instructionNamesRes_br;
	_audioCommandsNamesRes = _audioCommandsNamesRes_br;

	_callableNames = new Table(ARRAYSIZE(_callableNamesRes_br), _callableNamesRes_br);
	_instructionNames = new Table(ARRAYSIZE(_instructionNamesRes_br), _instructionNamesRes_br);
	_zoneFlagNames = new Table(ARRAYSIZE(_zoneFlagNamesRes_br), _zoneFlagNamesRes_br);
	_zoneTypeNames = new Table(ARRAYSIZE(_zoneTypeNamesRes_br), _zoneTypeNamesRes_br);
	_commandsNames = new Table(ARRAYSIZE(_commandsNamesRes_br), _commandsNamesRes_br);
	_audioCommandsNames = new Table(ARRAYSIZE(_audioCommandsNamesRes_br), _audioCommandsNamesRes_br);

	// TODO: make sure there are 120 max locations in Big Red Adventure
	_localFlagNames = new Table(120);
	_localFlagNames->addData("visited");

	// TODO: init callables for Big Red Adventure

}

} // namespace Parallaction
