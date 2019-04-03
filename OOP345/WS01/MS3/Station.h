#ifndef SICT_STATION_H
#define SICT_STATION_H

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>	
#include <sstream>
#include <queue>
#include "ItemSet.h"
#include "CustomerOrder.h"

namespace sict {
	class Station {
				
	public:
		std::queue<CustomerOrder> ordersQueue;
		ItemSet itemset;

		Station(const std::string&);
		void display(std::ostream& os) const;
		void fill(std::ostream& os);
		const std::string& getName() const;
		bool hasAnOrderToRelease() const;
		Station& operator--();
		Station& operator+=(CustomerOrder&& order);
		bool pop(CustomerOrder& ready);
		void validate(std::ostream& os) const;
		~Station();
	};
}

#endif

