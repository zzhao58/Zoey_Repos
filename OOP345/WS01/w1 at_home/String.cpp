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
		if (o_str != nullptr && o_str[0]!='\0') {
			c_string = new char[strlen(o_str) + 1];
			strcpy(c_string, o_str);
		}
		else {
			c_string[0] = '\0';
		}
	}

	String::~String() {
		delete[] c_string;
		//c_string = nullptr;
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