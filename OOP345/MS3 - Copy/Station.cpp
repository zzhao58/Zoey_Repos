
#include "Station.h"


namespace sict {
	Station::Station(const std::string& src) {
		itemset = ItemSet(src);
	}

	void Station::display(std::ostream& os) const {
		itemset.display(os, true);
	}

	void Station::fill(std::ostream& os) {
		if (!ordersQueue.empty()) {
			ordersQueue.front().fillItem(itemset, os);
		}
	}

	const std::string& Station::getName() const {
		return itemset.getName();
	}

	bool Station::hasAnOrderToRelease() const {
		return (!ordersQueue.empty() && (ordersQueue.front().isItemFilled(itemset.getName()) || itemset.getQuantity() == 0));
	}

	Station& Station::operator--() {		//pre-fix
		--itemset;
		return *this;
	}

	Station& Station::operator+=(CustomerOrder&& order) {
		ordersQueue.push(order);
		return *this;
	}

	bool Station::pop(CustomerOrder& ready) {
		ready = ordersQueue.front();
		ordersQueue.pop();   //remove
		return hasAnOrderToRelease();
	}

	void Station::validate(std::ostream& os) const {
		os << " getName(): " << itemset.getName() << std::endl;
		os << " getSerialNumber(): " << itemset.getSerialNumber() << std::endl;
		os << " getQuantity(): " << itemset.getQuantity() << std::endl;
	}
}
