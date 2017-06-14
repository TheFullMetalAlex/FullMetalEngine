#include "DebugLog.h"

int main()
{
	DebugLog::DebugOut("Hello\n");
	int x = 5;
	DebugLog::DebugOut("Hello %d\n", x);
	return 0;
}