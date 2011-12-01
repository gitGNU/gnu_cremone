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

#ifndef TAPPWINDOW_H
#define TAPPWINDOW_H

//standard headers
#include <stdint.h>
#include <memory>
#include <string>

#include "tgraphicobject.h"

namespace TCrem
{
	/**
	 *	\todo (berenger#3#) specify and implement exception-safe
	 *	\todo (berenger#9#) add some logging capabilities
	 *	\todo (berenger#9#) add some debugging capabilities
	 *	\todo (berenger#4#) refactor template parameter names
	 *	\todo (berenger#2#) use only references to smart pointers
	 *	\todo (berenger#1#) make this class inherit from the external bitmap, which inherit from __bitmap
	 *	\todo (berenger#3#) implement cast operators (" sprite::operator const type&(void)")
	 */

	/** \brief Manage operations made on the screen */
	template <typename PhysicObj>
	class TAppWindow: public TGraphicObject<PhysicObj>
	{
	public:

		/** \brief Ctor */
		TAppWindow(void) throw();
		/** Ctor */
		virtual ~TAppWindow(void) throw();

		/** \brief Initialize the screen with custom parameters
		 * \param width const uint16_t
		 * \param height const uint16_t
		 * \param bpp const uint8_t bits per pixel
		 * \param flags const uint32_t
		 */
		virtual void init(void)=0;

		/** \brief Find the best video mode and initialize screen with it
		 * \param flags const uint32_t
		 * \warning Do nothing if video mode is already set, but can't know it! Time loss...
		 */
		virtual void setBestMode(void)=0;

		/** \brief refresh the screen */
		virtual void refresh(void )=0;
		TAppWindow<PhysicObj>& fullscreen(bool const enable=false);
		TAppWindow<PhysicObj>& title(std::string const &title="");
		TAppWindow<PhysicObj>& winIcon(std::weak_ptr<TGraphicObject<PhysicObj> > const icon);

	protected:
		/** \brief dumb method used to avoid shared_ptr to free the screen
		 * \param ptr PhysicObj*
		 */
		void free(PhysicObj *ptr);
		/** \brief method used to allocate data to m_screen
		 * \param surface PhysicObj*
		 */
		void set(PhysicObj* surface);
	private:

	public:
	protected:
		bool m_fullscreen;
		std::string m_title;
		std::shared_ptr<TGraphicObject<PhysicObj> > m_icon;
	private:
	};

	//implementations
	#include "tpp/tappwindow.cpp"
}

#endif
