//CustomerOrder.h
//Zhi Zhao (109079178)

#ifndef CUSTOMERORDER_SICT_H
#define CUSTOMERORDER_SICT_H

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include "ItemInfo.h"
#include "ItemSet.h"


const int MAX = 5;
namespace sict{

	class CustomerOrder {
		std::string CustomerName;
		std::string ProductName;
		std::vector<ItemInfo> Items;
		static size_t field_width;
		
	public:
		CustomerOrder();
		CustomerOrder(const std::string&);
		~CustomerOrder();
		void fillItem(ItemSet&, std::ostream&); //check inventor full?
		bool isFilled() const;
		bool isItemFilled(const std::string& ) const;
		std::string getNameProduct() const;
		void display(std::ostream&, bool = false) const;  // argument default value should appear in declaration.
		static size_t getfieldWidth();		
	};

}

#endif


