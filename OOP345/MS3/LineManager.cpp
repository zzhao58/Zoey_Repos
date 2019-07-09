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
		
		std::vector<size_t>::iterator it = std::find(p_nextStations.begin(), p_nextStations.end(), p_stations.size());
		lastStation = it - p_nextStations.begin();

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
		/*
		std::vector<std::thread> threads;
		for (size_t i = 0; i < stations.size(); i++) {
			
			threads.push_back(std::thread([&]() {
				
				if (!stations[i]->ordersQueue.empty()) {    //use Si insteadof stations[i]
					stations[i]->fill(os);
				} 
				
				os << "--> " << stations[i]->ordersQueue.front().getNameProduct() << " moved from " << stations[i]->itemset.getName() << " to ";
				if (i!=lastStation){
					if (stations[i]->hasAnOrderToRelease()) {
						stations[nextStations[i]]->ordersQueue.push(stations[i]->ordersQueue.front());
						os << stations[nextStations[i]]->itemset.getName() << std::endl;
						stations[i]->ordersQueue.pop();
					}
				}
				else {
					std::string completedstr;
					completedstr = (stations[i]->ordersQueue.front().isFilled()) ? "Completed Set" : "Incomplete Set";
					os << completedstr << std::endl;
				}
			
			}));
		}
		
		for (auto& thread : threads)
			thread.join();

		return (stations[lastStation]->ordersQueue.size() == orders.size())? true:false;
		*/

		for_each(stations.begin(), stations.end(), [&](auto& si) { si->fill(os);} );
		
		CustomerOrder releasedOrder;
		for (size_t i = 0; i < stations.size(); i++) {
			if (stations[i]->hasAnOrderToRelease()) {
				if (i != lastStation) {
					stations[i]->pop(releasedOrder);
					os << " --> " << releasedOrder.getNameProduct()
						<< " moved from " + stations[i]->getName() << " to " << stations[nextStations[i]]->getName() << std::endl;
					*stations[nextStations[i]] += std::move(releasedOrder);
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