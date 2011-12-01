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

template <typename PhysicObj>
TGraphicObject<PhysicObj>::TGraphicObject(void) throw()
:m_bpp(DEFAULT_BPP),m_width(DEFAULT_WIDTH),m_height(DEFAULT_HEIGHT),m_graphicalObject()
{
}

template <typename PhysicObj>
TGraphicObject<PhysicObj>::TGraphicObject(uint16_t _width, uint16_t _height, uint8_t _bpp) throw()
:m_bpp(_bpp),m_width(_width),m_height(_height),m_graphicalObject()
{
}

template <typename PhysicObj>
TGraphicObject<PhysicObj>::TGraphicObject(std::weak_ptr<PhysicObj> bmp) throw()
:m_graphicalObject(bmp)
{
}

template <typename PhysicObj>
TGraphicObject<PhysicObj>::~TGraphicObject(void) throw()
{
}

template <typename PhysicObj>
std::weak_ptr<PhysicObj> TGraphicObject<PhysicObj>::getBitmap(void) const throw()
{
	return m_graphicalObject;
}


template <typename PhysicObj>
TGraphicObject<PhysicObj>& TGraphicObject<PhysicObj>::width(uint16_t _width)
{
    m_width=_width;return *this;
}

template <typename PhysicObj>
TGraphicObject<PhysicObj>& TGraphicObject<PhysicObj>::height(uint16_t _height)
{
    m_height=_height;return *this;
}

template <typename PhysicObj>
TGraphicObject<PhysicObj>& TGraphicObject<PhysicObj>::bpp(uint8_t _bpp)
{
    m_bpp=_bpp;return *this;
}
