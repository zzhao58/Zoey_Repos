//CustomerOrder.h
//Zhi Zhao(109079178)

#include <iomanip> //set output ,exm setw
#include <string>
#include "ItemSet.h"
#include "Utilities.h"
#include "CustomerOrder.h"

namespace sict {
	
	size_t CustomerOrder::field_width = 0;

	CustomerOrder::CustomerOrder() {
		CustomerName = "";
		ProductName = "";
		Items = std::vector<ItemInfo>();
	}

	CustomerOrder::CustomerOrder(const std::string& src) {// recieve a whole string which the cumstomer order.
		size_t current_pos = 0;
		std::string ItemStr = "";
		Utilities util;

		size_t n = std::count(src.begin(), src.end(), util.getDelimiter());// get how many "|"

		for (size_t col_index = 0; col_index < n + 1; col_index++) {
			try {
				//CustomerName
				if (col_index == 0) {
					CustomerName = util.extractToken(src, current_pos);
					if (field_width < CustomerName.length()) {
						field_width = CustomerName.length();
					}
				}

				//ProductName
				if (col_index == 1) {
					ProductName = util.extractToken(src, current_pos);
				}

				//Items
				if (col_index >= 2) {
					ItemStr = util.extractToken(src, current_pos);
					Items.push_back(std::move(ItemInfo(ItemStr)));
					//ItemStr="";					
				}				
			}
			catch (const char* err_msg) {				
				std::cout << err_msg << std::endl;
			}
		}

	}

	
	CustomerOrder::~CustomerOrder() { //dellecate the container object
		Items.clear();
	}

	//iteam means one row which make of a object
	void CustomerOrder::fillItem(ItemSet& item, std::ostream& os) {//check inventory statement, if saticified , we need to fix order statment
		for (auto i = Items.begin(); i != Items.end(); i++) {//loop in orderItem
			if ( !i->getIsFilled() && i->getName() == item.getName() && item.getQuantity() > 0 ) {
				i->setserialNumber(item.getSerialNumber());//take one to customer; assign a SerialNumber to order Item
				i->setIsFilled(true);//fix Item status
				--item;
				os << " Filled " << CustomerName << " [" << ProductName << "][" << i->getName() << "][" << i->getserialNumber() << "]" << std::endl;
			}
			else if (!i->getIsFilled() && i->getName() == item.getName() && item.getQuantity() == 0) {
				i->setserialNumber(0);
				i->setIsFilled(false);
				os << " Unable to Fill " << CustomerName << " [" << ProductName << "][" << i->getName() << "][" << i->getserialNumber() << "] out of stock" << std::endl;
			}
			else if ( i->getIsFilled() && i->getName() == item.getName()) {
				os << " Unable to Fill " << CustomerName << " [" << ProductName << "][" << i->getName() << "][" << i->getserialNumber() << "] already filled" << std::endl;
			}
		}
	}
	
	bool CustomerOrder::isFilled() const {
		bool totalFilled = true;
		for (auto i = Items.begin(); totalFilled && i != Items.end(); i++) {
			if ( !i->getIsFilled() ) {
				totalFilled = false;
			}
		}
		return totalFilled;	
	}

	bool CustomerOrder::isItemFilled(const std::string& item) const{ //check repeat Item in one order in loop
		bool itemFilled = true;
		for (auto i = Items.begin(); itemFilled && i != Items.end(); i++) {
			if (i->getName() == item && !i->getIsFilled())
				itemFilled = false;
		}
		return itemFilled;
	}
	
	std::string CustomerOrder::getNameProduct() const {
		size_t spaces = field_width + 1 - CustomerName.length();
		return CustomerName + std::string(spaces,' ') + "[" + ProductName + "]";
	}
	
	size_t CustomerOrder::getfieldWidth() {
		return field_width;
	}

	void CustomerOrder::display(std::ostream& os, bool showDetail) const {
		os << getNameProduct() << std::endl;
		if (!showDetail) {
			for (auto i = Items.begin(); i != Items.end(); i++) {
				os << std::string(field_width + 1, ' ') << i->getName() << std::endl;
			}			
		}
		else {
			for (auto i = Items.begin(); i != Items.end(); i++) {
				std::string fillstr;
				fillstr = (i->getIsFilled()) ? "FILLED" : "MISSING";
				os << std::setw(field_width + 1) << "[" << i->getserialNumber() << "] " << i->getName() << " - " << fillstr << std::endl;
			}
		}

	}

} 


