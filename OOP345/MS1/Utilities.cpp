//Utilities.cpp
//Zhi Zhao (109079178)

#include <iostream>
#include "Utilities.h"

namespace sict {
	char Utilities::delimiter = '|';

	Utilities::Utilities() {
		field_width = 1;
	}

	const std::string Utilities::extractToken(const std::string& str, size_t& next_pos) {
		
		std::string token;

		size_t new_pos = str.find(delimiter, next_pos);//find index of delimiter. the find of function return a index
		try {
			if (new_pos == next_pos) {
				throw "Exception: one delimiter follows another without any token between them.";
			}
			
			token = str.substr(next_pos, new_pos-next_pos); //first parameter means: where start to get, second:how many position you need
			next_pos = ++new_pos;	

			if (token.length() > field_width) {
				field_width = token.length();
			}
		}
		catch(const char* err_msg){
			std::cout << err_msg << std::endl;
		}

		return token;
	}

	const char Utilities::getDelimiter() const {
		return delimiter;
	}


	void Utilities::setFieldWidth(size_t p_f) {
		field_width = p_f;
	}
	

	void Utilities::setDelimiter(const char d) {
		delimiter = d;
	}

	size_t Utilities::getFieldWidth() const {
		return field_width;
	}

	
}