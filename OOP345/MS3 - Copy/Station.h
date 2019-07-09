//Station.h
//Zhi Zhao(109079178)
#ifndef STATION_SICT_H
#define STATION_SICT_H

#include<queue>
#include "CustomerOrder.h"
#include "ItemSet.h"

namespace sict {
	class Station {
		
	public:
		std::queue<CustomerOrder> ordersQueue;
		ItemSet itemset;

		Station(const std::string&);
		void display(std::ostream&) const;
		void fill(std::ostream&);
		const std::string& getName() const;
		bool hasAnOrderToRelease() const;
		Station& operator--();
		Station& operator+=(CustomerOrder&&);
		bool pop(CustomerOrder&);
		void validate(std::ostream&) const;
	};
}

#endif