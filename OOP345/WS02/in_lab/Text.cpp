//ZHi Zhao (109079178)
//Text.cpp

#include <iostream>
#include <string>
#include <fstream>
#include "Text.h"


namespace sict {

	Text::Text() {
		stringlines = nullptr;
		string_Num = 0;
	}

	Text::Text(char* fileName) {

		string_Num = 0;
		std::ifstream fin(fileName);
		std::string line; //each line put in the line(temper),the new line will cover the old one ,but we can get the number  of line.
		

		if (fin.is_open()) {
			
			while (std::getline(fin, line))//fin to line
			{
				string_Num++;
			}

			stringlines = new std::string[string_Num];
			
			for (size_t i = 0; i < string_Num; i++)
			{
				std::getline(fin, stringlines[i]);
			}
			
			fin.close();
		}
		
	}
	
	Text::Text(const Text& src) {
		stringlines = nullptr;
		*this = src;
	}
	
	Text& Text::operator=(const Text& src) {
		if (this != &src) {
			string_Num = src.string_Num;

			delete [] stringlines;
			if (src.stringlines != nullptr) {
				stringlines = new std::string[string_Num];
				for (size_t i = 0; i < string_Num; i++) {
					stringlines[i] = src.stringlines[i];
				}
			}
			else{
				stringlines = nullptr;
			}
		}
		return *this;
	}

	Text::~Text() {
		delete [] stringlines;
		stringlines = nullptr;
	}

	size_t Text::size() const {
		return string_Num;
	}





}