//ZHi Zhao (109079178)
//Text.h

#ifndef SICT_TEXT_H
#define SICT_TEXT_H

namespace sict {

	class Text {
		std::string* stringlines;
		size_t string_Num;

	public:
		Text();
		Text(char*);
		Text(const Text&);
		Text& operator=(const Text&);
		~Text();
		size_t size() const;
	};
}
#endif