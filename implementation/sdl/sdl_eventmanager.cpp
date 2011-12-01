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

#include "sdl_eventmanager.h"

#include <stdexcept>

#include <event.h>

namespace crem
{

	using namespace TCrem;

	SDL_EventManager::SDL_EventManager(void)
	:m_mask(0)
	{
	}

	void SDL_EventManager::pollEvent(void)
	{
		SDL_Event sdlev;
		Event ev;

//SDL_Event *etmp=new SDL_Event();
//etmp->type=SDL_MOUSEBUTTONUP;
//etmp->button.button=SDL_BUTTON_RIGHT;
//etmp->button.state=SDL_RELEASED;
//etmp->button.x=20;
//etmp->button.y=20;
//if(SDL_PushEvent(etmp))
//	throw std::runtime_error(SDL_GetError());

		while (SDL_PollEvent(&sdlev))
		{
			if(m_mask & SDL_EVENTMASK(sdlev.type))
			{
				ev=Event::createEvent(sdl2cremone(sdlev.type));
				switch (sdlev.type)
				{
				case SDL_QUIT:
					break;
				case SDL_KEYDOWN:
					ev.set(sdl2cremone(sdlev.key.keysym.sym),sdlev.type==SDL_KEYDOWN);
					break;
				case SDL_KEYUP:
					ev.set(sdl2cremone(sdlev.key.keysym.sym),sdlev.type==SDL_KEYDOWN);
					break;
				case SDL_MOUSEBUTTONUP:
					ev.set(sdl2cremone(sdlev.button),sdlev.type==SDL_MOUSEBUTTONDOWN);
					break;
				case SDL_MOUSEBUTTONDOWN:
					ev.set(sdl2cremone(sdlev.button),sdlev.type==SDL_MOUSEBUTTONDOWN);
					break;
				default:
					;
				}
				pushEvent(ev);
			}
		}
		EventManager::pollEvent();
	}

	void SDL_EventManager::addEventManager(Event const &ev, CALLBACK const callback, void *window)
	{
		m_mask|=SDL_EVENTMASK(ev.getType());
		TCrem::EventManager::addEventManager(ev,callback,window);
	}

	EVENT_TYPE SDL_EventManager::sdl2cremone(uint8_t type)
	{
		switch(type)
		{
		case SDL_ACTIVEEVENT:
			return ET_ACTIVEEVENT;
		case SDL_KEYDOWN:
			return ET_KEYDOWN;
		case SDL_KEYUP:
			return ET_KEYUP;
		case SDL_MOUSEMOTION:
			return ET_MOUSEMOTION;
		case SDL_MOUSEBUTTONDOWN:
			return ET_MOUSEBUTTONDOWN;
		case SDL_MOUSEBUTTONUP:
			return ET_MOUSEBUTTONUP;
		case SDL_JOYAXISMOTION:
			return ET_JOYAXISMOTION;
		case SDL_JOYBALLMOTION:
			return ET_JOYBALLMOTION;
		case SDL_JOYHATMOTION:
			return ET_JOYHATMOTION;
		case SDL_JOYBUTTONDOWN:
			return ET_JOYBUTTONDOWN;
		case SDL_JOYBUTTONUP:
			return ET_JOYBUTTONUP;
		case SDL_QUIT:
			return ET_QUIT;
		case SDL_SYSWMEVENT:
			return ET_SYSWMEVENT;
		case SDL_VIDEORESIZE:
			return ET_VIDEORESIZE;
		case SDL_VIDEOEXPOSE:
			return ET_VIDEOEXPOSE;
		case SDL_USEREVENT:
		default:
			return ET_USEREVENT;
		}
	}

	KEY_NAME SDL_EventManager::sdl2cremone(SDLKey key)
	{
	//	return (KEY_NAME)((int)SDLK_BACKSPACE-(int)KN_BACKSPACE+key+8);
		//return (KEY_NAME)(((int)key));
		switch(key)
		{
		case SDLK_BACKSPACE:
			return KN_BACKSPACE;
		case SDLK_TAB:
			return KN_TAB;
		case SDLK_CLEAR:
			return KN_CLEAR;
		case SDLK_RETURN:
			return KN_RETURN;
		case SDLK_PAUSE:
			return KN_PAUSE;
		case SDLK_ESCAPE:
			return KN_ESCAPE;
		case SDLK_SPACE:
			return KN_SPACE;
		case SDLK_EXCLAIM:
			return KN_EXCLAIM;
		case SDLK_QUOTEDBL:
			return KN_QUOTEDBL;
		case SDLK_HASH:
			return KN_HASH;
		case SDLK_DOLLAR:
			return KN_DOLLAR;
		case SDLK_AMPERSAND:
			return KN_AMPERSAND;
		case SDLK_QUOTE:
			return KN_QUOTE;
		case SDLK_LEFTPAREN:
			return KN_LEFTPAREN;
		case SDLK_RIGHTPAREN:
			return KN_RIGHTPAREN;
		case SDLK_ASTERISK:
			return KN_ASTERISK;
		case SDLK_PLUS:
			return KN_PLUS;
		case SDLK_COMMA:
			return KN_COMMA;
		case SDLK_MINUS:
			return KN_MINUS;
		case SDLK_PERIOD:
			return KN_PERIOD;
		case SDLK_SLASH:
			return KN_SLASH;
		case SDLK_0:
			return KN_0;
		case SDLK_1:
			return KN_1;
		case SDLK_2:
			return KN_2;
		case SDLK_3:
			return KN_3;
		case SDLK_4:
			return KN_4;
		case SDLK_5:
			return KN_5;
		case SDLK_6:
			return KN_6;
		case SDLK_7:
			return KN_7;
		case SDLK_8:
			return KN_8;
		case SDLK_9:
			return KN_9;
		case SDLK_COLON:
			return KN_COLON;
		case SDLK_SEMICOLON:
			return KN_SEMICOLON;
		case SDLK_LESS:
			return KN_LESS;
		case SDLK_EQUALS:
			return KN_EQUALS;
		case SDLK_GREATER:
			return KN_GREATER;
		case SDLK_QUESTION:
			return KN_QUESTION;
		case SDLK_AT:
			return KN_AT;
		case SDLK_LEFTBRACKET:
			return KN_LEFTBRACKET;
		case SDLK_BACKSLASH:
			return KN_BACKSLASH;
		case SDLK_RIGHTBRACKET:
			return KN_RIGHTBRACKET;
		case SDLK_CARET:
			return KN_CARET;
		case SDLK_UNDERSCORE:
			return KN_UNDERSCORE;
		case SDLK_BACKQUOTE:
			return KN_BACKQUOTE;
		case SDLK_a:
			return KN_a;
		case SDLK_b:
			return KN_b;
		case SDLK_c:
			return KN_c;
		case SDLK_d:
			return KN_d;
		case SDLK_e:
			return KN_e;
		case SDLK_f:
			return KN_f;
		case SDLK_g:
			return KN_g;
		case SDLK_h:
			return KN_h;
		case SDLK_i:
			return KN_i;
		case SDLK_j:
			return KN_j;
		case SDLK_k:
			return KN_k;
		case SDLK_l:
			return KN_l;
		case SDLK_m:
			return KN_m;
		case SDLK_n:
			return KN_n;
		case SDLK_o:
			return KN_o;
		case SDLK_p:
			return KN_p;
		case SDLK_q:
			return KN_q;
		case SDLK_r:
			return KN_r;
		case SDLK_s:
			return KN_s;
		case SDLK_t:
			return KN_t;
		case SDLK_u:
			return KN_u;
		case SDLK_v:
			return KN_v;
		case SDLK_w:
			return KN_w;
		case SDLK_x:
			return KN_x;
		case SDLK_y:
			return KN_y;
		case SDLK_z:
			return KN_z;
		case SDLK_DELETE:
			return KN_DELETE;
		case SDLK_KP0:
			return KN_KP0;
		case SDLK_KP1:
			return KN_KP1;
		case SDLK_KP2:
			return KN_KP2;
		case SDLK_KP3:
			return KN_KP3;
		case SDLK_KP4:
			return KN_KP4;
		case SDLK_KP5:
			return KN_KP5;
		case SDLK_KP6:
			return KN_KP6;
		case SDLK_KP7:
			return KN_KP7;
		case SDLK_KP8:
			return KN_KP8;
		case SDLK_KP9:
			return KN_KP9;
		case SDLK_KP_PERIOD:
			return KN_KP_PERIOD;
		case SDLK_KP_DIVIDE:
			return KN_KP_DIVIDE;
		case SDLK_KP_MULTIPLY:
			return KN_KP_MULTIPLY;
		case SDLK_KP_MINUS:
			return KN_KP_MINUS;
		case SDLK_KP_PLUS:
			return KN_KP_PLUS;
		case SDLK_KP_ENTER:
			return KN_KP_ENTER;
		case SDLK_KP_EQUALS:
			return KN_KP_EQUALS;
		case SDLK_UP:
			return KN_UP;
		case SDLK_DOWN:
			return KN_DOWN;
		case SDLK_RIGHT:
			return KN_RIGHT;
		case SDLK_LEFT:
			return KN_LEFT;
		case SDLK_INSERT:
			return KN_INSERT;
		case SDLK_HOME:
			return KN_HOME;
		case SDLK_END:
			return KN_END;
		case SDLK_PAGEUP:
			return KN_PAGEUP;
		case SDLK_PAGEDOWN:
			return KN_PAGEDOWN;
		case SDLK_F1:
			return KN_F1;
		case SDLK_F2:
			return KN_F2;
		case SDLK_F3:
			return KN_F3;
		case SDLK_F4:
			return KN_F4;
		case SDLK_F5:
			return KN_F5;
		case SDLK_F6:
			return KN_F6;
		case SDLK_F7:
			return KN_F7;
		case SDLK_F8:
			return KN_F8;
		case SDLK_F9:
			return KN_F9;
		case SDLK_F10:
			return KN_F10;
		case SDLK_F11:
			return KN_F11;
		case SDLK_F12:
			return KN_F12;
		case SDLK_F13:
			return KN_F13;
		case SDLK_F14:
			return KN_F14;
		case SDLK_F15:
			return KN_F15;
		case SDLK_NUMLOCK:
			return KN_NUMLOCK;
		case SDLK_CAPSLOCK:
			return KN_CAPSLOCK;
		case SDLK_SCROLLOCK:
			return KN_SCROLLOCK;
		case SDLK_RSHIFT:
			return KN_RSHIFT;
		case SDLK_LSHIFT:
			return KN_LSHIFT;
		case SDLK_RCTRL:
			return KN_RCTRL;
		case SDLK_LCTRL:
			return KN_LCTRL;
		case SDLK_RALT:
			return KN_RALT;
		case SDLK_LALT:
			return KN_LALT;
		case SDLK_RMETA:
			return KN_RMETA;
		case SDLK_LMETA:
			return KN_LMETA;
		case SDLK_LSUPER:
			return KN_LSUPER;
		case SDLK_RSUPER:
			return KN_RSUPER;
		case SDLK_MODE:
			return KN_MODE;
		case SDLK_HELP:
			return KN_HELP;
		case SDLK_PRINT:
			return KN_PRINT;
		case SDLK_SYSREQ:
			return KN_SYSREQ;
		case SDLK_BREAK:
			return KN_BREAK;
		case SDLK_MENU:
			return KN_MENU;
		case SDLK_POWER:
			return KN_POWER;
		case SDLK_EURO:
			return KN_EURO;
		}
	}

	MOUSE::BUTTON SDL_EventManager::sdl2cremone(SDL_MouseButtonEvent button)
	{
		switch(button.button)
		{
		case SDL_BUTTON_LEFT:
			return TCrem::MOUSE::BUTTON::LEFT;
		case SDL_BUTTON_MIDDLE:
			return TCrem::MOUSE::BUTTON::MIDDLE;
		case SDL_BUTTON_RIGHT:
			return TCrem::MOUSE::BUTTON::RIGHT;
		default:
			throw std::logic_error("Unknown button");
		}
	}
}
