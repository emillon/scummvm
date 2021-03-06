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

#ifndef BACKENDS_GRAPHICS_SDL_DISPMANX_H
#define BACKENDS_GRAPHICS_SDL_DISPMANX_H

#include "backends/graphics/surfacesdl/surfacesdl-graphics.h"

struct dispvarsStruct;
struct dispmanxPage;

class DispmanXSdlGraphicsManager : public SurfaceSdlGraphicsManager {
public:
	DispmanXSdlGraphicsManager(SdlEventSource *sdlEventSource, SdlWindow *window);
	~DispmanXSdlGraphicsManager();
	bool loadGFXMode();
	void internUpdateScreen();
	bool handleScalerHotkeys(Common::KeyCode key);
	void setFullscreenMode(bool enable);
	void setAspectRatioCorrection(bool enable);
	void clearOverlay();
	bool hasFeature(OSystem::Feature f);
protected:
	// Raspberry Pi Dispmanx API
	void dispmanXSetup(int width, int height);
	void dispmanXInit();
	void dispmanXUpdate();
	dispmanxPage *dispmanXGetFreePage();
	void dispmanXFreeResources();
	void dispmanXVideoQuit();
	dispvarsStruct *_dispvars;
};

#endif /* BACKENDS_GRAPHICS_SDL_DISPMANX_H */
