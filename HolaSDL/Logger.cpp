#include "Logger.h"

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

inline void Logger::initInstance(string filename)
{
	if (instance_.get() == nullptr) {
		instance_.reset(new Logger(filename));
	}
}

inline Logger * Logger::instance()
{
	return instance_.get();
}

void Logger::log(string info)
{
	worker_.execute([info,this]() { log_ << info << endl; });
}

void Logger::log(function<string()> f)
{
	worker_.execute([f, this]() {log_ << f() << endl; });
}


