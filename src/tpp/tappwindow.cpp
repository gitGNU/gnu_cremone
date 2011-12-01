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
TAppWindow<PhysicObj>::TAppWindow(void) throw()
:TGraphicObject<PhysicObj>(DEFAULT_WIDTH,DEFAULT_HEIGHT,DEFAULT_BPP),m_fullscreen(false),m_title(),m_icon()
{
}

template <typename PhysicObj>
TAppWindow<PhysicObj>::~TAppWindow(void) throw()
{
}

template <typename PhysicObj>
void TAppWindow<PhysicObj>::free(PhysicObj *ptr)
{
	return;
}

template <typename PhysicObj>
void TAppWindow<PhysicObj>::set(PhysicObj* surface)
{
	this->m_graphicalObject=std::shared_ptr<PhysicObj> (surface,std::bind1st(std::mem_fun(&TAppWindow::free),this));
}

template <typename PhysicObj>
TAppWindow<PhysicObj>& TAppWindow<PhysicObj>::fullscreen(bool const enable)
{
    m_fullscreen=enable;return *this;
}

template <typename PhysicObj>
TAppWindow<PhysicObj>& TAppWindow<PhysicObj>::title(std::string const &_title)
{
    m_title=title;return *this;
}

template <typename PhysicObj>
TAppWindow<PhysicObj>& TAppWindow<PhysicObj>::winIcon(std::weak_ptr<TGraphicObject<PhysicObj> > const icon)
{
    m_icon=icon;return *this;
}
