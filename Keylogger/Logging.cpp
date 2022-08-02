#include "Logging.h"
#include <fstream>

void Log::Logging(std::string input)
{
	std::fstream LogFile;
	LogFile.open("dataRecording.txt", std::fstream::app);
	if (LogFile.is_open())
	{
		LogFile << input;
		LogFile.close();
	}
}
