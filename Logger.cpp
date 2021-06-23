
#include "Logger.h"


Logger::Logger()
{
}

Logger::~Logger()
{
	queueLog_.destory();
	
	close();
}

void Logger::open()
{
	auto now = std::chrono::system_clock::now();
	std::string saveName = time_toString(now) + ".csv";
	open(saveName);
}

void Logger::open(std::string fileName)
{
	close();

	file_.open(fileName, std::ofstream::out | std::ofstream::app);
}

void Logger::close()
{
	if (file_.is_open() == true)
	{
		file_.flush();
		file_.close();
	}
}



void Logger::flush()
{
	size_t len = queueLog_.size();
	for (size_t i = 0; i < len; i++)
	{
		auto str = queueLog_.dequeue();
		file_ << str;
	}
	file_.flush();

}
