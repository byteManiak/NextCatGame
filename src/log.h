#pragma once

#include <string>
#include <iostream>

enum LogType {
	LOG_ERROR,
	LOG_WARN,
	LOG_MESSAGE
};

static void Log(LogType logType, std::string source, std::string message)
{
	std::ostream *stream;
	std::string header;

	switch(logType)
	{
	case LOG_ERROR:
		header = "[!]";
		stream = &std::cerr;
		break;
	case LOG_WARN:
		header = "[@]";
		stream = &std::cout;
		break;
	case LOG_MESSAGE:
		header = "[#]";
		stream = &std::cout;
		break;
	}

	(*stream) << header << " [" << source << "] " << message << std::endl;
}