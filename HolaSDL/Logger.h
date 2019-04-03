#pragma once
#include <string>

using namespace std;
class Logger
{
public:
	Logger();
	virtual ~Logger();
	inline static void initInstance(string filename) {  }
	inline static Logger* instance() {
		if (logger_ == nullptr) {
			logger_ = new Logger();
		}

		return logger_;
	}
	void log(string info);
	void log(function<string()> f);


	Logger(Logger&) = delete;
	Logger& operator=(const Logger&) = delete;
private:
	static Logger* logger_;
	ofstream log_;
};