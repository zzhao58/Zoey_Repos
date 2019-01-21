//w1.cpp
//Zhi Zhao (109079178)

#include <iostream>
#include "process.h"

using namespace std;
using namespace sict;

extern const int  INITIAL=3;

int main(int argc, char* argv[]){
	if (argc != 0) {
		//echoes the set of arguments in a single line
		cout << "Command Line :";
		for (int i = 0; i < argc; i++) {
			cout << " " << argv[i];
		}
		cout << " "<< endl;

		//echoes arguments from index [INITIAL-1]
		for (int i = INITIAL - 2; i < argc; i++) {
			process(argv[i]);
		}
		return 0;
	}
	else {
		//user has not enter any string
		cout << "***Insufficient number of arguments***";
		return 1;
	}

}