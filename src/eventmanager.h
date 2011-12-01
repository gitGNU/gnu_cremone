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

#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <stack>

#include "tsingleton.h"
#include "definitions.h"

namespace TCrem
{
	class Event;

	/**
	 *	\todo (berenger#3#) specify and implement exception-safe
	 *	\todo (berenger#9#) add some logging capabilities
	 *	\todo (berenger#9#) add some debugging capabilities
	 *	\todo (berenger#4#) ensure type safety (replace the "void*" types)
	 */

	class EventManager:public TSingleton<EventManager>
	{
	friend class TSingleton<EventManager>;
	public:
		/** \brief Search in event list if one can trigger a callback
		 *	If an event happened match a trigger, execute the corresponding callback
		 *	Events are removed from the stack after call to this method.
		 */
		virtual void pollEvent(void);
		/** \brief Add an event in the stack
		 * \param ev event const&
		 */
		void pushEvent(Event const &ev);
		/** \brief bind a trigger event, a callback and an object, and put them to the trigger list
		 * \param trigger event const&
		 * \param callback CALLBACK const
		 * \param window void*
		 */
		virtual void addEventManager(Event const trigger, CALLBACK const callback, void *window);
	protected:
		/** \brief Ctor */
		EventManager(void);
		/** \brief Dtor */
		virtual ~EventManager(void) throw();
	private:

	public:
	protected:
		std::stack<Event> m_eventStack; //!< stack containing all events registered while the last call to pollEvent()
	private:
		TRIGGER_MAP m_triggers; //!<multimap assigning to each trigger event a callback and the affected window
	};
}

#endif
