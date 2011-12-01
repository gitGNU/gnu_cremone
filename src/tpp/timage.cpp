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

#include "exceptions/file_error.h"

template <typename PhysicObj, typename object>
TImage<PhysicObj,object>::TImage(void) throw()
:m_texture()
{
}

template <typename PhysicObj, typename object>
TImage<PhysicObj,object>::TImage(std::string const &file)
:m_texture()
{
	load(file);
}

template <typename PhysicObj, typename object>
TImage<PhysicObj,object>::~TImage(void) throw()
{
}

template <typename PhysicObj, typename object>
void TImage<PhysicObj,object>::load(std::string const &file)
{
    static typename std::map<std::string, std::weak_ptr<PhysicObj> > s_openedFiles; //!< \todo (berenger#1#) determine if I should move it to __bitmap<t1,t2>. I have to find a way to make it static too. list of opened files. It is used to avoid disk access by keeping in memory bitmaps loaded from files.
//	if(s_openedFiles.count(file))
//	{
//		__bitmap<PhysicObj,object> tmp(s_openedFiles[file]);
//		m_texture.create(tmp);
//	}
//	else
//	{
		m_texture.create(file);
		s_openedFiles[file]=m_texture.getBitmap();
//	}
}

template <typename PhysicObj, typename object>
void TImage<PhysicObj,object>::save(std::string const &file) const throw()
{
	m_texture.save(file);
}

template <typename PhysicObj, typename object>
void TImage<PhysicObj,object>::draw(std::weak_ptr<PhysicObj> &target,const int16_t x, const int16_t y) const
{
	m_texture.draw(target,x, y);
}

template <typename PhysicObj, typename object>
void TImage<PhysicObj,object>::copy(std::weak_ptr<PhysicObj> &source,const int16_t x, const int16_t y)
{
	m_texture.copy(source,x, y);
}

template <typename PhysicObj, typename object>
void TImage<PhysicObj,object>::create(const uint16_t w, const uint16_t h, const uint8_t bpp, const uint32_t rmask,const uint32_t gmask, const uint32_t bmask,const uint32_t amask,const uint32_t flags)
{
	m_texture.create(w,h,bpp,rmask,gmask,bmask,amask,flags);
}

template <typename PhysicObj, typename object>
void TImage<PhysicObj,object>::create(TImage<PhysicObj,object> const &source)
{
	m_texture.create(source.m_texture);
}

template <typename PhysicObj, typename object>
bool TImage<PhysicObj,object>::isValid(void)const throw()
{
	return m_texture.isValid();
}

template <typename PhysicObj, typename object>
std::weak_ptr<PhysicObj> TImage<PhysicObj,object>::getBitmap(void) const throw()
{
	return m_texture.getBitmap();
}

template <typename PhysicObj, typename object>
uint16_t TImage<PhysicObj,object>::getW(void)const
{
	return m_texture.getW();
}

template <typename PhysicObj, typename object>
uint16_t TImage<PhysicObj,object>::getH(void)const
{
	return m_texture.getH();
}

template <typename PhysicObj, typename object>
uint8_t TImage<PhysicObj,object>::getBPP(void)const
{
	return m_texture.getBPP();
}

template <typename PhysicObj, typename object>
uint32_t TImage<PhysicObj,object>::getRMask(void)const
{
	return m_texture.getRMask();
}

template <typename PhysicObj, typename object>
uint32_t TImage<PhysicObj,object>::getGMask(void)const
{
	return m_texture.getGMask();
}

template <typename PhysicObj, typename object>
uint32_t TImage<PhysicObj,object>::getBMask(void)const
{
	return m_texture.getBMask();
}

template <typename PhysicObj, typename object>
uint32_t TImage<PhysicObj,object>::getAMask(void)const
{
	return m_texture.getAMask();
}

template <typename PhysicObj, typename object>
uint32_t TImage<PhysicObj,object>::getFlags(void)const
{
	return m_texture.getFlags();
}
