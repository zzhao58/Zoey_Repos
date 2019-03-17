//CustomerOrder.h
//Zhi Zhao (109079178)

#ifndef CUSTOMERORDER_SICT_H
#define CUSTOMERORDER_SICT_H

#include <iostream>
#include <string>
#include <vector>

namespace sict {
	class CustomerOrder {
		std::string Name;
		std::string Product;
		std::string IteamName;

		unsigned col_index;
		CustomerOrder* itemList;
		static size_t field_width;
		std::vector<CustomerOrder*> CustomerItem;

	public:
		CustomerOrder();
		CustomerOrder(const std::string& record);
		~CustomerOrder();
		void fillItem(ItemSet& item, std::ostream& os);
		bool isFilled() const;
		bool isItemFilled(const std::string& item) const;
		std::string getNameProduct() const;
		void display(std::ostream& os, bool showDetail) const;

	};

}

#endif

//=====================================================================================
namespace ms2 {

	class Item;
	class CustomerItem;

	class CustomerOrder {
		std::string name;          // name of the customer
		std::string product;       // name of the product
		CustomerItem* order;       // address of the customer requests 
		unsigned int nOrders;      // number of requests
		static size_t field_width; // current maximum field width
	public:
		CustomerOrder(const std::string&);
		CustomerOrder(const CustomerOrder&);
		CustomerOrder& operator=(const CustomerOrder&) = delete;
		CustomerOrder(CustomerOrder&&) NOEXCEPT;
		CustomerOrder& operator=(CustomerOrder&&)NOEXCEPT;
		~CustomerOrder();
		unsigned int noOrders() const;
		const std::string& operator[](unsigned int) const;
		void fill(Item&);
		void remove(Item&);
		bool empty() const;
		void display(std::ostream&) const;
	};
}
