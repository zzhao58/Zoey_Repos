//ZHi Zhao (109079178)

#ifndef SICT_TEXT_H
#define SICT_TEXT_H

namespace sict {

	class Text {
		std::string* stringlines;
		size_t string_Num;

	public:
		Text();
		Text(char*);
		Text(const Text&);				//copy Constructor
		Text(Text&&);					//move Constructor
		Text& operator=(const Text&);  //copy assignment operator
		Text& operator=(Text&&);		//move assignment operator
		~Text();
		size_t size() const;
	};
}
#endif