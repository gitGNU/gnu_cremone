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

#include "appwindow.h"

namespace crem
{
	void AppWindow::init( const uint16_t width_, const uint16_t height_, const uint8_t bpp_)
	{
		TGraphicObject<sf::RenderWindow>::m_bpp=bpp_;
		TGraphicObject<sf::RenderWindow>::m_width=width_;
		TGraphicObject<sf::RenderWindow>::m_height=height_;
		init();
	}

	void AppWindow::init(void)
	{
		if(!(m_width && m_height && m_bpp))
			setBestMode();
		else
			m_graphicalObject->Create(sf::VideoMode(m_width,m_height,m_bpp),m_title);
	}

	void AppWindow::setBestMode()
	{
		sf::VideoMode mode=sf::VideoMode::GetMode(0);
		init(mode.Width,mode.Height,mode.BitsPerPixel);
	}

	void AppWindow::refresh(void)
	{
		m_graphicalObject->Display();
	}
}
