// Workshop 5 - Functions
// w5.cpp
// Chris Szalwinski
// 2019/02/10

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "KVPair.h"
#include "KVList.h"
#include "Taxable.h"
using namespace sict;

float HST = 0.13f;
int fieldWidth = 10;

template <typename L, typename T, typename K, typename V>
L createList(char* filename) {
	std::ifstream file(filename);
	if (!file) {
		L list(0);
		return std::move(list);
	}
	int no_records = 0;
	do {
		char c = file.get();
		if (file.good() && c == '\n') no_records++;
	} while (!file.eof());
	file.clear();
	file.seekg(std::ios::beg);
	L list(no_records);
	do {
		K key;
		V value;
		file >> key;
		if (file) {
			file >> value;
			file.ignore();
			list.push_back(T(key, value));
		}
	} while (file);

	return std::move(list);
}
//zhi zhao (109079178)
int main(int argc, char* argv[]) {
	std::cout << "Command Line : ";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << ' ';
	}
	std::cout << std::endl;

	// check for command line errors
	if (argc != 3) exit(1);

	// set for fixed, 2-decimal point output
	std::cout << std::fixed << std::setprecision(2);

	bool processList = true;

	// process price list file
	try {
		KVList<KVPair<std::string, float>> priceList = createList<
			KVList<KVPair<std::string, float>>,
			KVPair<std::string, float>,
			std::string,
			float>
			(argv[1]);
		std::cout << "\nPrice List with G+S Taxes Included\n==================================\n";
		std::cout << "Description:      Price Price+Tax\n";
		priceList.display(std::cout, Taxable(HST));
	}
	catch (int& value)
	{
		if (value == 1)
		{
			std::cout << "The number of elements received is not positive-valued" << std::endl;
			std::exit(2);
			processList = false;
		}
		else if (value == 2)
		{
			std::cout << "out-of-bounds" << std::endl;
			std::exit(3);
		}
	}

	try
	{
		KVList<KVPair<int, float>> gradesList = createList<
			KVList<KVPair<int, float>>,
			KVPair<int, float>,
			int,
			float>
			(argv[2]);

		auto letter = [](float grade)
		{
			std::string convertLetter;
			if (grade >= 90 && grade <= 100)
				return convertLetter = "A+";
			else if (grade >= 80 && grade <= 89.9)
				return convertLetter = "A ";
			else if (grade >= 75 && grade <= 79.9)
				return convertLetter = "B+";
			else if (grade >= 70 && grade <= 74.9)
				return convertLetter = "B ";
			else if (grade >= 65 && grade <= 69.9)
				return convertLetter = "C+";
			else if (grade >= 60 && grade <= 64.9)
				return convertLetter = "C ";
			else if (grade >= 55 && grade <= 59.9)
				return convertLetter = "D+";
			else if (grade >= 50 && grade <= 54.9)
				return convertLetter = "D ";
			else
				return convertLetter = "F ";
		};
		std::cout << "\nStudent List Letter Grades Included\n==================================\n";
		std::cout << "Student No :      Grade    Letter\n";
		gradesList.display(std::cout, letter);
	}
	catch (int& value)
	{
		if (value == 1)
		{
			std::cout << "The number of elements is not greater than zero." << std::endl;
			std::exit(4);
			processList = false;
		}
		else if (value == 2)
		{
			std::cout << "exceed max room of KVlist" << std::endl;
			std::exit(5);
		}
	}

	std::exit(0);
}