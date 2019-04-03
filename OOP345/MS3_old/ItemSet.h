//ItemSet.h
//Zhi Zhao (109079178)

#ifndef ITEMSET_SICT_H
#define ITEMSET_SICT_H

#include <iostream>
#include <iomanip>
#include <string>

namespace sict {

	const unsigned CODE_WIDTH = 5;
	class ItemSet {
		std::string name;
		unsigned serialNumber;
		unsigned Quantity;
		std::string description;
		unsigned field_width;
	
	public:
		ItemSet(const std::string&);
		const std::string& getName() const;
		const unsigned getSerialNumber() const;
		const unsigned getQuantity() const;
		ItemSet& operator--();
		void display(std::ostream& os, bool full) const;
	};
}
#endif 


