// Workshop 2 - Copy and Move Semantics
// Name: Qirong Fu
// Student #: 158899179
// Email: qfu11@myseneca.ca
// Course: OOP345 WINTER 2019
// File: Text.h

#ifndef SICT_TEXT_H
#define SICT_TEXT_H

namespace sict
{
	class Text {
		std::string* m_str;
		size_t  number_str;

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

