#include "DebugLog.h"

DebugLog* DebugLog::self = nullptr;


//***NOTE***
//https://stackoverflow.com/questions/16049306/error-lnk2001-unresolved-external-symbol-private-static-class //
// "
static char DebugBuff[256];
//"static, but non-const data members should be defined outside of the class definition and inside the namespace enclosing the class. The usual practice is to define it in the translation unit (*.cpp) because it is considered to be an implementation detail. Only static and const integral types can be declared and defined at the same time (inside class definition)"

void DebugLog::PrivateDebugOut(const char * outMessage, va_list args)
{
	vsprintf_s(DebugBuff, outMessage, args);
	OutputDebugString(DebugBuff);
}
