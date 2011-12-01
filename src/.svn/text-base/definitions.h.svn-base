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

#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <SDL/SDL.h>

#include <map>
#include <utility>

#ifndef NDEBUG
#include <stdexcept>
#endif

namespace TCrem
{
	/**
	 *	\todo (berenger#4#) ensure type safety (replace the "void*" types)
	 */
	class Event;
	typedef void (*CALLBACK)(void *, const Event&); //! function type of callbacks. The 1st argument is the object affected by event (usually a window) to allow the function to affect it, and the second is a reference to the event itself, to allow the function to know what happened.
	typedef std::multimap<Event,std::pair<CALLBACK, void * > > TRIGGER_MAP; //! type internally used by event manager. 1st arg is the trigger event, 2nd one is a pair with the function to run and the object (usually a window) affected. It is possible to have an event triggering more than one callback.

	enum TEXTURE_POSITION {TOPLEFT,TOP,TOPRIGHT,RIGHT,BOTTOMRIGHT,BOTTOM,BOTTOMLEFT,LEFT};

	enum EVENT_TYPE
	{
		ET_UNKNOWNEVENT=0,
		ET_ACTIVEEVENT=1,
		ET_KEYDOWN,
		ET_KEYUP,
		ET_MOUSEMOTION,
		ET_MOUSEBUTTONDOWN=SDL_MOUSEBUTTONDOWN,
		ET_MOUSEBUTTONUP=SDL_MOUSEBUTTONUP,
		ET_JOYAXISMOTION,
		ET_JOYBALLMOTION,
		ET_JOYHATMOTION,
		ET_JOYBUTTONDOWN,
		ET_JOYBUTTONUP,
		ET_QUIT,
		ET_SYSWMEVENT,
		ET_VIDEORESIZE,
		ET_VIDEOEXPOSE,
		ET_USEREVENT
	};

	enum KEY_NAME
	{
		KN_BACKSPACE
		,KN_TAB
		,KN_CLEAR
		,KN_RETURN
		,KN_PAUSE
		,KN_ESCAPE
		,KN_SPACE
		,KN_EXCLAIM
		,KN_QUOTEDBL
		,KN_HASH
		,KN_DOLLAR
		,KN_AMPERSAND
		,KN_QUOTE
		,KN_LEFTPAREN
		,KN_RIGHTPAREN
		,KN_ASTERISK
		,KN_PLUS
		,KN_COMMA
		,KN_MINUS
		,KN_PERIOD
		,KN_SLASH
		,KN_0
		,KN_1
		,KN_2
		,KN_3
		,KN_4
		,KN_5
		,KN_6
		,KN_7
		,KN_8
		,KN_9
		,KN_COLON
		,KN_SEMICOLON
		,KN_LESS
		,KN_EQUALS
		,KN_GREATER
		,KN_QUESTION
		,KN_AT
		,KN_LEFTBRACKET
		,KN_BACKSLASH
		,KN_RIGHTBRACKET
		,KN_CARET
		,KN_UNDERSCORE
		,KN_BACKQUOTE
		,KN_a
		,KN_b
		,KN_c
		,KN_d
		,KN_e
		,KN_f
		,KN_g
		,KN_h
		,KN_i
		,KN_j
		,KN_k
		,KN_l
		,KN_m
		,KN_n
		,KN_o
		,KN_p
		,KN_q
		,KN_r
		,KN_s
		,KN_t
		,KN_u
		,KN_v
		,KN_w
		,KN_x
		,KN_y
		,KN_z
		,KN_DELETE
		,KN_KP0
		,KN_KP1
		,KN_KP2
		,KN_KP3
		,KN_KP4
		,KN_KP5
		,KN_KP6
		,KN_KP7
		,KN_KP8
		,KN_KP9
		,KN_KP_PERIOD
		,KN_KP_DIVIDE
		,KN_KP_MULTIPLY
		,KN_KP_MINUS
		,KN_KP_PLUS
		,KN_KP_ENTER
		,KN_KP_EQUALS
		,KN_UP
		,KN_DOWN
		,KN_RIGHT
		,KN_LEFT
		,KN_INSERT
		,KN_HOME
		,KN_END
		,KN_PAGEUP
		,KN_PAGEDOWN
		,KN_F1
		,KN_F2
		,KN_F3
		,KN_F4
		,KN_F5
		,KN_F6
		,KN_F7
		,KN_F8
		,KN_F9
		,KN_F10
		,KN_F11
		,KN_F12
		,KN_F13
		,KN_F14
		,KN_F15
		,KN_NUMLOCK
		,KN_CAPSLOCK
		,KN_SCROLLOCK
		,KN_RSHIFT
		,KN_LSHIFT
		,KN_RCTRL
		,KN_LCTRL
		,KN_RALT
		,KN_LALT
		,KN_RMETA
		,KN_LMETA
		,KN_LSUPER
		,KN_RSUPER
		,KN_MODE
		,KN_HELP
		,KN_PRINT
		,KN_SYSREQ
		,KN_BREAK
		,KN_MENU
		,KN_POWER
		,KN_EURO
	};

	typedef struct
	{
		bool pressed;
		enum BUTTON{LEFT,MIDDLE,RIGHT} button;
	}MOUSE;

	typedef struct
	{
	}QUIT;

	typedef struct
	{
		KEY_NAME code;
	}KEY;

}

#endif
