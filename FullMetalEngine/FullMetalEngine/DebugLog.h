#ifndef DEBUGLOG_H
#define DEBUGLOG_H

#include <Windows.h>
#include <stdio.h>
#include <stdarg.h>

class DebugLog
{
public:

	//Big 4
	DebugLog() = delete;
	DebugLog(const DebugLog& other) = delete;
	DebugLog& operator=(const DebugLog& other) = delete;
	~DebugLog() = delete;

	//Reference on using variable arguments using ellipses http://www.cprogramming.com/tutorial/c/lesson17.html
	//Apparently this is how printf works

	static char DebugBuff[256];

	//Print a message to the output window
	static void DebugOut(const char* outMessage, ...)
	{
		va_list args;
		va_start(args, outMessage);
		vsprintf_s(DebugBuff, outMessage, args);
		OutputDebugString(DebugBuff);
	}
private:

};

#endif // !DEBUGLOG_H

