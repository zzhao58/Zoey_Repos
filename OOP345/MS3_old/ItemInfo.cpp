#include <algorithm>
#include "Utilities.h"
#include "ItemInfo.h"

namespace sict {
	ItemInfo::ItemInfo() {
		Name = "";
		serialNumber = 0u;
		IsFilled = false;
	}

	
	ItemInfo::ItemInfo(const std::string& src) {
		Name = src;
		serialNumber = 0u;
		IsFilled = false;        //initialization

	}

	std::string ItemInfo::getName() const {
		return Name;
	}

	unsigned ItemInfo::getserialNumber() const {
		return serialNumber;
	}

	void ItemInfo::setserialNumber(unsigned sn) {//assign serialnumber to current
		serialNumber = sn;
	}


	bool ItemInfo::getIsFilled() const { //get status
		return IsFilled;
	}

	void ItemInfo::setIsFilled(bool filled) {
		IsFilled = filled;
	}

}