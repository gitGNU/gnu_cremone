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

#ifndef TGRAPHIC_OBJECT_H
#define TGRAPHIC_OBJECT_H

#include <memory>

namespace TCrem
{
	#define DEFAULT_WIDTH   640
	#define DEFAULT_HEIGHT  400
	#define DEFAULT_BPP     8

	template <typename PhysicObj>
	class TGraphicObject
	{
	public:
		/** \brief Ctor */
		TGraphicObject(void) throw();
		/** \brief Ctor */
		TGraphicObject(uint16_t _width, uint16_t _height=DEFAULT_HEIGHT, uint8_t _bpp=DEFAULT_BPP) throw();
		/** \brief Ctor */
		TGraphicObject(std::weak_ptr<PhysicObj> bmp) throw();
		/** Ctor */
		virtual ~TGraphicObject(void) throw();
		/** \brief return the internal bitmap
		 * \return std::weak_ptr<PhysicObj>
		 */
		std::weak_ptr<PhysicObj> getBitmap(void) const throw();

		TGraphicObject<PhysicObj>& width(uint16_t _width=DEFAULT_WIDTH);
		TGraphicObject<PhysicObj>& height(uint16_t _height=DEFAULT_HEIGHT);
		TGraphicObject<PhysicObj>& bpp(uint8_t _bpp=DEFAULT_BPP);
	protected:
	//	virtual void free(PhysicObj *ptr)=0;
	// think about using a static callback or a virtual pure method free?
	private:

	public:
	protected:
		uint8_t m_bpp;
		uint16_t m_width, m_height;
		std::shared_ptr<PhysicObj> m_graphicalObject;
	private:
	};

	#include "tpp/tgraphicobject.cpp"
}
#endif
