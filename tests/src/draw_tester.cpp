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

#include "draw_tester.h"
#include <UnitTest++.h>

//NOTE (berenger#1#) utiliser un callback sur fonction classique pour vider le pointeur de SDL_Surface*

using namespace crem;

draw_tester::draw_tester()
: m_scr()
{
	SDL_Init( 0 );
}

draw_tester::~draw_tester()
{
	SDL_Quit();
}


TEST( LoadBmpNonExistingFile )
{
	crem::Image img;
	img.load("failure.bmp");
}

TEST( LoadBmpExistingFile )
{
	crem::Image img;
	img.load( RESSOURCES_DIRECTORY"test.bmp" );
}

TEST_FIXTURE( draw_tester, ScreenFixinit )
{
	crem::Image img;
	m_scr.height(600).width(400).bpp(32);
	m_scr.init();
	m_ws=m_scr.getBitmap();
	img.load( RESSOURCES_DIRECTORY"test.bmp" );
	img.draw(m_ws,0,0);
	m_scr.refresh();
}

TEST_FIXTURE( draw_tester, CopyScreen )
{
	/*
	CHECK( m_scr.init( 800, 600, 32, m_flags ) );
	crem::Image bg;
	bg.loadFile(RESSOURCES_DIRECTORY"background.bmp");
	bg.draw(&m_scr,0,0);
	CHECK( m_scr.refresh() );
	sleep(3);

    sdl_bitmap sprite1,sprite2;
    sprite1.create(RESSOURCES_DIRECTORY"test.bmp");
	sprite2.create(sprite1);

	SDL_Rect pos={0,0,0,0}, dir={1,1,0,0};

	sprite2.copyScreen(30,30,&m_scr);
	sprite2.drawScreen(30,30,&m_scr);
	CHECK( m_scr.refresh() );
	sleep(3);

	sprite2.copyScreen(30,30,&m_scr);
	sprite1.drawScreen(30,30,&m_scr);
	CHECK( m_scr.refresh() );
	sleep(3);

	sprite2.drawScreen(30,30,&m_scr);
	CHECK( m_scr.refresh() );
	sleep(3);
 */ /*
	crem::Image img, i2;
	i2.loadFile(RESSOURCES_DIRECTORY"test.bmp");
	img.clone(i2);

SDL_Rect p={0,0,0,0},d={0,0,0,0};
p.x=30;p.y=30;
SDL_Surface *sc=m_scr.getBitmap().lock().get();
SDL_Surface *ds=img.m_texture.m_surface.get();
SDL_BlitSurface(sc,&p,ds,&d);


//	img.copy(&m_scr,30,30);
	i2.draw(&m_scr,30,30);
	CHECK( m_scr.refresh() );
	sleep(3);

	CHECK( img.draw(&m_scr,30,30) );
	CHECK( m_scr.refresh() );
	sleep(1);
	img.saveFile(RESSOURCES_DIRECTORY"test_out.bmp");
	*/
}

TEST_FIXTURE( draw_tester, ShowSpriteAutoinit )
{
	/*
	CHECK( m_scr.setBestMode( m_flags ) );
	crem::Image bg;
	bg.loadFile(RESSOURCES_DIRECTORY"background.bmp");
	bg.draw(&m_scr,0,0);
	CHECK( m_scr.refresh() );
	sleep(1);

	crem::Image img;
	CHECK(img.load( RESSOURCES_DIRECTORY"test.bmp" ) );
	Sprite spr;
	spr.setSprite( img );

	spr.move(30,30);
	CHECK( spr.draw(&m_scr) );
	CHECK( m_scr.refresh() );
	sleep(1);

	spr.move(50,50);
	CHECK( spr.draw(&m_scr) );
	CHECK( m_scr.refresh() );
	sleep(1);

	CHECK( spr.clear() );
	CHECK( m_scr.refresh() );
	sleep(1);
	*/
//////////////////////////////////////////////////////
    atexit(SDL_Quit);

	AppWindow screen;
	screen.init( 640, 480, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);

	m_ws=screen.getBitmap();

	crem::Image bg1,img;
	bg1.load(RESSOURCES_DIRECTORY"background.bmp");
	bg1.draw(m_ws,0,0);

	Sprite sprite;

	img.load(RESSOURCES_DIRECTORY"cb.bmp");
	img.load(RESSOURCES_DIRECTORY"test2.bmp");
	sprite.set(img);


	sprite.move(40,40);

	sprite.draw(m_ws);
	screen.refresh();
	SDL_Delay(1000);



	sprite.move(100,100);

	sprite.draw(m_ws);
	screen.refresh();
	SDL_Delay(1000);

}
