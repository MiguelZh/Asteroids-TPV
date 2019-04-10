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
	inline static void initInstance(string filename);
	inline static Logger* instance();
	void log(string info);
	void log(function<string()> f);


	Logger(Logger&) = delete;
	Logger& operator=(const Logger&) = delete;
private:
	Logger(string filename);
	virtual ~Logger();
	static unique_ptr <Logger> instance_;
	ofstream log_;
	Worker worker_;
};