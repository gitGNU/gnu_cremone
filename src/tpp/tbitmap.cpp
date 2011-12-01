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
TBitmap<PhysicObj>::TBitmap(void) throw()
:TGraphicObject<PhysicObj>()
{
}

template <typename PhysicObj>
TBitmap<PhysicObj>::TBitmap(std::weak_ptr<PhysicObj> bmp) throw()
:TGraphicObject<PhysicObj>(bmp)
{
}

template <typename PhysicObj>
TBitmap<PhysicObj>::~TBitmap<PhysicObj>(void) throw()
{
}

template <typename PhysicObj>
bool TBitmap<PhysicObj>::create(std::weak_ptr<PhysicObj> const bmp) throw()
{
	this->m_graphicalObject=bmp.lock();
	return true;
}

template <typename PhysicObj>
void TBitmap<PhysicObj>::draw(std::weak_ptr<PhysicObj> target,int16_t const sx, int16_t const sy,int16_t const w, int16_t const h, int16_t const dx, int16_t const dy) const
{
	blitSurface(this->m_graphicalObject, target,dx,dy,!w?getW():w,!h?getH():h,sx,sy);
}

template <typename PhysicObj>
void TBitmap<PhysicObj>::copy(std::weak_ptr<PhysicObj> const source,int16_t sx, int16_t sy,int16_t w, int16_t h, int16_t dx, int16_t dy)
{
	blitSurface(source, this->m_graphicalObject,sx,sy,!w?getW():w,!h?getH():h,dx,dy);
}

template <typename PhysicObj>
bool TBitmap<PhysicObj>::isValid(void) const throw()
{
	return this->m_graphicalObject.use_count();
}
