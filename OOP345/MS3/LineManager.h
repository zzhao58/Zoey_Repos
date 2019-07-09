#ifndef LINEMANAGER_SICT_H
#define LINEMANAGER_SICT_H

#include <iostream>
#include <vector>
#include "Station.h"
#include "CustomerOrder.h"

namespace sict {
	class LineManager {
		std::vector<Station*> stations;
		std::vector<CustomerOrder> orders;
		std::vector<size_t> nextStations;
		std::deque<CustomerOrder> completed;
		std::deque<CustomerOrder> incomplete;
		size_t firstStation{ 0u };
		size_t lastStation{ 0u };

	public:
		LineManager();
		LineManager(std::vector<Station*>&, std::vector<size_t>&, std::vector<CustomerOrder>&, size_t, std::ostream&);
		void display(std::ostream& os) const;
		bool run(std::ostream& os);
	};
}

#endif
