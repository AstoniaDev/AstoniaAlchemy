#ifndef VERSION_H
#define VERSION_H

	//Software Status
	static const char STATUS[] = "Beta";
	static const char STATUS_SHORT[] = "b";
	
	//Standard Version Type
	static const long MAJOR = 0;
	static const long MINOR = 9;
	static const long BUILD = 22;
	static const long REVISION = 112;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 46;
	#define RC_FILEVERSION 0,9,22,112
	#define RC_FILEVERSION_STRING "0, 9, 22, 112\0"
	static const char FULLVERSION_STRING[] = "0.9.22.112";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 22;
	

#endif //VERSION_H
