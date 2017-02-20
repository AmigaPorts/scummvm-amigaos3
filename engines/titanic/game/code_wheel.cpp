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

#include "titanic/game/code_wheel.h"
#include "titanic/titanic.h"

namespace Titanic {

BEGIN_MESSAGE_MAP(CodeWheel, CBomb)
	ON_MESSAGE(MouseButtonDownMsg)
	ON_MESSAGE(EnterViewMsg)
	ON_MESSAGE(MouseButtonUpMsg)
	ON_MESSAGE(MovieEndMsg)
END_MESSAGE_MAP()

CodeWheel::CodeWheel() : CBomb(), _correctValue(0), _value(4),
		_isCorrect(0), _field114(0), _field118(0) {
}

void CodeWheel::save(SimpleFile *file, int indent) {
	file->writeNumberLine(1, indent);
	file->writeNumberLine(_correctValue, indent);
	file->writeNumberLine(_value, indent);
	file->writeNumberLine(_isCorrect, indent);
	if (g_vm->isGerman()) {
		file->writeNumberLine(_field114, indent);
		file->writeNumberLine(_field118, indent);
	}

	CBomb::save(file, indent);
}

void CodeWheel::load(SimpleFile *file) {
	file->readNumber();
	_correctValue = file->readNumber();
	_value = file->readNumber();
	_isCorrect = file->readNumber();
	if (g_vm->isGerman()) {
		_field114 = file->readNumber();
		_field118 = file->readNumber();
	}

	CBomb::load(file);
}

bool CodeWheel::MouseButtonDownMsg(CMouseButtonDownMsg *msg) {
	static const int START_FRAMES[15] = {
		0, 5, 10, 15, 19, 24, 28, 33, 38, 42, 47, 52, 57, 61, 66
	};
	static const int END_FRAMES[15] = {
		5, 10, 15, 19, 24, 28, 33, 38, 42, 47, 52, 57, 61, 66, 70
	};

	int yp = _bounds.top + _bounds.height() / 2;
	_isCorrect = false;

	if (msg->_mousePos.y > yp) {
		if (_value == _correctValue)
			_isCorrect = true;

		_value = (_value + 1) % 15;
		playMovie(START_FRAMES[_value], END_FRAMES[_value],
			MOVIE_WAIT_FOR_FINISH | MOVIE_NOTIFY_OBJECT);
	} else {
		if (_value == _correctValue)
			_isCorrect = true;

		playMovie(START_FRAMES[14 - _value] + 68, END_FRAMES[14 - _value] + 68,
			MOVIE_WAIT_FOR_FINISH | MOVIE_NOTIFY_OBJECT);

		_value = (_value <= 0) ? 14 : _value - 1;
	}

	playSound("z#59.wav");
	return true;
}

bool CodeWheel::EnterViewMsg(CEnterViewMsg *msg) {
	loadFrame(24);
	_value = 4;
	return true;
}

bool CodeWheel::MouseButtonUpMsg(CMouseButtonUpMsg *msg) {
	return true;
}

bool CodeWheel::MovieEndMsg(CMovieEndMsg *msg) {
	sleep(200);
	CStatusChangeMsg changeMsg;
	changeMsg._newStatus = 0;
	if (_isCorrect)
		changeMsg._newStatus = -1;
	if (_value == _correctValue)
		changeMsg._newStatus = 1;
	changeMsg.execute("Bomb");

	return true;
}

} // End of namespace Titanic
