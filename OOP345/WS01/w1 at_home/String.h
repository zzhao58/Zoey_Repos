//String.h
//Zhi Zhao (109079178)

#ifndef SICT_STRING_H
#define SICT_STRING_H

namespace sict {

	class String{
		char* c_string = nullptr;

	public:
		String(const char*);
		~String();
		void display(std::ostream&);
	};

	std::ostream& operator<<(std::ostream &, String&);
}
#endif