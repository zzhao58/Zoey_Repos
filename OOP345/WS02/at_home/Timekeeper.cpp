//ZHi Zhao (109079178)
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <chrono>
#include <cstring>
#include "Timekeeper.h"

using namespace std;
namespace sict {
	Timekeeper::Timekeeper() {
		current_Num = 0;
		startTime = chrono::steady_clock::now();
		endTime = chrono::steady_clock::now();

		for (auto& e : records) {
			e.message  = nullptr;
			e.timeUnit = nullptr;
			e.duration = chrono::duration_cast<chrono::milliseconds>(endTime - startTime);
		}
	}

	Timekeeper::~Timekeeper(){
		for (auto& e : records) {
			delete [] e.message;
			e.message = nullptr;
			
			delete [] e.timeUnit;
			e.timeUnit = nullptr;
		}
	}

	void Timekeeper::start() {
		startTime = chrono::steady_clock::now();
	}

	void Timekeeper::stop() {
		endTime = chrono::steady_clock::now();
	}

	void Timekeeper::recordEvent(const char* p_event) {
		if (current_Num < MAX) {
		
			records[current_Num].message = new char[strlen(p_event) + 1];
			strcpy(records[current_Num].message, p_event);

			records[current_Num].timeUnit = new char[strlen(UNIT) + 1];
			strcpy(records[current_Num].timeUnit, UNIT);

			records[current_Num].duration = chrono::duration_cast<chrono::milliseconds>(endTime -startTime);
			
			current_Num++;
		}		
	}

	std::ostream& Timekeeper::report(std::ostream& os) {
		os << std::endl;
		os << "Execution Times:" << std::endl;

		for (int i = 0; i < current_Num; i++)
		{
			os << records[i].message << ' ' << (records[i].duration).count()/1000000<< ' ' << records[i].timeUnit << std::endl;
		}
		return os;
	}
}