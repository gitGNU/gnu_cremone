#ifndef FILE_ERROR_H
#define FILE_ERROR_H

#include <stdexcept>
#include <string>

const std::string FILE_ERROR[]=
{
"File not found:",
"Unable to read file:",
"Unable to write file:",
"Unknown format of file:"
};

enum FILE_ERROR_CODE {NotFound=0, CantRead, CantWrite,UnknownFormat};

class File_error : public std::runtime_error
{
	public:
		explicit File_error(FILE_ERROR_CODE errorCode,const std::string& file, const std::string& otherInformations=std::string())
		:std::runtime_error(FILE_ERROR[errorCode]+file+otherInformations),m_errorCode(errorCode)
		{
		}

		virtual ~File_error() throw(){}

		FILE_ERROR_CODE m_errorCode;
	protected:
	private:
};

#endif // FILE_ERROR_H
