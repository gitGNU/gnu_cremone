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

#include "bitmap.h"
#include <stdexcept>

namespace crem
{

	Bitmap::Bitmap():TBitmap<SDL_Surface>()
	{
	}

	uint16_t Bitmap::getW(void)const
	{
		return m_graphicalObject->w;
	}

	uint16_t Bitmap::getH(void)const
	{
		return m_graphicalObject->h;
	}

	uint8_t Bitmap::getBPP(void)const
	{
		return m_graphicalObject->format->BitsPerPixel;
	}

	uint32_t Bitmap::getAMask(void)const
	{
		return m_graphicalObject->format->Amask;
	}

	uint32_t Bitmap::getBMask(void)const
	{
		return m_graphicalObject->format->Bmask;
	}

	uint32_t Bitmap::getRMask(void)const
	{
		return m_graphicalObject->format->Rmask;
	}

	uint32_t Bitmap::getGMask(void)const
	{
		return m_graphicalObject->format->Gmask;
	}

	uint32_t Bitmap::getFlags(void)const
	{
		return m_graphicalObject->flags;
	}

	void Bitmap::blitSurface(std::weak_ptr<SDL_Surface> const source
							, std::weak_ptr<SDL_Surface> destination
							, const uint16_t x,const uint16_t y
							, const uint16_t w,const uint16_t h
							, const uint16_t dx, const uint16_t dy)const
	{
		SDL_Rect src,dst;
		src.x=x;src.y=y;src.w=w;src.h=h;
		dst.x=dx;dst.y=dy;

		int8_t ret=SDL_BlitSurface(source.lock().get(),&src,destination.lock().get(),&dst);

		switch(ret)
		{
		default:
		case -1:
		case -2:
			throw std::runtime_error(SDL_GetError());
		case 0:
			break;
		}
	}

	void Bitmap::create(TBitmap<SDL_Surface> const &source)
	{
	//TODO (berenger#9#) optimize by using SDL_CreateRGBSurfaceFrom()
		create(source.getW(),source.getH(),source.getBPP(),source.getRMask(),source.getGMask(),source.getBMask(),source.getAMask(),source.getFlags());
	}

	void Bitmap::create(const uint16_t w, const uint16_t h, const uint8_t _bpp, const uint32_t rmask,const uint32_t gmask, const uint32_t bmask,const uint32_t amask,const uint32_t flags)
	{
		m_graphicalObject.reset(SDL_CreateRGBSurface(flags, w, h, _bpp, rmask, gmask, bmask, amask),&SDL_FreeSurface);
		if(!m_graphicalObject.get())
			throw std::runtime_error("Problem while creating surface");
	}

	void Bitmap::create(std::string const &file)
	{
		m_graphicalObject.reset(SDL_LoadBMP(file.c_str()),&SDL_FreeSurface);
		if(!m_graphicalObject.get())
			throw File_error(CantRead,file,SDL_GetError());
	}

	void Bitmap::save(std::string const & file) const
	{
		if(SDL_SaveBMP(m_graphicalObject.get(),file.c_str()))
			throw File_error(CantWrite,file,SDL_GetError());
	}
}
