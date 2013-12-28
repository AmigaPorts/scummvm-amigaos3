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

#include "fullpipe/fullpipe.h"

#include "fullpipe/objectnames.h"
#include "fullpipe/constants.h"

#include "fullpipe/gameloader.h"
#include "fullpipe/motion.h"
#include "fullpipe/scenes.h"
#include "fullpipe/statics.h"

#include "fullpipe/interaction.h"
#include "fullpipe/behavior.h"


namespace Fullpipe {

void scene24_initScene(Scene *sc) {
	g_vars->scene24_var01 = 200;
	g_vars->scene24_var02 = 200;
	g_vars->scene24_var03 = 300;
	g_vars->scene24_var04 = 300;

	g_vars->scene24_water = sc->getStaticANIObject1ById(ANI_WATER24, -1);
	g_vars->scene24_jet = sc->getStaticANIObject1ById(ANI_JET24, -1);
	g_vars->scene24_drop = sc->getStaticANIObject1ById(ANI_DROP_24, -1);

	g_vars->scene24_water->setAlpha(0xa0);
	g_vars->scene24_jet->setAlpha(0xa0);
	g_vars->scene24_drop->setAlpha(0xa0);

	Scene *oldsc = g_fp->_currentScene;
	g_fp->_currentScene = sc;

	if (g_fp->getObjectState(sO_Pool) == g_fp->getObjectEnumState(sO_Pool, sO_Overfull)) {
		g_vars->scene24_var05 = 1;
		g_vars->scene24_var06 = 0;
	} else {
		g_vars->scene24_jet->hide();

		g_vars->scene24_var05 = 0;

		g_vars->scene24_water->changeStatics2(ST_WTR24_FLOWLOWER);

		g_vars->scene24_var06 = 1;
	}

	if (g_fp->getObjectState(sO_Pool) < g_fp->getObjectEnumState(sO_Pool, sO_Full)) {
		g_vars->scene24_var07 = 0;

		g_vars->scene24_water->hide();

		g_fp->setObjectState(sO_StairsDown_24, g_fp->getObjectEnumState(sO_StairsDown_24, sO_IsOpened));
	} else {
		g_vars->scene24_var07 = 1;

		g_fp->setObjectState(sO_StairsDown_24, g_fp->getObjectEnumState(sO_StairsDown_24, sO_IsClosed));
	}

	g_fp->_currentScene = oldsc;
}

} // End of namespace Fullpipe
