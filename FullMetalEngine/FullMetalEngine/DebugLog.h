#ifndef DEBUGLOG_H
#define DEBUGLOG_H

#include <Windows.h>
#include <stdio.h>
#include <stdarg.h>






//Singleton class for printing to output window (debugging tool)
class DebugLog
{
private:

	//Big 4
	DebugLog() {};
	DebugLog(const DebugLog& other) {};
	DebugLog& operator=(const DebugLog& other) {};
	~DebugLog() {};

	//pointer to self
	static DebugLog *self;

	//Instance Creation
	static DebugLog& Instance()
	{
		if (!self)
		{
			self = new DebugLog();
		}

		return *self;
	}


	void PrivateDebugOut(const char* outMessage, va_list args);

public:

	//Reference on using variable arguments using ellipses http://www.cprogramming.com/tutorial/c/lesson17.html
	//Apparently this is how printf works

	//Print a message to the output window

	static void DebugOut(char* outMessage, ...)
	{
		va_list args;
		va_start(args, outMessage);

		Instance().PrivateDebugOut(outMessage, args);
	}

};

#endif // !DEBUGLOG_H

