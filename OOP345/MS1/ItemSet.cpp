//ItemSet.cpp
//Zhi Zhao (109079178)

#include <iostream>
#include "Utilities.h"
#include "ItemSet.h"

namespace sict {

	static size_t MaxNameWidth = 0;

	ItemSet::ItemSet(std::string& src) {
		bool go_on = true;
		size_t current_pos = 0;
		size_t col_index = 0;
		Utilities util;

		while (go_on && col_index < 4) { //go_on is true which means keep on moveing
			try {
				if (col_index == 0) {
					name = util.extractToken(src, current_pos);
					field_width = util.getFieldWidth();
					if (field_width > MaxNameWidth) {
						MaxNameWidth = field_width;
					}
				}

				if (col_index == 1) {
					serialNumber = (unsigned)std::stoi(util.extractToken(src, current_pos));//string to intger to unsinged
				}

				if (col_index == 2) {
					Quantity = (unsigned)std::stoi(util.extractToken(src, current_pos));
				}

				if (col_index == 3) {
					description = util.extractToken(src, current_pos);
				}
			}
			catch (const char* err_msg) {
				go_on = false;
				std::cout << err_msg << std::endl;
			}
			col_index++;
		}
	}

	const std::string& ItemSet::getName() const{
		return name;
	}

	const unsigned ItemSet::getSerialNumber() const{
		return serialNumber;
	}

	const unsigned ItemSet::getQuantity() const{
		return Quantity;
	}

	ItemSet& ItemSet::operator--() {
		Quantity--;
		serialNumber++;
		return *this;
	}

	void ItemSet::display(std::ostream& os, bool full) const {
		
		if (full) {
			os.width(MaxNameWidth);
			os.setf(std::ios::left);
			os << name;
			os.unsetf(std::ios::left);
			os << " [";
			os.width(5);
			os.fill('0');
			os << serialNumber << "] ";
			os.fill(' ');
			os << "Quantity ";
			os.width(3);
			os.setf(std::ios::left);
			os << Quantity;
			os.unsetf(std::ios::left);
			os << "Description: " << description << std::endl;

		}
		else {
			os.width(MaxNameWidth);
			os.setf(std::ios::left);
			os << name;
			os.unsetf(std::ios::left);
			os << " [";
			os.width(5);
			os.fill('0');
			os << serialNumber << "] ";
		}



	}

	
}