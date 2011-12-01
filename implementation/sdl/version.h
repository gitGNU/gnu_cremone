#ifndef VERSION_H
#define VERSION_H

namespace crem
{
	namespace AutoVersion{

		//Software Status
		static const char STATUS[] = "";
		static const char STATUS_SHORT[] = "";

		//Standard Version Type
		static const long MAJOR = 0;
		static const long MINOR = 0;
		static const long BUILD = 1;
		static const long REVISION = 1;

		//Miscellaneous Version Types
		static const long BUILDS_COUNT = 4;
		#define RC_FILEVERSION 0,0,1,1
		#define RC_FILEVERSION_STRING "0, 0, 1, 1\0"
		static const char FULLVERSION_STRING[] = "0.0.1.1";

		//SVN Version
		static const char SVN_REVISION[] = "0";
		static const char SVN_DATE[] = "unknown date";

		//These values are to keep track of your versioning state, don't modify them.
		static const long BUILD_HISTORY = 1;


	}
}
#endif //VERSION_H
