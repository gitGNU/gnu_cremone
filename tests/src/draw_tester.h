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

#ifndef DRAWTESTER_H
#define DRAWTESTER_H

#include <string>

#include <cremone.h>
#include <exception>

#define RESSOURCES_DIRECTORY "../rsc/"

class draw_tester
{
public:
	draw_tester();
	virtual ~draw_tester();

	bool LoadGoodFile( void );
	crem::AppWindow m_scr;
	std::weak_ptr<SDL_Surface> m_ws;
protected:
private:
};

#endif // DRAWTESTER_H
