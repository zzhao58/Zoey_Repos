// Workshop 2 - Copy and Move Semantics
// Name: Qirong Fu
// Email: qfu11@myseneca.ca
// Student #: 158899179
// Course: OOP345 WINTER 2019
// File: Timekeeper.cpp

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <chrono>
#include <cstring>
#include "Timekeeper.h"
using namespace sict;

namespace sict
{
	Timekeeper::Timekeeper()
	{
		n_record = 0;

		for (int i = 0; i < MAX; i++)
		{
			record[i].n_message = nullptr;
			record[i].unitTime = nullptr;
		}
	}

	Timekeeper::~Timekeeper()
	{
		for (int i = 0; i < MAX; i++)
		{
			delete[] record[i].n_message;
			record[i].n_message = nullptr;
		}
	}

	void Timekeeper::start()
	{
		n_start = std::chrono::steady_clock::now();
	}

	void Timekeeper::stop()
	{
		n_end = std::chrono::steady_clock::now();
	}

	void Timekeeper::recordEvent(const char* str)
	{
		if (n_record < MAX)
		{
			record[n_record].n_message = new char[strlen(str) + 1];
			std::strcpy(record[n_record].n_message, str);

			record[n_record].duration = (n_end - n_start);

			record[n_record].unitTime = "milliseconds";			

			n_record++;
		}
	}

	std::ostream& Timekeeper::report(std::ostream& os)
	{
		os << std::endl;
		os << "Execution Times:" << std::endl;

		for (int i = 0; i < n_record; i++)
		{
			os << record[i].n_message << ' ' << std::chrono::duration_cast<std::chrono::milliseconds>(record[i].duration).count() << record[i].unitTime << std::endl;
		}

		return os;
	}
}

