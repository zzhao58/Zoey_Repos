//String.h
//Zhi Zhao (109079178)

#ifndef SICT_STRING_H
#define SICT_STRING_H

namespace sict {

	const int MAX = 3;
	class String{
		char c_string[MAX + 1];

	public:
		String(const char*);
		void display(std::ostream&);
	};

	std::ostream& operator<<(std::ostream &, String&);
}
#endif