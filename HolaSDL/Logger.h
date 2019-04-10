#pragma once
#include <string>
#include<iostream>
#include <fstream>
#include<memory>
#include "Worker.h"
using namespace std;

class Logger
{
public:
	static inline void initInstance(string filename)
	{
		if (instance_.get() == nullptr) {
			instance_.reset(new Logger(filename));
		}
	}

	static inline Logger * getInstance()
	{
		return instance_.get();
	}
	void log(string info);
	void log(function<string()> f);
	virtual ~Logger();

	Logger(Logger&) = delete;
	Logger& operator=(const Logger&) = delete;
private:
	Logger(string filename);
	static unique_ptr <Logger> instance_;
	ofstream log_;
	Worker worker_;
};
