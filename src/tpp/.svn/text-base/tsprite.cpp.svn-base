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

template<typename PhysicObj,typename object>
TSprite<PhysicObj,object>::TSprite(void) throw()
:m_sprite(),m_weakTarget(),m_shadow(),m_isDraw(false),m_spriteX(),m_spriteY(),m_shadowX(),m_shadowY()
{
}

//template<typename PhysicObj,typename object>
//__sprite<PhysicObj,object>::__sprite(__sprite<PhysicObj,object> const &src) throw()
//:m_isDraw(false), m_shadow(),m_sprite(src.m_sprite),m_spriteX(src.m_x),m_spriteY(src.m_y)
//{
//}

template<typename PhysicObj,typename object>
TSprite<PhysicObj,object>::~TSprite()
{
	clear();
}

template<typename PhysicObj,typename object>
bool TSprite<PhysicObj,object>::getIsDrawed()const throw()
{
	return m_isDraw;
}

template<typename PhysicObj,typename object>
void TSprite<PhysicObj,object>::clear(void)
{
	if(m_isDraw)
		m_shadow.draw(m_weakTarget,m_shadowX,m_shadowY);
	m_isDraw=false;
}

template<typename PhysicObj,typename object>
void TSprite<PhysicObj,object>::draw(std::weak_ptr<PhysicObj> &target)
{
//	//first verify if image is set
	if(!m_sprite.isValid())
		return;// false;
//	//clear the sprite BEFORE changing the screen
//	if(!clear())
//		return false;
	clear();

	m_weakTarget=target;
	if(m_weakTarget.expired())
		return;// false;

	m_shadowX=m_spriteX;
	m_shadowY=m_spriteY;

	//if the shadow does not exist or is not of the same size as the sprite, create one of the same size
	if(!m_shadow.isValid())
		m_shadow.create(m_sprite);
	if(m_shadow.getH()!=m_sprite.getH() || m_shadow.getW()!=m_sprite.getW())
		m_shadow.create(m_sprite);
	m_shadow.copy(m_weakTarget,m_shadowX,m_shadowY);
	m_sprite.draw(m_weakTarget,m_spriteX,m_spriteY);
	m_isDraw=true;
	return ;
}

template<typename PhysicObj,typename object>
void TSprite<PhysicObj,object>::move(const int16_t x, const int16_t y) throw()
{
	m_spriteX=x;
	m_spriteY=y;
}

template<typename PhysicObj,typename object>
void TSprite<PhysicObj,object>::set(TImage<PhysicObj,object> const &val) throw()
{
	m_sprite = val;
}
