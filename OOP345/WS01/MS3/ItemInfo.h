#ifndef SICT_ITEMINFO_H
#define SICT_ITEMINFO_H

#include <iostream>
#include <string>

namespace sict {

	class ItemInfo {
		std::string Name;
		unsigned serialNumber;
		bool IsFilled;
	public:
		ItemInfo();
		ItemInfo(const std::string&);
		std::string getName() const;
		unsigned getserialNumber() const;
		void setserialNumber(unsigned);
		bool getIsFilled() const;
		void setIsFilled(bool);
	};
}

#endif 
