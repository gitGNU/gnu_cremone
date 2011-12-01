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

template <typename PhysicObj, typename object>
TWindow<PhysicObj,object>::TWindow(void)
:TSprite<PhysicObj,object>(),m_body(),m_theme(),m_themeChanged(true),m_isInit(false),m_parent(0),m_children()
{
	set();
}

template <typename PhysicObj, typename object>
TWindow<PhysicObj,object>::TWindow(std::weak_ptr<TTheme<PhysicObj,object> > const theme, TImage<PhysicObj, object> const &img)
:TSprite<PhysicObj,object>(),m_body(),m_theme(),m_themeChanged(true),m_isInit(false),m_parent(),m_children()
{
	set();
	set(theme);
	set(img);
}

template <typename PhysicObj, typename object>
TWindow<PhysicObj,object>::~TWindow(void)
{
}

template <typename PhysicObj, typename object>
void TWindow<PhysicObj,object>::set(const TImage<PhysicObj,object> &image)
{
	//if body size have changed, borders (so: theme) will need to be redrawed
	if(m_body.isValid())
		if(image.getH()!=m_body.getH() || image.getW()!=m_body.getW())
			m_themeChanged=true;
	set();
	m_body=image;
}

template <typename PhysicObj, typename object>
void TWindow<PhysicObj,object>::set(const std::weak_ptr<TTheme<PhysicObj,object> > theme)
{
	m_themeChanged=true;
	set();
	m_theme=theme.lock();
}

template <typename PhysicObj, typename object>
void TWindow<PhysicObj,object>::draw(std::weak_ptr<PhysicObj> target)
{
	if(!m_isInit)
		do_buildSprite();
	TSprite<PhysicObj,object>::draw(target);
}

template <typename PhysicObj, typename object>
void TWindow<PhysicObj,object>::move(const int16_t x, const int16_t y) throw()
{
	if(m_parent.use_count())
		set();
	TSprite<PhysicObj,object>::move(x,y);
}

template <typename PhysicObj, typename object>
void TWindow<PhysicObj,object>::do_buildSprite(void)
{
	uint16_t decX, decY;
	uint16_t xBigStep,yBigStep;
	uint16_t finalwidth,finalheight;
	bool resetSprite=false;
	std::weak_ptr<PhysicObj> weak;
	typename std::vector<std::shared_ptr<TWindow<PhysicObj, object> > >::iterator iter;


	set();
//	//check about existence of body and theme
//	if(!(m_theme.use_count()&& m_body.isValid()))
//		return m_isInit;
//	//check if theme was entirely init
//	if(!m_theme->isInit())
//		return m_isInit;

	//calculate the gap to center the body
	xBigStep=std::max(m_theme->getW(TOP),m_theme->getW(BOTTOM));
	yBigStep=std::max(m_theme->getH(RIGHT),m_theme->getH(LEFT));

	decX=xBigStep-m_body.getW()%xBigStep;
	decX=(decX==xBigStep)?0:decX>>1;

	decY=yBigStep-m_body.getH()%yBigStep;
	decY=decY==yBigStep?0:decY>>1;

	//calculate final size of image
	finalwidth	=m_body.getW()+decX+m_theme->getW(RIGHT)+m_theme->getW(LEFT);
	finalheight	=m_body.getH()+decY+m_theme->getH(TOP)+m_theme->getH(BOTTOM);

	//if sprite was never created or don't have good dimensions, create one
	resetSprite=!this->m_sprite.isValid();
	if(!resetSprite)
		resetSprite=!(this->m_sprite.getH()!=finalheight || this->m_sprite.getW()!=finalwidth);
	if(resetSprite)
	{
		m_themeChanged=true;
		this->m_sprite.create(finalwidth,finalheight,m_theme->getMaxBPP(),m_theme->getMaxRMask(),m_theme->getMaxGMask(),m_theme->getMaxBMask(),m_theme->getMaxAMask(),0);
	}

	iter=m_children.begin();
	weak=m_body.getBitmap();
	for(;iter!=m_children.end();iter++)
		(*iter)->draw(weak);

	weak=this->m_sprite.getBitmap();

	if(m_themeChanged)
		do_buildBorders(finalwidth,finalheight);

	m_body.draw(weak,decX+m_theme->getW(LEFT),decY+m_theme->getH(TOP));

}

template <typename PhysicObj, typename object>
void TWindow<PhysicObj,object>::do_buildBorders(uint16_t finalwidth, uint16_t finalheight)
{
	std::weak_ptr<PhysicObj> weak;
	weak=this->m_sprite.getBitmap();

	m_theme->draw(TOPLEFT,0,0,weak);
	m_theme->draw(TOPRIGHT,this->m_sprite.getW()-m_theme->getW(TOPRIGHT),0,weak);
	m_theme->draw(BOTTOMRIGHT,this->m_sprite.getW()-m_theme->getW(BOTTOMRIGHT),this->m_sprite.getH()-m_theme->getH(BOTTOMRIGHT),weak);
	m_theme->draw(BOTTOMLEFT,0,this->m_sprite.getH()-m_theme->getH(BOTTOMLEFT),weak);

	do_drawVBorder(TOPLEFT,LEFT			, 0);
	do_drawHBorder(TOPLEFT,TOP			, 0);
	do_drawVBorder(TOPRIGHT, RIGHT		, finalwidth-m_theme->getW(BOTTOMRIGHT));
	do_drawHBorder(BOTTOMRIGHT, BOTTOM	, finalheight-m_theme->getH(BOTTOMRIGHT));
}

template <typename PhysicObj, typename object>
void TWindow<PhysicObj,object>::do_buildBody(void)
{
}

template <typename PhysicObj, typename object>
void TWindow<PhysicObj,object>::do_drawVBorder(TEXTURE_POSITION start,TEXTURE_POSITION filler, uint16_t const offset)
{
	for(uint16_t y=m_theme->getH(start);y<m_theme->getH(start)+m_body.getH();y+=m_theme->getH(filler))
		m_theme->draw(filler,offset,y,this->m_sprite.getBitmap());
}

template <typename PhysicObj, typename object>
void TWindow<PhysicObj,object>::do_drawHBorder(TEXTURE_POSITION start,TEXTURE_POSITION filler, uint16_t const offset)
{
	for(uint16_t x=m_theme->getW(start);x<m_theme->getW(start)+m_body.getW();x+=m_theme->getW(filler))
		m_theme->draw(filler,x,offset,this->m_sprite.getBitmap());
}

template <typename PhysicObj, typename object>
void TWindow<PhysicObj,object>::addChild(std::weak_ptr<TWindow<PhysicObj, object> > child)
{
	set();
	child.lock()->m_parent=this->
		std::enable_shared_from_this<TWindow<PhysicObj,object> >::shared_from_this();
	m_children.push_back(child.lock());
}

template <typename PhysicObj, typename object>
void TWindow<PhysicObj,object>::set(void) throw()
{
	m_isInit=false;
	if(m_parent.use_count())
		m_parent.lock()->set();
}
