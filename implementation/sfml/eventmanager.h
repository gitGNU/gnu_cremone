#ifndef HEADER_EAC06684191DBB86
#define HEADER_EAC06684191DBB86

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

#ifndef sfml_EVENTMANAGER_H
#define sfml_EVENTMANAGER_H

#include <eventmanager.h>
#include <stdint.h>

#include <SFML/Window.hpp>

#define MAXPEEPEVENT 1

class sfml_EventManager: public eventManager
{
public:
	sfml_EventManager(void);
	void pollEvent(void);
	void addEventManager(event const &ev, CALLBACK const callback, void *window);
protected:
	EVENT_TYPE sdl2cremoneEVENT_TYPE(uint8_t type);
	KEY_NAME sfml_cast_KEY(SDLKey key)const;
	MOUSE::BUTTON sfml_cast_BUTTON(SDLKey key)const;
private:

public:
protected:
private:
	uint32_t m_mask;
};

#endif

#endif // header guard
