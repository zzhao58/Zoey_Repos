
#include <queue>
#include <vector>
#include <algorithm>
#include <thread>
#include "LineManager.h"
#include "Utilities.h"

namespace sict {

	LineManager::LineManager(std::vector<Station*>& vec_stationPtrs, std::vector<size_t>& vec_nextstation, std::vector<CustomerOrder>& cust_orders, size_t start_station, std::ostream& os) {
		con_stations = vec_stationPtrs;
		for (size_t i = 0; i < cust_orders.size(); i++) {
			*con_stations[start_station] += std::move(cust_orders[i]);
		}
		//for (auto i : cust_orders)
		//	*con_stations[start_station] += std::move(i);

		con_nextstation = vec_nextstation;
		orderNum = cust_orders.size();

		std::vector<size_t>::iterator it;
		it = std::find(vec_nextstation.begin(), vec_nextstation.end(), vec_nextstation.size());
		laststation = it - vec_nextstation.begin();
	}

	void LineManager::display(std::ostream& os) const {
		os << "COMPLETED ORDERS" << std::endl;
		std::queue<CustomerOrder> ordersCopy1 = con_stations[laststation]->ordersQueue;
		while (!ordersCopy1.empty()) {
			if (ordersCopy1.front().isFilled()) {   //total filled
				ordersCopy1.front().display(os, true);
			}
			ordersCopy1.pop();
		}

		os << "INCOMPLETED ORDERS" << std::endl;
		std::queue<CustomerOrder> ordersCopy2 = con_stations[laststation]->ordersQueue;
		while (!ordersCopy2.empty()) {
			if (!ordersCopy2.front().isFilled()) {  //total not filled
				ordersCopy2.front().display(os, true);
			}
			ordersCopy2.pop();
		}
	}

	bool LineManager::run(std::ostream& os) {
		std::vector<std::thread> threads;

		for (size_t i = 0; i < con_stations.size(); i++) {
			threads.push_back(std::thread(
				[&]() {
					if (!con_stations[i]->ordersQueue.empty()) {//the queue of each station object is not empty, i will to fill
						con_stations[i]->ordersQueue.front().fillItem(con_stations[i]->itemset, os);//i wiil go to exactly station which include the first cus_order in queue to fill
					}

					if (i != laststation) {//make sure wether is the last station,if it is not the last station, we need to pass the first order to next station
						size_t next_idx = con_nextstation[i];//I want to find the index of the next station
						if (con_stations[i]->hasAnOrderToRelease()) {//make sure wether has order need to pass
							con_stations[next_idx]->ordersQueue.push(con_stations[i]->ordersQueue.front());//push to the next station,note: queue only have push, don't have push_back
							os << "--> " << con_stations[i]->ordersQueue.front().getNameProduct() << " moved from ";
							os << con_stations[i]->getName() << " to " << con_stations[next_idx]->getName() << std::endl;//print
							con_stations[i]->ordersQueue.pop();//remove the first customer order after coping .
						}
					}
					else {//if it is the last station
						std::string IsCompleted;
						IsCompleted = (con_stations[i]->ordersQueue.front().isFilled()) ? "Completed Set" : "Incomplete Set";
						os << "--> " << con_stations[i]->ordersQueue.front().getNameProduct() << " to " << IsCompleted;
					}
				}
			));
		}

		for (auto& thread : threads)
			thread.join();

		return (con_stations[laststation]->ordersQueue.size() == orderNum) ? true : false;

	}
}