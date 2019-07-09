//LineManager.h
//Zhi Zhao(109079178)
#ifndef LINEMANAGER_SICT_H
#define LINEMANAGER_SICT_H

#include <iostream>
#include <vector>
#include "Station.h"
#include "CustomerOrder.h"

namespace sict {
	class LineManager {
		std::vector<Station*> stations; 
		std::vector<CustomerOrder> orders; //customer order
		std::vector<size_t> nextStations;  //nextStation's index
		std::deque<CustomerOrder> completed; //complate
		std::deque<CustomerOrder> incomplete;  //imcomplate
		size_t firstStation{ 0u }; //put index
		size_t lastStation{ 0u };   //put index

	public:
		LineManager();
		LineManager(std::vector<Station*>&, std::vector<size_t>&, std::vector<CustomerOrder>&, size_t, std::ostream&);
		void display(std::ostream& os) const;
		bool run(std::ostream& os);
	};
}

#endif
