#include <algorithm>
#include <thread>
#include "LineManager.h"

namespace sict {
	LineManager::LineManager() {}

	LineManager::LineManager(std::vector<Station*>& p_stations, std::vector<size_t>& p_nextStations, std::vector<CustomerOrder>& p_orders, size_t p_firstStation, std::ostream& os) {
		stations = p_stations;
		orders = p_orders;
		nextStations = p_nextStations;
		firstStation = p_firstStation;
		
		std::vector<size_t>::iterator it = std::find(p_nextStations.begin(), p_nextStations.end(), p_stations.size());  //find position of iterator(point)
		lastStation = it - p_nextStations.begin();  //find index of the last station

		//move all orders to the first stations ordersQueue
		for (auto order : p_orders)
			stations[firstStation]->ordersQueue.push(order);
	}

	void LineManager::display(std::ostream& os) const {
		
		os << "COMPLETED ORDERS" << std::endl;
		for (auto& i : completed)
			i.display(os, true);

		os << "INCOMPLETED ORDERS" << std::endl;
		for (auto& i : incomplete)
			i.display(os, true);
	}

	bool LineManager::run(std::ostream& os) {
		

		for_each(stations.begin(), stations.end(), [&](auto& si) { si->fill(os);} );// automatical fill between itemset and cumstommer order
		
		CustomerOrder releasedOrder;
		for (size_t i = 0; i < stations.size(); i++) {
			if (stations[i]->hasAnOrderToRelease()) {
				if (i != lastStation) {//i means index of station
					stations[i]->pop(releasedOrder);  //from queue to releasedOrder with pop
					os << " --> " << releasedOrder.getNameProduct()
						<< " moved from " + stations[i]->getName() << " to " << stations[nextStations[i]]->getName() << std::endl;
					*stations[nextStations[i]] += std::move(releasedOrder);//move to the next station
				}
				else {
					stations[i]->pop(releasedOrder);
					if (releasedOrder.isFilled()) {
						os << " --> " << releasedOrder.getNameProduct()
						<< " moved from " + stations[i]->getName() << " to " << " Completed Set " << std::endl;
						completed.push_back(std::move(releasedOrder));
					}
					else {
						os << " --> " << releasedOrder.getNameProduct()
						<< " moved from " + stations[i]->getName() << " to " << " Incomplete Set " << std::endl;
						incomplete.push_back(std::move(releasedOrder));
					}
				}
			}
		}

		size_t processed = completed.size() + incomplete.size();
		return (processed == orders.size()) ? true : false;
		
	}
}