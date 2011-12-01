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

#ifndef SDL_EVENTMANAGER_H
#define SDL_EVENTMANAGER_H

#include <eventmanager.h>
#include <stdint.h>

#include <SDL/SDL.h>

namespace crem
{
	#define MAXPEEPEVENT 1

	class SDL_EventManager: public TCrem::EventManager
	{
	public:
		SDL_EventManager(void);
		void pollEvent(void);
		void addEventManager(TCrem::Event const &ev, TCrem::CALLBACK const callback, void *window);
	protected:
		static TCrem::EVENT_TYPE sdl2cremone(uint8_t type);
		static TCrem::KEY_NAME sdl2cremone(SDLKey key);
		static TCrem::MOUSE::BUTTON sdl2cremone(SDL_MouseButtonEvent button);
	private:

	public:
	protected:
	private:
		uint32_t m_mask;
	};
}
#endif
