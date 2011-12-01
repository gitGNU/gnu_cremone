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


//! CODE::BLOCKS bugs detected: the 3 following methods are not well managed by doxyblocks
//! Another bug: last line receive tons of spaces
//! Another bug: it make a \param when it see: (void)
//! Another bug: when there are multiple template parameters, they are split in multiple arguments (by example: "type<t1,t2> var"). This bug happend on some the tooltip too.
//! Another bug: when using multiline edit, auto-completion can be launched
//! Another bug: when using multiline edit, undo/redo only affect one line
//! Another bug: when using multiline edit, suppr and backspace only affect one line (only if there is a selection?)
//! Wished feature: make doxyblocks manage the multi-editing
//! Wished feature: recognize Ctor and Dtor

#ifndef TBITMAP_H
#define TBITMAP_H

#include <string>
#include <stdint.h>
#include <memory>

#include "exceptions/file_error.h"
#include "tgraphicobject.h"
#include "tappwindow.h"

namespace TCrem
{
	/**
	 *	\todo (berenger#3#) specify and implement exception-safe
	 *	\todo (berenger#9#) add some logging capabilities
	 *	\todo (berenger#9#) add some debugging capabilities
	 *	\todo (berenger#4#) refactor template parameter names
	 *	\todo (berenger#2#) use only references to smart pointers
	 *	\todo (berenger#3#) implement cast operators? (" sprite::operator const type&(void)")
	 */

	template <typename PhysicObj>
	class TBitmap: public TGraphicObject<PhysicObj>
	{
	public:
		/** \brief Default Ctor */
		TBitmap<PhysicObj>(void) throw();
		/** \brief Ctor */
		TBitmap<PhysicObj>(std::weak_ptr<PhysicObj> bmp) throw();
		/** \brief Dtor */
		virtual ~TBitmap<PhysicObj>(void) throw();

		/** \brief check the validity of the internal ptr
		 * \return bool true if valid, false else
		 */
		bool isValid(void) const throw();

		/** \brief initialise the internal pointer with the given bitmap
		 * \param source std::weak_ptr<PhysicObj> const
		 */
		bool create(std::weak_ptr<PhysicObj> const source) throw();

		/** \brief draw the rectangle (sx,sy,w,h) from itself to the bitmap target, at coordinates (dx,dy)
		 * \param target std::weak_ptr<PhysicObj> const
		 * \param sx=0 int16_t const
		 * \param sy=0 int16_t const
		 * \param w=0 int16_t const
		 * \param h=0 int16_t const
		 * \param dx=0 int16_t const
		 * \param dy=0 int16_t const
		 * \note the bitmap can be the screen
		 * \todo (berenger#5#) make a choice between make it const and remove m_weakSurface or let it as it is actually
		 */
		void draw(std::weak_ptr<PhysicObj> target,int16_t const sx=0, int16_t const sy=0,int16_t const w=0, int16_t const h=0, int16_t const dx=0, int16_t const dy=0) const;
		/** \brief draw the rectangle (sx,sy,w,h) from bitmap source to itself, at coordinates (dx,dy)
		 * \param source std::weak_ptr<PhysicObj> const
		 * \param sx=0 int16_t const
		 * \param sy=0 int16_t const
		 * \param w=0 int16_t const
		 * \param h=0 int16_t const
		 * \param dx=0 int16_t const
		 * \param dy=0 int16_t const
		 * \note the bitmap can be the screen
		 */
		void copy(std::weak_ptr<PhysicObj> const source,int16_t const sx=0, int16_t const sy=0,int16_t const w=0, int16_t const h=0, int16_t const dx=0, int16_t const dy=0);

		/** \brief return the number of bits per pixel of internal bitmap
		 * \return virtual uint8_t
		 */
		virtual uint8_t  getBPP(void) const =0;
		/** \brief return the width of internal bitmap
		 * \return virtual uint16_t
		 */
		virtual uint16_t getW(void) const =0;
		/** \brief return the height of internal bitmap
		 * \return virtual uint16_t
		 */
		virtual uint16_t getH(void) const =0;
		/** \brief return the alpha color mask of internal bitmap
		 * \return virtual uint32_t
		 */
		virtual uint32_t getAMask(void) const =0;
		/** \brief return the blue color mask of internal bitmap
		 * \return virtual uint32_t
		 */
		virtual uint32_t getBMask(void) const =0;
		/** \brief return the red color mask of internal bitmap
		 * \return virtual uint32_t
		 */
		virtual uint32_t getRMask(void) const =0;
		/** \brief return the green color mask of internal bitmap
		 * \return virtual uint32_t
		 */
		virtual uint32_t getGMask(void) const =0;
		/** \brief return flags used to create the internal bitmap
		 * \return virtual uint32_t
		 */
		virtual uint32_t getFlags(void) const =0;

		/** \brief create a bitmap from another one
		 * \param source object const&
		 */
		virtual void create(TBitmap<PhysicObj> const &source)=0;
		/** \brief create a bitmap from an image file
		 * \throw File_error on error
		 * \param file std::string const&
		 */
		virtual void create(std::string const &file)=0;
		/** \brief create a bitmap by specifying its characteristics
		 * \param w const uint16_t
		 * \param h const uint16_t
		 * \param bpp const uint8_t
		 * \param rmask const uint32_t
		 * \param gmask const uint32_t
		 * \param bmask const uint32_t
		 * \param amask const uint32_t
		 * \param flags const uint32_t
		 */
		virtual void create(const uint16_t w, const uint16_t h, const uint8_t bpp, const uint32_t rmask,const uint32_t gmask, const uint32_t bmask,const uint32_t amask,const uint32_t flags)=0;

		/** \brief save the internal bitmap to a file
		 * \param file std::string const&
		 */
		virtual void save(std::string const & file)const=0;

	protected:
		/** \brief Draw the rectangle (x,y,x,h) from source at coordinates (dx,dy) of destination
		 * \param source std::weak_ptr<PhysicObj> bitmap from which the image will be taken
		 * \param destination std::weak_ptr<PhysicObj> bitmap on which the image will be draw
		 * \param x const uint16_t
		 * \param y const uint16_t
		 * \param w const uint16_t
		 * \param h const uint16_t
		 * \param dx const uint16_t
		 * \param dy const uint16_t
		 * \note the bitmap can be the screen
		 * \todo (berenger#5#): find a way to force it to be implemented and have it static
		 */
		virtual void blitSurface(std::weak_ptr<PhysicObj> const source, std::weak_ptr<PhysicObj> destination, const uint16_t x,const uint16_t y,const uint16_t w,const uint16_t h, const uint16_t dx, const uint16_t dy)const =0;
	private:

	public:
	protected:
	private:
	};

	//implementations
	#include "tpp/tbitmap.cpp"
}
#endif // TBITMAP_H
