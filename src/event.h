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

#ifndef EVENT_H
#define EVENT_H

#include <stdint.h>

#include "definitions.h"

namespace TCrem
{
	/**
	 *	\todo (berenger#3#) specify and implement exception-safe
	 *	\todo (berenger#9#) add some logging capabilities
	 *	\todo (berenger#9#) add some debugging capabilities
	 *	\todo (berenger#9#) think more about the ID usage. I think I should remove it.
	 */

	class Event
	{
	public:
		/** \brief Ctor */
		Event(void);
		/** \brief  Ctor
		 * \param priority uint32_t
		 */
		Event(EVENT_TYPE const type);
		/** Dtor */
		virtual ~Event(void);
		/** \brief create an event and return it
		 * \param type EVENT_TYPE type of event (aka: KEY, MOUSE,...)
		 * \return event
		 */
		static Event createEvent(EVENT_TYPE type)
		{
			return *(new Event(type));
		}
		/** \brief compare event's priority.
		 * \param ev event const&
		 * \return bool true if ev have a lower priority. (0 is the highest priority)
		 * \note this method is a multimap requirement.
		 */
		bool operator<(Event const &ev) const throw ();
		/** \brief test event's equality
		 * \param ev event const&
		 * \return bool true if events are the same
		 */
		bool operator==(Event const &ev) const throw (std::logic_error);

		/** \brief set the event to the given key
		 * \param keycode KEY_NAME
		 * \param press bool
		 */
		void set(KEY_NAME keycode, bool press=true);
		void set(MOUSE::BUTTON btn, bool press=true);
		EVENT_TYPE getType(void)const;

	public:
		union
		{
			MOUSE mouse;
			QUIT quit;
			KEY key;
		} m_event;
		EVENT_TYPE m_type;
	protected:
	private:
	};
}

#endif
