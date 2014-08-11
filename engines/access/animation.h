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

#ifndef ACCESS_ANIMATION_H
#define ACCESS_ANIMATION_H

#include "common/scummsys.h"
#include "common/array.h"
#include "common/memstream.h"
#include "access/data.h"

namespace Access {

class AnimationResource;
class Animation;
class AnimationFrame;
class AnimationFramePart;

class AnimationManager : public Manager {
public:
	Common::Array<Animation *> _animationTimers;
	AnimationResource *_animation;
	Animation *_animStart;
public:
	AnimationManager(AccessEngine *vm);
	~AnimationManager();
	void freeAnimationData();
	void loadAnimations(const byte *data, int size);
	
	void clearTimers();

	Animation *findAnimation(int animId);
	Animation *setAnimation(int animId);

	void setAnimTimer(Animation *anim);

	void animate(int animId);
};

class AnimationResource {
private:
	Common::Array<Animation *> _animations;
public:
	AnimationResource(const byte *data, int size);
	~AnimationResource();

	int getCount() { return _animations.size(); }
	Animation *getAnimation(int idx) { return _animations[idx]; }
};

class Animation {
private:
	Common::Array<AnimationFrame *> _frames;
public:
	int _type;
	int _scaling;
	int _frameNumber;
	int _initialTicks;
	int _loopCount;
	int _countdownTicks;
	int _currentLoopCount;
	int _field10;
public:
	Animation(Common::MemoryReadStream &stream);
	~Animation();

	void animate();
};

class AnimationFrame {
public:
	int _baseX, _baseY;
	int _frameDelay;
	Common::Array<AnimationFramePart *> _parts;
public:
	AnimationFrame(Common::MemoryReadStream &stream, int startOffset);
	~AnimationFrame();
};

class AnimationFramePart {
public:
	byte _flags;
	int _slotIndex;
	int _spriteIndex;
	Common::Point _position;
	int _priority;
public:
	AnimationFramePart(Common::MemoryReadStream &stream);
};

} // End of namespace Access

#endif /* ACCESS_ANIMATION_H */
