/********************************************************************************
 *cremone - A library to easily make GUI for games.								*
 *Copyright (C) 2011 Morel B�renger												*
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

#ifndef TSINGLETON_H
#define TSINGLETON_H

namespace TCrem
{
	template< class T>
	class TSingleton
	{
		public:
			static T &GetInstance(void) throw()
			{
				if(!sm_Instance)
					sm_Instance=new T;
				return static_cast<T&>(*sm_Instance);
			}
		protected:
			TSingleton<T>(void) throw()
			{
			}
			virtual ~TSingleton<T>(void) throw()
			{
			}
		private:
			static T* sm_Instance;
	};

	template<class T>
	T *TSingleton<T>::sm_Instance=0;
}
#endif
