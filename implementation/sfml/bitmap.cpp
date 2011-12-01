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

#include "Bitmap.h"

namespace crem
{

	Bitmap::Bitmap():TBitmap<sfml_Surface>()
	{
	}

	uint16_t Bitmap::getW(void)const
	{
		return this->m_graphicalObject->w;
	}

	uint16_t Bitmap::getH(void)const
	{
		return this->m_graphicalObject->h;
	}

	uint8_t Bitmap::getBPP(void)const
	{
		return this->m_graphicalObject->format->BitsPerPixel;
	}

	uint32_t Bitmap::getAMask(void)const
	{
		return this->m_graphicalObject->format->Amask;
	}

	uint32_t Bitmap::getBMask(void)const
	{
		return this->m_graphicalObject->format->Bmask;
	}

	uint32_t Bitmap::getRMask(void)const
	{
		return this->m_graphicalObject->format->Rmask;
	}

	uint32_t Bitmap::getGMask(void)const
	{
		return this->m_graphicalObject->format->Gmask;
	}

	uint32_t Bitmap::getFlags(void)const
	{
		return this->m_graphicalObject->flags;
	}

	void Bitmap::blitSurface(std::weak_ptr<sfml_Surface> const source, std::weak_ptr<sfml_Surface> destination, const uint16_t x,const uint16_t y,const uint16_t w,const uint16_t h, const uint16_t dx, const uint16_t dy)const
	{
		sfml_Rect src,dst;
		src.x=x;src.y=y;src.w=w;src.h=h;
		dst.x=dx;dst.y=dy;dst.w=0;dst.h=0;

		int8_t ret=sfml_BlitSurface(source.lock().get(),&src,destination.lock().get(),&dst);
		if(ret!=0)
		{
			char *t=sfml_GetError();
			printf("erreur sdl: %s\n",t);
		}

		switch(ret)
		{
		case 0:
			return;//no error
		default:
		case -1:
			;// FIXME (berenger#7#): implement me
		case -2:
			;// FIXME (berenger#7#): implement me
		}
	}

	void Bitmap::create(__bitmap<sfml_Surface> const &source)
	{
	//TODO (berenger#7#) optimize by using sfml_CreateRGBSurfaceFrom()
		this->m_graphicalObject.reset(sfml_CreateRGBSurface(source.getFlags(),source.getW(),source.getH(),source.getBPP(),source.getRMask(),source.getGMask(),source.getBMask(),source.getAMask()),&sfml_FreeSurface);
	}

	void Bitmap::create(const uint16_t w, const uint16_t h, const uint8_t bpp, const uint32_t rmask,const uint32_t gmask, const uint32_t bmask,const uint32_t amask,const uint32_t flags)
	{
		this->m_graphicalObject.reset(sfml_CreateRGBSurface(flags, w, h, bpp, rmask, gmask, bmask, amask),&sfml_FreeSurface);
	}

	void Bitmap::create(std::string const &file)
	{
		this->m_graphicalObject.reset(sfml_LoadBMP(file.c_str()),&sfml_FreeSurface);
	}

	void Bitmap::save(std::string const & file) const
	{
		if(sfml_SaveBMP(this->m_graphicalObject.get(),file.c_str()))
			{;}// FIXME (berenger#7#): implement me
	}
}
