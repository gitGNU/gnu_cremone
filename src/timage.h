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

#ifndef TIMAGE_H
#define TIMAGE_H

#include <string>
#include <map>

#include "bitmap.h"

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

	template <typename PhysicObj, typename object>
	class TImage
	{
	public:
		/** \brief Std Ctor */
		TImage(void) throw();
		/** \brief Ctor: initialize the image with the image in the given file
		 * \param file std::string const &
		 */
		TImage(std::string const &file);

		/** \brief Std Dtor */
		~TImage(void) throw();

		/** \brief replace the image by the one contained in the given file
		 * \param file std::string const&
		 */
		void load(std::string const &file);
		/** \brief save the image in the given file
		 * \param file std::string const&
		 */
		void save(std::string const &file) const throw();

		/** \brief draw itself on the given bitmap
		 *
		 * \param target std::weak_ptr<PhysicObj>&
		 * \param x const int16_t
		 * \param y const int16_t
		 * \note the bitmap can be the screen
		 */
		void draw(std::weak_ptr<PhysicObj> &target,const int16_t x, const int16_t y) const;
		/** \brief copy the content of the given image
		 *
		 * \param target std::weak_ptr<PhysicObj>&
		 * \param x const int16_t
		 * \param y const int16_t
		 * \note the bitmap can be the screen
		 * \note no resizing is done
		 */
		void copy(std::weak_ptr<PhysicObj> &target,const int16_t x, const int16_t y);

		/** \brief return the internal bitmap
		 * \return std::weak_ptr<PhysicObj>
		 */
		std::weak_ptr<PhysicObj> getBitmap(void) const throw();

		/** \brief create an image with given parameters
		 * \param w const uint16_t width
		 * \param h const uint16_t height
		 * \param bpp const uint8_t bits per pixel
		 * \param rmask const uint32_t red mask
		 * \param gmask const uint32_t green mask
		 * \param bmask const uint32_t blue mask
		 * \param amask const uint32_t alpha mask (transparency)
		 * \param flags const uint32_t flags
		 */
		void create(const uint16_t w, const uint16_t h, const uint8_t bpp, const uint32_t rmask,const uint32_t gmask, const uint32_t bmask,const uint32_t amask,const uint32_t flags);
		/** \brief create an image with same characteristics than the one given
		 * \param source __image<PhysicObj, object> const&
		 */
		void create(TImage<PhysicObj,object> const &source);
		/** \brief return image's width
		 * \return uint16_t
		 */
		uint16_t getW(void)const;
		/** \brief return image's height
		 * \return uint16_t
		 */
		uint16_t getH(void)const;
		/** \brief return image's depth
		 * \return uint8_t
		 */
		uint8_t getBPP(void)const;
		/** \brief return image's red color mask
		 * \return uint32_t
		 */
		uint32_t getRMask(void)const;
		/** \brief return image's green color mask
		 * \return uint32_t
		 */
		uint32_t getGMask(void)const;
		/** \brief return image's blue color mask
		 * \return uint32_t
		 */
		uint32_t getBMask(void)const;
		/** \brief return image's alpha (transparency) color mask
		 * \return uint32_t
		 */
		uint32_t getAMask(void)const;
		/** \brief return image's flags
		 * \return uint32_t
		 */
		uint32_t getFlags(void)const;
		/** \brief return the state of the internal bitmap
		 * \return bool true if image is valid
		 */
		bool isValid(void)const throw();
	protected:
	private:

	public:
	protected:
	private:
		object m_texture; //!< \todo remove me. Contained image.
	};

	//definitions
	#include "tpp/timage.cpp"
}
#endif
