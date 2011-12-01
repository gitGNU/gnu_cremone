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

#include <UnitTest++.h>
#include <cremone.h>

const uint32_t flags=SDL_SWSURFACE;

using namespace crem;

TEST( sdl_bitmap_getBPP )
{
	Bitmap test;
	test.create(250,340,32,0xeeeeeeee,0xdddddddd,0xcccccccc,0xbbbbbbbb,flags);
	CHECK_EQUAL(test.getBPP(),32);
}

TEST( sdl_bitmap_getW )
{
	Bitmap test;
	test.create(250,340,32,0xeeeeeeee,0xdddddddd,0xcccccccc,0xbbbbbbbb,flags);
	CHECK_EQUAL(test.getW(),250);
}

TEST( sdl_bitmap_getH )
{
	Bitmap test;
	test.create(250,340,32,0xeeeeeeee,0xdddddddd,0xcccccccc,0xbbbbbbbb,flags);
	CHECK_EQUAL(test.getH(),340);
}

TEST( sdl_bitmap_getAMask )
{
	Bitmap test;
	test.create(250,340,32,0xeeeeeeee,0xdddddddd,0xcccccccc,0xbbbbbbbb,flags);
	CHECK_EQUAL(test.getAMask(),0xbbbbbbbb);
}

TEST( sdl_bitmap_getRMask )
{
	Bitmap test;
	test.create(250,340,32,0xeeeeeeee,0xdddddddd,0xcccccccc,0xbbbbbbbb,flags);
	CHECK_EQUAL(test.getRMask(),0xeeeeeeee);
}

TEST( sdl_bitmap_getGMask )
{
	Bitmap test;
	test.create(250,340,32,0xeeeeeeee,0xdddddddd,0xcccccccc,0xbbbbbbbb,flags);
	CHECK_EQUAL(test.getGMask(),0xdddddddd);
}

TEST( sdl_bitmap_getBMask )
{
	Bitmap test;
	test.create(250,340,32,0xeeeeeeee,0xdddddddd,0xcccccccc,0xbbbbbbbb,flags);
	CHECK_EQUAL(test.getBMask(),0xcccccccc);
}

TEST( sdl_bitmap_getFlags )
{
	AppWindow s;
	s.setBestMode(flags);
	Bitmap test;
	test.create(250,340,32,0xeeeeeeee,0xdddddddd,0xcccccccc,0xbbbbbbbb,flags);
	CHECK_EQUAL(test.getFlags(),flags);
}

