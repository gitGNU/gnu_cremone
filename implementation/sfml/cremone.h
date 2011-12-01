#ifndef HEADER_3FAA47EC2B3AA2CA
#define HEADER_3FAA47EC2B3AA2CA

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

#ifndef sfml_CREMONE
#define sfml_CREMONE

#include <SFML/Window.hpp>
#include <sprite.h>
#include <image.h>
#include <window.h>
#include <event.h>

#include "sfml_bitmap.h"
#include "sfml_screen.h"

#include "sfml_eventmanager.h"

typedef __image<sfml_Surface,sfml_bitmap> sfml_image;
typedef __sprite<sfml_Surface,sfml_bitmap> sfml_sprite;
typedef __window<sfml_Surface,sfml_bitmap> sfml_window;
typedef __theme<sfml_Surface,sfml_bitmap> sfml_theme;

#endif

#endif // header guard
