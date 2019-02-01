// Workshop 2 - Copy and Move Semantics
// Name: Qirong Fu
// Email: qfu11@myseneca.ca
// Student #: 158899179
// Course: OOP345 WINTER 2019
// File: Timekeeper.h

#ifndef SICT_TIMEKEEPER_H
#define SICT_TIMEKEEPER_H

#include <iostream>
#include <chrono>

namespace sict
{
	const int MAX = 10;	
		
	class Timekeeper {
		int n_record;
		std::chrono::steady_clock::time_point n_start;
		std::chrono::steady_clock::time_point n_end;

		struct {	
			char* n_message;
			const char* unitTime;			
			std::chrono::steady_clock::duration duration;			
		}record[MAX];
		
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
