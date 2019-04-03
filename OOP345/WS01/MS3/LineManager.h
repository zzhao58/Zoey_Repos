#ifndef SICT_LINMANAGER_H
#define SICT_LINMANAGER_H
#include <vector>
#include "Station.h"

namespace sict {
	class LineManager {
		std::vector<Station*> con_stations;
		std::vector<size_t> con_nextstation;
		size_t orderNum;
		size_t laststation;
	public:
		LineManager(std::vector<Station*>&, std::vector<size_t>&, std::vector<CustomerOrder>&, size_t, std::ostream&);
		void display(std::ostream& os) const;
		bool run(std::ostream& os);		
	};
}
#endif
