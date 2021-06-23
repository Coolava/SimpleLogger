#pragma once
#include <fstream>
#include <vector>
#include "chrono2.h"
#include "SafeQueue.h"

class Logger
{
public:
	Logger();
	
	~Logger();
	void open();
	void open(std::string fileName);
	void close();

	std::chrono::time_point<std::chrono::system_clock> log(const std::string& str)
	{
		//auto now = std::chrono::steadyToSystem(std::chrono::steady_clock::now());
		auto now = std::chrono::system_clock::now();
		std::string temp = std::chrono::time_toString(now) + str;

		queueLog_.enqueue(temp);

		return now;
	}

	void flush();
	

private:
	SafeQueue<std::string> queueLog_;
	std::ofstream file_;

};

