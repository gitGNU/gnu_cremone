#include "eventcaster.h"

namespace crem
{

	TCrem::EVENT_TYPE sdl2cremoneEVENT_TYPE(uint8_t type)
	{
		switch(type)
		{
		case SDL_ACTIVEEVENT:
			return TCrem::ET_ACTIVEEVENT;
		case SDL_KEYDOWN:
			return TCrem::ET_KEYDOWN;
		case SDL_KEYUP:
			return TCrem::ET_KEYUP;
		case SDL_MOUSEMOTION:
			return TCrem::ET_MOUSEMOTION;
		case SDL_MOUSEBUTTONDOWN:
			return TCrem::ET_MOUSEBUTTONDOWN;
		case SDL_MOUSEBUTTONUP:
			return TCrem::ET_MOUSEBUTTONUP;
		case SDL_JOYAXISMOTION:
			return TCrem::ET_JOYAXISMOTION;
		case SDL_JOYBALLMOTION:
			return TCrem::ET_JOYBALLMOTION;
		case SDL_JOYHATMOTION:
			return TCrem::ET_JOYHATMOTION;
		case SDL_JOYBUTTONDOWN:
			return TCrem::ET_JOYBUTTONDOWN;
		case SDL_JOYBUTTONUP:
			return TCrem::ET_JOYBUTTONUP;
		case SDL_QUIT:
			return TCrem::ET_QUIT;
		case SDL_SYSWMEVENT:
			return TCrem::ET_SYSWMEVENT;
		case SDL_VIDEORESIZE:
			return TCrem::ET_VIDEORESIZE;
		case SDL_VIDEOEXPOSE:
			return TCrem::ET_VIDEOEXPOSE;
		case SDL_USEREVENT:
		default:
			return TCrem::ET_USEREVENT;
		}
	}

	TCrem::KEY_NAME sdl_cast_KEY(SDLKey key)
	{
	//	return (KEY_NAME)((int)SDLK_BACKSPACE-(int)KN_BACKSPACE+key+8);
		//return (KEY_NAME)(((int)key));
		switch(key)
		{
		case SDLK_BACKSPACE:
			return TCrem::KN_BACKSPACE;
		case SDLK_TAB:
			return TCrem::KN_TAB;
		case SDLK_CLEAR:
			return TCrem::KN_CLEAR;
		case SDLK_RETURN:
			return TCrem::KN_RETURN;
		case SDLK_PAUSE:
			return TCrem::KN_PAUSE;
		case SDLK_ESCAPE:
			return TCrem::KN_ESCAPE;
		case SDLK_SPACE:
			return TCrem::KN_SPACE;
		case SDLK_EXCLAIM:
			return TCrem::KN_EXCLAIM;
		case SDLK_QUOTEDBL:
			return TCrem::KN_QUOTEDBL;
		case SDLK_HASH:
			return TCrem::KN_HASH;
		case SDLK_DOLLAR:
			return TCrem::KN_DOLLAR;
		case SDLK_AMPERSAND:
			return TCrem::KN_AMPERSAND;
		case SDLK_QUOTE:
			return TCrem::KN_QUOTE;
		case SDLK_LEFTPAREN:
			return TCrem::KN_LEFTPAREN;
		case SDLK_RIGHTPAREN:
			return TCrem::KN_RIGHTPAREN;
		case SDLK_ASTERISK:
			return TCrem::KN_ASTERISK;
		case SDLK_PLUS:
			return TCrem::KN_PLUS;
		case SDLK_COMMA:
			return TCrem::KN_COMMA;
		case SDLK_MINUS:
			return TCrem::KN_MINUS;
		case SDLK_PERIOD:
			return TCrem::KN_PERIOD;
		case SDLK_SLASH:
			return TCrem::KN_SLASH;
		case SDLK_0:
			return TCrem::KN_0;
		case SDLK_1:
			return TCrem::KN_1;
		case SDLK_2:
			return TCrem::KN_2;
		case SDLK_3:
			return TCrem::KN_3;
		case SDLK_4:
			return TCrem::KN_4;
		case SDLK_5:
			return TCrem::KN_5;
		case SDLK_6:
			return TCrem::KN_6;
		case SDLK_7:
			return TCrem::KN_7;
		case SDLK_8:
			return TCrem::KN_8;
		case SDLK_9:
			return TCrem::KN_9;
		case SDLK_COLON:
			return TCrem::KN_COLON;
		case SDLK_SEMICOLON:
			return TCrem::KN_SEMICOLON;
		case SDLK_LESS:
			return TCrem::KN_LESS;
		case SDLK_EQUALS:
			return TCrem::KN_EQUALS;
		case SDLK_GREATER:
			return TCrem::KN_GREATER;
		case SDLK_QUESTION:
			return TCrem::KN_QUESTION;
		case SDLK_AT:
			return TCrem::KN_AT;
		case SDLK_LEFTBRACKET:
			return TCrem::KN_LEFTBRACKET;
		case SDLK_BACKSLASH:
			return TCrem::KN_BACKSLASH;
		case SDLK_RIGHTBRACKET:
			return TCrem::KN_RIGHTBRACKET;
		case SDLK_CARET:
			return TCrem::KN_CARET;
		case SDLK_UNDERSCORE:
			return TCrem::KN_UNDERSCORE;
		case SDLK_BACKQUOTE:
			return TCrem::KN_BACKQUOTE;
		case SDLK_a:
			return TCrem::KN_a;
		case SDLK_b:
			return TCrem::KN_b;
		case SDLK_c:
			return TCrem::KN_c;
		case SDLK_d:
			return TCrem::KN_d;
		case SDLK_e:
			return TCrem::KN_e;
		case SDLK_f:
			return TCrem::KN_f;
		case SDLK_g:
			return TCrem::KN_g;
		case SDLK_h:
			return TCrem::KN_h;
		case SDLK_i:
			return TCrem::KN_i;
		case SDLK_j:
			return TCrem::KN_j;
		case SDLK_k:
			return TCrem::KN_k;
		case SDLK_l:
			return TCrem::KN_l;
		case SDLK_m:
			return TCrem::KN_m;
		case SDLK_n:
			return TCrem::KN_n;
		case SDLK_o:
			return TCrem::KN_o;
		case SDLK_p:
			return TCrem::KN_p;
		case SDLK_q:
			return TCrem::KN_q;
		case SDLK_r:
			return TCrem::KN_r;
		case SDLK_s:
			return TCrem::KN_s;
		case SDLK_t:
			return TCrem::KN_t;
		case SDLK_u:
			return TCrem::KN_u;
		case SDLK_v:
			return TCrem::KN_v;
		case SDLK_w:
			return TCrem::KN_w;
		case SDLK_x:
			return TCrem::KN_x;
		case SDLK_y:
			return TCrem::KN_y;
		case SDLK_z:
			return TCrem::KN_z;
		case SDLK_DELETE:
			return TCrem::KN_DELETE;
		case SDLK_KP0:
			return TCrem::KN_KP0;
		case SDLK_KP1:
			return TCrem::KN_KP1;
		case SDLK_KP2:
			return TCrem::KN_KP2;
		case SDLK_KP3:
			return TCrem::KN_KP3;
		case SDLK_KP4:
			return TCrem::KN_KP4;
		case SDLK_KP5:
			return TCrem::KN_KP5;
		case SDLK_KP6:
			return TCrem::KN_KP6;
		case SDLK_KP7:
			return TCrem::KN_KP7;
		case SDLK_KP8:
			return TCrem::KN_KP8;
		case SDLK_KP9:
			return TCrem::KN_KP9;
		case SDLK_KP_PERIOD:
			return TCrem::KN_KP_PERIOD;
		case SDLK_KP_DIVIDE:
			return TCrem::KN_KP_DIVIDE;
		case SDLK_KP_MULTIPLY:
			return TCrem::KN_KP_MULTIPLY;
		case SDLK_KP_MINUS:
			return TCrem::KN_KP_MINUS;
		case SDLK_KP_PLUS:
			return TCrem::KN_KP_PLUS;
		case SDLK_KP_ENTER:
			return TCrem::KN_KP_ENTER;
		case SDLK_KP_EQUALS:
			return TCrem::KN_KP_EQUALS;
		case SDLK_UP:
			return TCrem::KN_UP;
		case SDLK_DOWN:
			return TCrem::KN_DOWN;
		case SDLK_RIGHT:
			return TCrem::KN_RIGHT;
		case SDLK_LEFT:
			return TCrem::KN_LEFT;
		case SDLK_INSERT:
			return TCrem::KN_INSERT;
		case SDLK_HOME:
			return TCrem::KN_HOME;
		case SDLK_END:
			return TCrem::KN_END;
		case SDLK_PAGEUP:
			return TCrem::KN_PAGEUP;
		case SDLK_PAGEDOWN:
			return TCrem::KN_PAGEDOWN;
		case SDLK_F1:
			return TCrem::KN_F1;
		case SDLK_F2:
			return TCrem::KN_F2;
		case SDLK_F3:
			return TCrem::KN_F3;
		case SDLK_F4:
			return TCrem::KN_F4;
		case SDLK_F5:
			return TCrem::KN_F5;
		case SDLK_F6:
			return TCrem::KN_F6;
		case SDLK_F7:
			return TCrem::KN_F7;
		case SDLK_F8:
			return TCrem::KN_F8;
		case SDLK_F9:
			return TCrem::KN_F9;
		case SDLK_F10:
			return TCrem::KN_F10;
		case SDLK_F11:
			return TCrem::KN_F11;
		case SDLK_F12:
			return TCrem::KN_F12;
		case SDLK_F13:
			return TCrem::KN_F13;
		case SDLK_F14:
			return TCrem::KN_F14;
		case SDLK_F15:
			return TCrem::KN_F15;
		case SDLK_NUMLOCK:
			return TCrem::KN_NUMLOCK;
		case SDLK_CAPSLOCK:
			return TCrem::KN_CAPSLOCK;
		case SDLK_SCROLLOCK:
			return TCrem::KN_SCROLLOCK;
		case SDLK_RSHIFT:
			return TCrem::KN_RSHIFT;
		case SDLK_LSHIFT:
			return TCrem::KN_LSHIFT;
		case SDLK_RCTRL:
			return TCrem::KN_RCTRL;
		case SDLK_LCTRL:
			return TCrem::KN_LCTRL;
		case SDLK_RALT:
			return TCrem::KN_RALT;
		case SDLK_LALT:
			return TCrem::KN_LALT;
		case SDLK_RMETA:
			return TCrem::KN_RMETA;
		case SDLK_LMETA:
			return TCrem::KN_LMETA;
		case SDLK_LSUPER:
			return TCrem::KN_LSUPER;
		case SDLK_RSUPER:
			return TCrem::KN_RSUPER;
		case SDLK_MODE:
			return TCrem::KN_MODE;
		case SDLK_HELP:
			return TCrem::KN_HELP;
		case SDLK_PRINT:
			return TCrem::KN_PRINT;
		case SDLK_SYSREQ:
			return TCrem::KN_SYSREQ;
		case SDLK_BREAK:
			return TCrem::KN_BREAK;
		case SDLK_MENU:
			return TCrem::KN_MENU;
		case SDLK_POWER:
			return TCrem::KN_POWER;
		case SDLK_EURO:
			return TCrem::KN_EURO;
		}
	}

	TCrem::MOUSE::BUTTON sdl_cast_BUTTON(SDLKey key)
	{
	}
}
