//ZHi Zhao (109079178)

#ifndef SICT_TIMEKEEPER_H
#define SICT_TIMEKEEPER_H

#include <istream>
#include <chrono>

namespace sict {

	const int  MAX = 10;
	const char UNIT[] = "seconds";

	class Timekeeper {
		int current_Num;
		std::chrono::steady_clock::time_point startTime;
		std::chrono::steady_clock::time_point endTime;

		struct {
			char* message;
			char* timeUnit;
			std::chrono::steady_clock::duration duration;
		} records[MAX];

	public:
		Timekeeper();
		~Timekeeper();
		void start();
		void stop();
		void recordEvent(const char*);
		std::ostream& report(std::ostream&);
	};
}
#endif

