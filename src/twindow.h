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

#ifndef TWINDOW_H
#define TWINDOW_H

#include <vector>
#include <math.h>
#include <algorithm>

#include "ttheme.h"
#include "tsprite.h"

namespace TCrem
{
	template <typename PhysicObj, typename object>
	class TWindow:public TSprite<PhysicObj,object>, public std::enable_shared_from_this<TWindow<PhysicObj,object> >
	{
	public:
		/** \brief Ctor */
		TWindow(void);
		/** \brief Ctor: initialise window with existing theme and image
		 * \param theme std::weak_ptr<__theme<PhysicObj,object> > const &
		 * \param img __image<PhysicObj,object> const &
		 */
		TWindow(std::weak_ptr<TTheme<PhysicObj,object> > const theme, TImage<PhysicObj, object> const &img);
		/** \brief Dtor */
		virtual ~TWindow(void);

		/** \brief assign a theme
		 *	assign a theme to the window and call set()
		 * \param theme std::weak_ptr<__theme<PhysicObj,object> >const&
		 */
		void set(std::weak_ptr<TTheme<PhysicObj,object> > const theme);
		/** \brief assign an image
		 *	assign an image to the window and call set()
		 * \param image __image<PhysicObj, object> const&
		 */
		void set(TImage<PhysicObj,object> const &image);
		/** \brief unset the flag m_isInit of the window and all its parents
		 *	by unsetting the m_isInit, the method force the window and all its
		 *	parents to be recalculated on next draw
		 */
		void set(void)throw();

		/** \brief draw the window on the target image
		 * \param target std::weak_ptr<PhysicObj>&
		 */
		void draw(std::weak_ptr<PhysicObj> target);

		/** \brief move a window
		 *	Move a window. If it is a child, call the set() method to refresh
		 *	it's parents
		 */
		void move(const int16_t x, const int16_t y) throw();

		/** \brief add a window child and call set()
		 *	adding a child window imply to recalc the image of the current
		 *	window and of all its parents
		 * \param child std::unique_ptr<__window<PhysicObj,object> >&
		 */
		void addChild(std::weak_ptr<TWindow<PhysicObj, object> > child);
	protected:
		/** \brief recalc the image
		 *	\todo (Berenger#3#) avoid redrawing of borders if size didn't
		 *	change. (create a buildBody method)
		 */
		void do_buildSprite(void);

		void do_buildBorders(uint16_t finalwidth, uint16_t finalheight);
		void do_buildBody(void);

		/** \brief draw vertical borders
		 * \param start TEXTURE_POSITION
		 * \param filler TEXTURE_POSITION
		 * \param offset uint16_t const
		 */
		void do_drawVBorder(TEXTURE_POSITION start,TEXTURE_POSITION filler, uint16_t const offset);
		/** \brief draw horizontal borders
		 * \param start TEXTURE_POSITION
		 * \param filler TEXTURE_POSITION
		 * \param offset uint16_t const
		 */
		void do_drawHBorder(TEXTURE_POSITION start,TEXTURE_POSITION filler, uint16_t const offset);
	private:

	public:
	protected:
		TImage<PhysicObj,object> m_body; //!< body of the window. It don't include borders.
		std::shared_ptr<TTheme<PhysicObj,object> > m_theme; //!< theme of the window
	private:
		bool m_themeChanged;
		bool m_isInit; //!< flag used to check the validity of the window
		std::weak_ptr<TWindow<PhysicObj, object> > m_parent; //!< parent of the window. 0 if it is a modal window. For now, it is higly advised to have only one modal window, as nothing has be implemented against "image riders"
		std::vector<std::shared_ptr<TWindow<PhysicObj, object> > > m_children;
	};

	//implementation
	#include "tpp/twindow.cpp"
}
#endif
