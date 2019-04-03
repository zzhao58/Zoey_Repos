//Utilities
//Zhi Zhao(109079178)	

#ifndef UTILITIES_SICT_H
#define UTILITIES_SICT_H
#include <string>
#include <fstream>

namespace sict {
	class Utilities {

		size_t field_width;    //max field width
		static char delimiter;  //field delimiter character


	public:
		Utilities();
		const std::string extractToken(const std::string& str, size_t& next_pos);
		const char getDelimiter() const;
		size_t getFieldWidth() const;
		static void setDelimiter(const char d);
		void setFieldWidth(size_t);

	};
}
#endif