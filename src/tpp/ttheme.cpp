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

#include "exceptions/file_error.h"

template <typename PhysicObj, typename object>
TTheme<PhysicObj,object>::TTheme(void)
:m_maxBPP(),m_maxRMask(),m_maxGMask(),m_maxBMask(),m_maxAMask(),m_commonFlags()
{
}

template <typename PhysicObj, typename object>
TTheme<PhysicObj,object>::TTheme(std::string const &indexFileName, std::string const &path)
:m_maxBPP(),m_maxRMask(),m_maxGMask(),m_maxBMask(),m_maxAMask(),m_commonFlags()
{
	set(indexFileName,path);
}

template <typename PhysicObj, typename object>
void TTheme<PhysicObj,object>::set(TEXTURE_POSITION const position, const TImage<PhysicObj,object> &image)
{
	m_borders[position]=image;
	do_calcMax(position);
}

template <typename PhysicObj, typename object>
void TTheme<PhysicObj,object>::set(TEXTURE_POSITION const position, const std::string &fileName)
{
	m_borders[position].load(fileName);
	do_calcMax(position);
}

template <typename PhysicObj, typename object>
void TTheme<PhysicObj,object>::set(std::string const &indexFileName, std::string const &path)
{
	std::string s(path+indexFileName);
	FILE *f=fopen(s.c_str(),"r");
	if(f)
	{
		std::string position, fileName;
		while(!feof(f))
		{
			do_parseThemeFile(f,position,fileName);

			if(!(fileName.empty() || position.empty()))
			{
				POSITION_MAP::const_iterator iter=m_positionName.find(position);
				if(iter!=m_positionName.end())
					set(iter->second,path+fileName);
				else
					throw File_error(UnknownFormat,s);
			}
		}
		fclose(f);
	}
	else
		throw File_error(NotFound,s);
}

template <typename PhysicObj, typename object>
uint16_t TTheme<PhysicObj,object>::getW(TEXTURE_POSITION position) const
{
	return m_borders[position].getW();
}

template <typename PhysicObj, typename object>
uint16_t TTheme<PhysicObj,object>::getH(TEXTURE_POSITION position) const
{
	return m_borders[position].getH();
}

template <typename PhysicObj, typename object>
void TTheme<PhysicObj,object>::draw(
									TEXTURE_POSITION position,
									uint16_t const x,
									uint16_t const y,
									std::weak_ptr<PhysicObj> target
									) const
{
	m_borders[position].draw(target,x,y);
}

template <typename PhysicObj, typename object>
uint8_t TTheme<PhysicObj,object>::getMaxBPP(void) const throw()
{
	return m_maxBPP;
}

template <typename PhysicObj, typename object>
uint32_t TTheme<PhysicObj,object>::getMaxRMask(void) const throw()
{
	return m_maxRMask;
}

template <typename PhysicObj, typename object>
uint32_t TTheme<PhysicObj,object>::getMaxGMask(void) const throw()
{
	return m_maxGMask;
}

template <typename PhysicObj, typename object>
uint32_t TTheme<PhysicObj,object>::getMaxBMask(void) const throw()
{
	return m_maxBMask;
}

template <typename PhysicObj, typename object>
uint32_t TTheme<PhysicObj,object>::getMaxAMask(void) const throw()
{
	return m_maxAMask;
}

template <typename PhysicObj, typename object>
uint32_t TTheme<PhysicObj,object>::getCommonFlags(void) const throw()
{
	return m_commonFlags;
}

template <typename PhysicObj, typename object>
void TTheme<PhysicObj,object>::do_calcMax(TEXTURE_POSITION position)
{
	m_maxBPP=std::max(m_maxBPP,m_borders[position].getBPP());
	m_maxRMask=std::max(m_maxRMask,m_borders[position].getRMask());
	m_maxGMask=std::max(m_maxGMask,m_borders[position].getGMask());
	m_maxBMask=std::max(m_maxBMask,m_borders[position].getBMask());
	m_maxAMask=std::max(m_maxAMask,m_borders[position].getAMask());
	if(isInit())
		m_commonFlags=
			m_borders[0].getFlags()&
			m_borders[1].getFlags()&
			m_borders[2].getFlags()&
			m_borders[3].getFlags()&
			m_borders[4].getFlags()&
			m_borders[5].getFlags()&
			m_borders[6].getFlags()&
			m_borders[7].getFlags();
}

template <typename PhysicObj, typename object>
bool TTheme<PhysicObj,object>::isInit(void) const throw()
{
	return	m_borders[0].isValid()&&
			m_borders[1].isValid()&&
			m_borders[2].isValid()&&
			m_borders[3].isValid()&&
			m_borders[4].isValid()&&
			m_borders[5].isValid()&&
			m_borders[6].isValid()&&
			m_borders[7].isValid();
}

template <typename PhysicObj, typename object>
void TTheme<PhysicObj,object>::do_parseThemeFile(FILE *file,std::string &position, std::string &fileName) const
{
	char c;
	bool exit, comment;
	position.clear();fileName.clear();
	exit=false; comment=false;
	do
	{
		switch((c=fgetc(file)))
		{
		case '#':
			comment=true;
		case '=':
		case '\r':
		case '\n':
			exit=true;
			break;
		default:
			position+=c;
		}
	}while( !(exit || feof(file)));

	exit=comment;
	while( !(exit || feof(file)))
	{
		switch((c=fgetc(file)))
		{
		case '#':
			comment=true;
		case '=':
		case '\r':
		case '\n':
			exit=true;
			break;
		default:
			fileName+=c;
		}
	}
}

//initialisation of positions names and indexes
template <typename PhysicObj, typename object>
const POSITION_MAP TTheme<PhysicObj,object>::
	m_positionName={
			POSITION_ELEM(strBottom,BOTTOM),
			POSITION_ELEM(strBottom,BOTTOM),
			POSITION_ELEM(strBottomLeft,BOTTOMLEFT),
			POSITION_ELEM(strBottomRIght,BOTTOMRIGHT),
			POSITION_ELEM(strLeft,LEFT),
			POSITION_ELEM(strRight,RIGHT),
			POSITION_ELEM(strTop,TOP),
			POSITION_ELEM(strTopLeft,TOPLEFT),
			POSITION_ELEM(strTopRight,TOPRIGHT)
		};

template <typename PhysicObj, typename object>
const std::string TTheme<PhysicObj,object>::strBottom("bottom");
template <typename PhysicObj, typename object>
const std::string TTheme<PhysicObj,object>::strBottomLeft("bottomleft");
template <typename PhysicObj, typename object>
const std::string TTheme<PhysicObj,object>::strBottomRIght("bottomright");
template <typename PhysicObj, typename object>
const std::string TTheme<PhysicObj,object>::strLeft("left");
template <typename PhysicObj, typename object>
const std::string TTheme<PhysicObj,object>::strRight("right");
template <typename PhysicObj, typename object>
const std::string TTheme<PhysicObj,object>::strTop("top");
template <typename PhysicObj, typename object>
const std::string TTheme<PhysicObj,object>::strTopLeft("topleft");
template <typename PhysicObj, typename object>
const std::string TTheme<PhysicObj,object>::strTopRight("topright");
