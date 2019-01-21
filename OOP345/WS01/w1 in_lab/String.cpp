//String.cpp
//Zhi Zhao (109079178)


#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <cstring>
#include"String.h"

extern const int INITIAL;

using namespace std;
namespace sict {

	String::String(const char* o_str) {
		if (o_str != nullptr&& o_str[0]!='\0') {
			std::strncpy(c_string, o_str, MAX);
			c_string[MAX] = '\0';
		}
		else {
			c_string[0] = '\0';
		}
	}


	void String::display(ostream& os) {
		
		os << c_string;

	}

	
	ostream& operator<<(ostream &os, String& o_str) {

		static int j = INITIAL;
		os << j++ << ": ";
		o_str.display(os);
		return os;
	}
}