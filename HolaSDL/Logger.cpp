#include "Logger.h"

 unique_ptr <Logger> Logger::instance_;
//Logger* Logger::instance_ = nullptr;

Logger::Logger(string filename)
{
	log_.open(filename);
	worker_.start();
}


Logger::~Logger()
{
	log_.close();
}


void Logger::log(string info)
{
	worker_.execute([info,this]() { log_ << info << endl; });
}

void Logger::log(function<string()> f)
{
	worker_.execute([f, this]() {log_ << f() << endl; });
}


