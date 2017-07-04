#include "DebugLog.h"
#include <chrono>
#include <WinUser.h>

int main()
{
	//Setup systems/initialize prereq work
	Initialize();

	bool quit = false;

	//Main game loop
	while (!quit)
	{
		ReadInput();
		Update();
		Render();

	}
	
	//Properly shutdown systems and close application
	Terminate();





	
	//DebugLog::DebugOut("Hello\n");
	//int x = 5;
	//DebugLog::DebugOut("Hello %d\n", x);
	//return 0;
}

void Initialize()
{

}

void ReadInput()
{
	
}

void Update()
{
	DebugLog::DebugOut("Update\n");
}

void Render()
{
	DebugLog::DebugOut("Render");
}


void Terminate()
{

}