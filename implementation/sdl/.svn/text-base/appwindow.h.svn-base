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

#ifndef SDLSCREEN_H
#define SDLSCREEN_H

#include <tappwindow.h>
#include <SDL/SDL.h>

// FIXME (berenger#1#): implement exceptions

namespace crem
{
	class AppWindow : public TCrem::TAppWindow<SDL_Surface>
	{
	public:
	/** \brief Initialize the screen with custom parameters
	 * Look at SDL_SetVideoMode to have informations on this function (the only differences are that there is a verification and a try to initialise video subsystem before if necessary, and that some logs are generated if there are errors)
	 * \param width const uint16_t
	 * \param height const uint16_t
	 * \param bpp const uint8_t bits per pixel
	 * \param flags const uint32_t
	 */
		AppWindow();
		virtual ~AppWindow() throw();
		void init(const uint16_t width, const uint16_t height, const uint8_t bpp,const uint32_t flags);
		void init(void);
		void setBestMode(const uint32_t flags);
		void setBestMode(void);
		void refresh(void );
	protected:
	private:
	};
}
#endif // SDLSCREEN_H
