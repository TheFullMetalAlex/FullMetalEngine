#include "DebugLog.h"

DebugLog* DebugLog::self = nullptr;

void DebugLog::PrivateDebugOut(char * outMessage, va_list args)
{
	vsprintf_s(DebugBuff, outMessage, args);
	OutputDebugString(DebugBuff);
}
