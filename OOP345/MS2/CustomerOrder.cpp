//CustomerOrder.h
//Zhi Zhao(109079178)

#include <iomanip>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "CustomerOrder.h"
#include "ItemSet.h"
#include "Utilities.h"


namespace sict {
	static size_t MaxNameWidth = 0;
	CustomerOrder::CustomerOrder() {
		Name = "";
		Product = "";
		IteamName = " ";
		col_index = 0u;
		itemList = nullptr;
		field_width = 0u;
	}

	CustomerOrder::CustomerOrder(const std::string& src) {
		bool go_on = true;
		size_t pos = 0u;
		size_t count = 0u;
		size_t itemPos = 0u;
		size_t itemCnt = 0u;
		Utilities util;

		util.setFieldWidth(field_width);
		while (go_on && col_index < 4) {
			try {
				if (col_index == 0) {
					Name = util.extractToken(src, pos);
					field_width = util.getFieldWidth();
					if (field_width > MaxNameWidth) {
						MaxNameWidth = field_width;
					}
				}

				if (col_index == 1) {
					Product = util.extractToken(src, pos);
				}

				if (col_index == 2) {
					IteamName = util.extractToken(src,pos);
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
		//========================================
		while (go_on && col_index < 4) {
			try {
				if (col_index == 0) Name = util.extractToken(src, pos);
				else if (count == 1) Product = util.extractToken(src, pos);
				
				else if (count == 2) {
					itemPos = pos;
					while (more) {
						util.extractToken(record, itemPos);
						itemCnt++;
					}
					col_index = itemCnt;
					itemCnt = 0;
					more = true;
					ItemList = new ItemInfo*[col_index];
				}
				else {
					ItemList[itemCnt] = new ItemInfo(util.extractToken(record, pos, more));
					itemCnt++;
				}
				
			}
		}
		catch (const char* err_msg) {
			go_on = false;
			std::cout << err_msg << std::endl;
		}
		col_index++;
	}
	CustomerOrder::~CustomerOrder() {
		for (size_t i = 0u; i < ItemCount; i++) delete ItemList[i];
		delete[] ItemList;
	}

	//Object move functionality
	CustomerOrder::CustomerOrder(CustomerOrder&& ref) {
		*this = std::move(ref);
	}
	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& ref) {
		if (this != &ref) {
			if (ItemList != nullptr) {
				for (size_t i = 0u; i < ItemCount; i++) delete ItemList[i];
				delete[] ItemList;
			}
			Name = ref.Name;
			Product = ref.Product;
			ItemCount = ref.ItemCount;
			ItemList = ref.ItemList;
			field_width = ref.field_width;
			ref.Name = "";
			ref.Product = "";
			ref.ItemCount = 0;
			ref.ItemList = nullptr;
			ref.field_width = 0;
		}
		return *this;
	}

	//Returns true if order completely filled, false otherwise
	bool CustomerOrder::getOrderFillState() {
		for (size_t i = 0u; i < ItemCount; i++) {
			if (ItemList[i]->FillState == false) return false;
		}
		return true;
	}
	//Returns true if the given item has been filled
	bool CustomerOrder::getItemFillState(std::string s) {
		bool ret = true;
		for (size_t i = 0u; i < ItemCount; i++) {
			if (ItemList[i]->ItemName == s) ret = ItemList[i]->FillState;
			if (ret == false) break;
		}
		return ret;
	}
	//Fills the customer order item if the inventory on Item is available
	void CustomerOrder::fillItem(Item& item_, std::ostream& os) {
		size_t i;
		for (i = 0; i < ItemCount; i++) {
			if (ItemList[i]->ItemName == item_.getName() && ItemList[i]->FillState == false) {
				ItemList[i]->FillState = true;
				ItemList[i]->SerialNumber = item_.getSerialNumber();
				os << (ItemList[i]->FillState ? "Filled" : "UnFilled") <<
					" " << this->Name << ", " << this->Product << "[" << ItemList[i]->ItemName << "]" << std::endl;
			}
		}
	}
	//Displays the details of the CustomerOrder to the ostream object provided
	void CustomerOrder::Display(std::ostream& os) {
		os << Name << std::endl;
		os << Product << std::endl;
		for (size_t i = 0u; i < ItemCount; i++) {
			os << "[" << ItemList[i]->SerialNumber << "]" << ItemList[i]->ItemName << " - "
				<< (ItemList[i]->FillState ? "FILLED" : "MISSING") << std::endl;
		}

	}
}


//=================================================================================================================
namespace ms2 {
	size_t CustomerOrder::field_width;

	CustomerOrder::CustomerOrder(const std::string& custOrder) {
		/*
			custOrder contains the information for a single customer order.
			Task 1 : initializes the number of customer items to 0 and the pointer to customerArray to a safe address.
			Task 2 : Using a Utilities object extract the tokens from custOrder
			Task 3 : Report an exception if any tokens are returned empty
			Task 4 : The constructor allocates dynamic memory for *order
			Task 5 : Sets field_width to the Utilities objects field_width only if the Utilities field_width is greater.
			* custOrder layout*
			customer name field | product name field | Item name field
			*/
		nOrders = 0; order = nullptr;  //  Task 1.

		ms1::Utilities zoolander;
		std::vector<std::string> token;
		size_t pos = 0; bool isMore = true;
		for (unsigned int counter = 0; isMore; counter++) { //  Task 2 Begins

			name = zoolander.nextToken(custOrder, pos, isMore);

			if (isMore) { product = zoolander.nextToken(custOrder, pos, isMore); }

			while (isMore) {
				token.push_back(zoolander.nextToken(custOrder, pos, isMore));
			}

			order = new CustomerItem[token.size()];  //  Task 4.

			for (unsigned int i = 0; i < token.size(); i++) {
				order[i] = CustomerItem(token[i]);
			}

			if (field_width < zoolander.getFieldWidth()) { //  Task 5.
				field_width = zoolander.getFieldWidth();
			}
			nOrders = token.size();
		}
	} //Task 2 Ends. 


	CustomerOrder::CustomerOrder(const CustomerOrder& pCustomerOrder) {
		//DO NOT USE report exception if used.
		throw std::string("Test");
	}
	CustomerOrder::CustomerOrder(CustomerOrder&& pCustomerOrder) NOEXCEPT
		: name(pCustomerOrder.name),
		product(pCustomerOrder.product),
		nOrders(pCustomerOrder.nOrders)
	{
		//Assign class data members from the source object to the oject being created. 
		//Assign source data members to default.

		order = new CustomerItem[nOrders];

		for (unsigned int i = 0; i < nOrders; i++) {
			order[i] = pCustomerOrder.order[i];
		}
		pCustomerOrder.order = nullptr;
		pCustomerOrder.name = ""; pCustomerOrder.product = ""; pCustomerOrder.nOrders = 0;
	}
	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& pCustomerOrder)NOEXCEPT {
		// Task 1 : A conditional statement that performs no operation if you try to assign the object to itself
		// Task 2 : Free the current objects dynamic memory data members; 
		// Task 3 : Assign the rValue data member to the current objects data members. 
		// Task 4 : Free the rValue 
		if (this != &pCustomerOrder) { // Task 1.
			delete[] order; //Task 2.
			name = pCustomerOrder.name; product = pCustomerOrder.product; nOrders = pCustomerOrder.nOrders;
			order = pCustomerOrder.order; // Task 3.

			pCustomerOrder.order = nullptr; //Task 4.
			pCustomerOrder.name = ""; pCustomerOrder.product = ""; pCustomerOrder.nOrders = 0;

		}
		return *this;
	}
	CustomerOrder::~CustomerOrder() {
		//deletes dynamic memory in use by the current object.
		delete[] order;
	}
	unsigned int CustomerOrder::noOrders() const {
		//returns the number of customer items in the current object. 
		return nOrders;
	}
	const std::string& CustomerOrder::operator[](unsigned int i) const {
		// returns a reference to the name of customer item i.
		// reports exception if index is out of bounds. 
		try {
			std::string rName;
			rName = order[i].getName();


		}
		catch (...) {

		}
		return name;
	}
	void CustomerOrder::fill(Item& item) {
		// searches through the customer items and fills those order for the customer 
		// Task 1 : custitems identified by item if any have not been filled.
		// Task 2 : increment code for each customer item filled. This keeps the item code unqiue for each order.

		for (unsigned int i = 0; i < nOrders; i++) {
			if (order[i].asksFor(item)) {
				order[i].fill(item.getCode()); // Task 1.
				item++; //Task 2. 
			}
		}
	}
	void CustomerOrder::remove(Item& item) {
		// Searches through the customer order and removes those items identified by the name of item
		//Does not alter the item's code.
		for (unsigned int i = 0; i < nOrders; i++) {
			if (order[i].getName() == item.getName()) {
				nOrders--;



			}
		}
	}
	bool CustomerOrder::empty() const {
		//return true if the current object is in a safe empty state.
		return (order == nullptr) ? true : false;
	}
	void CustomerOrder::display(std::ostream& os) const {
		/*  Display customer order
			the name of the customer left-justified in a field of width field_width
			the name of the product left-justified in a field of width field_width
			each customer item on a separate line
		*/

		os << std::setw(field_width) << std::setfill(' ') << std::left << name << " :  " << product << std::endl;
		for (unsigned int i = 0; i < nOrders; i++) {
			order[i].display(os);
		}
	}
}