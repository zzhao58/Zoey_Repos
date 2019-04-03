//Station.cpp
//Zhi Zhao (109079178)

#include <functional>
#include "Station.h"
#include "ItemSet.h"


namespace sict {
	Station::Station(const std::string& src) {
		ordersQueue = std::queue<CustomerOrder>();
		itemset = ItemSet(src);
	}
	
	void Station::display(std::ostream& os) const {
		itemset.display(os, true);
	}

	void Station::fill(std::ostream& os) {
		if (!ordersQueue.empty()) {
			CustomerOrder curOrder = ordersQueue.front();  //front() or back()
			curOrder.fillItem(itemset, os);
		}
	}

	const std::string& Station::getName() const {
		return itemset.getName();
	}

	bool Station::hasAnOrderToRelease() const {
		if ( !ordersQueue.empty() && (ordersQueue.front().isItemFilled(itemset.getName())||itemset.getQuantity()==0) ){
			return true;
		}
		else {
			return false;
		}
	}

	Station& Station::operator--() {
		--itemset;
		return *this;
	}

	Station& Station::operator+=(CustomerOrder&& order) {
		ordersQueue.push(std::move(order));
		return *this;
	}

	bool Station::pop(CustomerOrder& ready) {
		if (hasAnOrderToRelease()) {
			ready = ordersQueue.front();   
			ordersQueue.pop();
			return true;
		}
		else {
			return  false;
		}
	}

	void Station::validate(std::ostream& os) const {
		os << "getName(): " << itemset.getName() << std::endl;
		os << "getSerialNumber(): " << itemset.getSerialNumber() << std::endl;
		os << "getQuantity(): " << itemset.getQuantity() << std::endl;
	}

	Station::~Station() {

	}
}