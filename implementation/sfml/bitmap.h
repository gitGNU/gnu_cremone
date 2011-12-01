#ifndef HEADER_8D5C5BE9E7AC7A3B
#define HEADER_8D5C5BE9E7AC7A3B

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

#ifndef __sdlbitmap_H
#define __sdlbitmap_H

#include <memory>

#include <SFML/Window.hpp>
#include <bitmap.h>

// FIXME (berenger#1#): implement exceptions

class sfml_bitmap:public TBitmap<sfml_Surface>
{
	friend class TBitmap<sfml_Surface>;
	public:
		sfml_bitmap();

		uint8_t getBPP(void)const;
		uint16_t getW(void)const;
		uint16_t getH(void)const;
		uint32_t getAMask(void)const;
		uint32_t getBMask(void)const;
		uint32_t getRMask(void)const;
		uint32_t getGMask(void)const;
		uint32_t getFlags(void)const;

		void create(std::string const &file);
		void create(__bitmap<sfml_Surface> const &source);
		void create(const uint16_t w, const uint16_t h, const uint8_t bpp, const uint32_t rmask,const uint32_t gmask, const uint32_t bmask,const uint32_t amask,const uint32_t flags);

		void save(std::string const & file) const;
	protected:
		void free(sfml_Surface *ptr);
		void blitSurface(std::weak_ptr<sfml_Surface> const source, std::weak_ptr<sfml_Surface> destination, const uint16_t x,const uint16_t y,const uint16_t w,const uint16_t h, const uint16_t dx, const uint16_t dy)const;
	private:
};

#endif // __sfml_bitmap_H

#endif // header guard
