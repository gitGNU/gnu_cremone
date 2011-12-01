/********************************************************************************
 *cremone - A library to easily make GUI for games.								*
 *Copyright (C) 2011 Morel Bérenger												*
 *																				*
 *This file is part of cremone.													*
 *																				*
 *	cremone is free software: you can redistribute it and/or modify				*
 *	it under the terms of the GNU Lesser General Public License as published by	*
 *	the Free Software Foundation, either version 3 of the License, or			*
 *	(at your option) any later version.											*
 *																				*
 *	cremone is distributed in the hope that it will be useful,					*
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of				*
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the				*
 *	GNU Lesser General Public License for more details.							*
 *																				*
 *	You should have received a copy of the GNU Lesser General Public License	*
 *	along with cremone.  If not, see <http://www.gnu.org/licenses/>.			*
 ********************************************************************************/

#include "appwindow.h"
#include <stdexcept>

namespace crem
{
	AppWindow::AppWindow(): TAppWindow<SDL_Surface>()
	{
		if(!SDL_WasInit(SDL_INIT_VIDEO ))
		{
			SDL_InitSubSystem( SDL_INIT_VIDEO );
		    atexit(SDL_Quit);//!< actually this implementation take control of SDL. If the main window is closed, SDL will be quitted.
		}
	}

	AppWindow::~AppWindow()throw()
	{
	}

	void AppWindow::init( const uint16_t _width, const uint16_t _height, const uint8_t _bpp, const uint32_t flags )
	{
		if(!SDL_SetVideoMode(_width, _height, _bpp, flags))
			throw std::runtime_error(SDL_GetError());

		set(SDL_GetVideoSurface());
	}

	void AppWindow::init(void)
	{
		init( m_width, m_height, m_bpp, SDL_HWSURFACE|SDL_DOUBLEBUF );
	}

	void AppWindow::setBestMode(const uint32_t flags)
	{
		SDL_Rect **bestMode=0;

		bestMode=SDL_ListModes(NULL,flags);

		switch((long)(bestMode))
		{
		case 0:
			throw std::runtime_error("Unable to find valid video mode for given parameters");
		case -1:
			init(640, 400, 8, flags);
			return;
		default:
			init(bestMode[0]->w, bestMode[0]->h, SDL_GetVideoInfo()->vfmt->BitsPerPixel, flags);
		}
	}

	void AppWindow::setBestMode(void)
	{
		setBestMode(SDL_HWSURFACE|SDL_DOUBLEBUF );
	}

	void AppWindow::refresh(void)
	{
		if(SDL_Flip(SDL_GetVideoSurface()))
			throw std::runtime_error(SDL_GetError());
	}
}
