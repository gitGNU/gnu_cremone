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

#include "event.h"

namespace TCrem
{

	Event::Event(void)
	:m_event(),m_type(ET_UNKNOWNEVENT)
	{
	}

	Event::Event(EVENT_TYPE const type)
	:m_event(),m_type(type)
	{
	}

	Event::~Event(void)
	{
	}

	bool Event::operator<(Event const &ev) const throw ()
	{
		return m_type<ev.m_type;
	}

	bool Event::operator==(Event const &ev) const throw (std::logic_error)
	{
		if(m_type!=ev.m_type)
			return false;
		switch(m_type)
		{
		default:
		case ET_UNKNOWNEVENT:
			throw std::logic_error("Unknown event type");
		case ET_KEYDOWN:
		case ET_KEYUP:
			return m_event.key.code==ev.m_event.key.code;
		case ET_MOUSEMOTION:
			break;
		case ET_MOUSEBUTTONDOWN:
		case ET_MOUSEBUTTONUP:
			return m_event.mouse.button==ev.m_event.mouse.button;
		case ET_QUIT:
			return true;
		case ET_JOYAXISMOTION:
		case ET_JOYBALLMOTION:
		case ET_JOYHATMOTION:
		case ET_JOYBUTTONDOWN:
		case ET_JOYBUTTONUP:
		case ET_SYSWMEVENT:
		case ET_VIDEORESIZE:
		case ET_VIDEOEXPOSE:
		case ET_USEREVENT:
		case ET_ACTIVEEVENT:
			break;
		}
		throw std::logic_error("Event type not implemented");
	}

	void Event::set(KEY_NAME keycode, bool press)
	{
		m_type=press?ET_KEYDOWN:ET_KEYUP;
		m_event.key.code=keycode;
	}

	void Event::set(MOUSE::BUTTON btn, bool press)
	{
		m_type=press?ET_MOUSEBUTTONDOWN:ET_MOUSEBUTTONUP;
		m_event.mouse.button=btn;
	}

	EVENT_TYPE Event::getType(void)const
	{
		return m_type;
	}
}
