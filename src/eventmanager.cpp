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

#include <utility>

#include "eventmanager.h"

#include "event.h"

namespace TCrem
{
	EventManager::EventManager(void)
	:/*singleton<eventManager>(),*/m_eventStack(),m_triggers()
	{
	}

	EventManager::~EventManager(void) throw()
	{
	}

	void EventManager::addEventManager(Event const trigger, CALLBACK const callback, void *window)
	{
		std::pair<CALLBACK, void *> p1(callback,window);
		std::pair<Event,std::pair<CALLBACK, void *> >p2(trigger,p1);
		m_triggers.insert(p2);

	/*
		m_triggers.insert(
			std::pair<	const event&,std::pair<CALLBACK, void *> >
					(	trigger,std::pair<CALLBACK, void *>(callback,window)));
	*/
	}

	void EventManager::pushEvent(Event const &ev)
	{
		m_eventStack.push(ev);
	}

	void EventManager::pollEvent(void)
	{
		TRIGGER_MAP::iterator it;
		std::pair<TRIGGER_MAP::iterator,TRIGGER_MAP::iterator> triggered_range;
		Event ev;

		while(!m_eventStack.empty())
		{
			ev=m_eventStack.top();
			m_eventStack.pop();
			triggered_range=m_triggers.equal_range(ev);//type filtering
			for(it=triggered_range.first;it!=triggered_range.second;it++)
				if(ev==(*it).first)//entire filtering
					(*it).second.first((*it).second.second,ev);
		}
	}
}
