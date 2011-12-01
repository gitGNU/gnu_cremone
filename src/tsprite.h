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

#ifndef TSPRITE_H
#define TSPRITE_H

#include "timage.h"

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

	template <typename PhysicObj,typename object>
	class TSprite
	{
	public:
		/** \brief Ctor */
		TSprite(void) throw();
	//	/** \brief Ctor: use a sprite to initialise
	//	 *	\param src __sprite<PhysicObj,object> const &
	//	 */
	//	__sprite(__sprite<PhysicObj,object> const &src) throw();
		/** \brief Dtor
		 *	\warning because a sprite have to be cleared before deleted, this destructor could throw an exception!!!
		 */
		virtual ~TSprite();

		/** \brief allow to know if the sprite is drawed
		 * \return bool
		 */
		bool getIsDrawed(void)const throw();
		/** \brief set the image of the sprite
		 * \param val __image<PhysicObj,object> const&
		 */
		void set(TImage<PhysicObj,object> const &val) throw();
		/** \brief draw the sprite on the given image
		 * \param target std::weak_ptr<PhysicObj>&
		 */
		void draw(std::weak_ptr<PhysicObj> &target);
		/** \brief remove the sprite of the given image
		 * the removing is made by drawing what was at this place before the sprite
		 */
		void clear(void);
		/** \brief change the position of the future draw */
		void move(const int16_t x, const int16_t y) throw();
	protected:
	private:

	public:
	protected:
		TImage<PhysicObj,object> m_sprite; //!< image of the sprite
		std::weak_ptr<PhysicObj> m_weakTarget; //!< weak ptr of the image where the sprite is drawed and where the sprite will be cleared
	private:
		TImage<PhysicObj,object> m_shadow; //!< snapshot of what was behind the sprite
		bool m_isDraw; //!< flag to remember if the sprite is drawed or not
		uint16_t m_spriteX,m_spriteY; //!< coordinates where the sprite will be drawed next time.
		uint16_t m_shadowX,m_shadowY; //!< coordinates of drawed sprite
	};

	//implementations
	#include "tpp/tsprite.cpp"
}
#endif // SPRITE_H
