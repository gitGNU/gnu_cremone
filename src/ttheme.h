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

#ifndef TTHEME_H
#define TTHEME_H

#include <string>
#include <map>
#include <utility>
#include <stdexcept>

#include "definitions.h"
#include "timage.h"

namespace TCrem
{
	typedef std::map<std::string const , TEXTURE_POSITION> POSITION_MAP;
	typedef std::pair<std::string const, TEXTURE_POSITION> POSITION_ELEM;

	template <typename PhysicObj, typename object>
	class TTheme
	{
////////////////////

	private:
		static const POSITION_MAP m_positionName;
	//TODO (berenger#1#) implement a special empty theme (with images of w&h = 0px)
//	const std::string strBottom("bottom");
//	const std::string strBottomLeft("bottomleft");
//	const std::string strBottomRIght("bottomright");
//	const std::string strLeft("left");
//	const std::string strRight("right");
//	const std::string strTop("top");
//	const std::string strTopLeft("topleft");
//	const std::string strTopRight("topright");
		static const std::string strBottom;
		static const std::string strBottomLeft;
		static const std::string strBottomRIght;
		static const std::string strLeft;
		static const std::string strRight;
		static const std::string strTop;
		static const std::string strTopLeft;
		static const std::string strTopRight;

/////////////////////
	public:
		/** \brief Ctor */
		TTheme(void);
		/** \brief Ctor: use a theme file to load textures
		 * \param path std::string const& path to the file
		 * \param indexFileName std::string const& name of the file
		 */
		TTheme(std::string const &path, std::string const &indexFileName);
		/** \brief draw a part of the theme on a target
		 * \param position TEXTURE_POSITION
		 * \param x uint16_t const
		 * \param y uint16_t const
		 * \param target std::weak_ptr<PhysicObj>
		 */
		void draw(TEXTURE_POSITION const position, uint16_t const x,uint16_t const y, std::weak_ptr<PhysicObj> target) const;
		/** \brief set a part of the theme with an existing image
		 * \param position TEXTURE_POSITION
		 * \param image __image<PhysicObj const,object>&
		 */
		void set(TEXTURE_POSITION const position, const TImage<PhysicObj,object> &image);
		/** \brief set a part of the theme with a file
		 * \param position TEXTURE_POSITION
		 * \param fileName const std::string&
		 */
		void set(TEXTURE_POSITION const position, const std::string &fileName);
		/** \brief set the entire theme from a theme file
		 * \param indexFileName std::string const&
		 * \param path std::string const&
		 */
		void set(std::string const &indexFileName, std::string const &path);
		/** \brief return the width of an element of the theme
		 * \param position TEXTURE_POSITION
		 * \return uint16_t
		 */
		uint16_t getW(TEXTURE_POSITION const position) const;
		/** \brief return the height of an element of the theme
		 * \param position TEXTURE_POSITION
		 * \return uint16_t
		 */
		uint16_t getH(TEXTURE_POSITION const position) const;
		/** \brief return the maximum width in the theme
		 * \param position TEXTURE_POSITION
		 * \return uint16_t
		 */
		uint16_t getMaxW(void) const throw();
		/** \brief return the maximum height in the theme
		 * \param position TEXTURE_POSITION
		 * \return uint16_t
		 */
		uint16_t getMaxH(void) const throw();
		/** \brief return the maximum depth (bits per pixel) in the theme
		 * \param position TEXTURE_POSITION
		 * \return uint8_t
		 */
		uint8_t getMaxBPP(void) const throw();
		/** \brief return the highest red color mask in the theme
		 * \param position TEXTURE_POSITION
		 * \return uint32_t
		 */
		uint32_t getMaxRMask(void)const throw();
		/** \brief return the highest green color mask in the theme
		 * \param position TEXTURE_POSITION
		 * \return uint32_t
		 */
		uint32_t getMaxGMask(void)const throw();
		/** \brief return the highest blue color mask in the theme
		 * \param position TEXTURE_POSITION
		 * \return uint32_t
		 */
		uint32_t getMaxBMask(void)const throw();
		/** \brief return the highest transparency mask in the theme
		 * \param position TEXTURE_POSITION
		 * \return uint32_t
		 */
		uint32_t getMaxAMask(void)const throw();
		/** \brief return the flags common to all parts of the theme
		 * \param position TEXTURE_POSITION
		 * \return uint32_t
		 */
		uint32_t getCommonFlags(void)const throw();
		/** \brief check the validity of the theme
		 * \return bool true if theme is valid
		 */
		bool isInit(void)const throw();
	protected:
	private:
		/** \brief recalculate values returned by getters
		 *
		 * \param position TEXTURE_POSITION position of the last element set modified
		 * \return void
		 *
		 */
		void do_calcMax(TEXTURE_POSITION const position);
		/** \brief parse a line of the theme file to extract position string and filename
		 * \param file FILE const*
		 * \param position std::string&
		 * \param fileName std::string&
		 */
		void do_parseThemeFile(FILE *file,std::string &position, std::string &fileName)const;
		void do_initPositionName(void);
	public:
	protected:
		TImage<PhysicObj,object>m_borders[8]; //!< images of the theme
	private:
		uint8_t m_maxBPP; //!< maximum color depth in theme
		uint32_t m_maxRMask,m_maxGMask,m_maxBMask,m_maxAMask; //!< maximum color and transparency masks in theme
		uint32_t m_commonFlags; //!< common flags in theme

	//	PositionName s_positionName;
	//	static std::map<std::string,TEXTURE_POSITION> s_positionName;//!< tool to parse theme files. \todo (berenger#1#) think about creating a class inheriting from singleton.
	};

	#include "tpp/ttheme.cpp"
}
#endif
