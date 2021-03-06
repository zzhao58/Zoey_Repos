// Product.h
// Zhi Zhao(109079178)

#ifndef SICT_PRODUCT_H
#define SICT_PRODUCT_H

#include <iostream>
#include <string>
#include "iProduct.h"

namespace sict {
	class Product : public iProduct {
		// Holds information about a product that consists of its product number and its cost

		unsigned productID;
		double productPrice;

	public:
		Product(unsigned, double);
		double price() const;
		void display(std::ostream& os) const;
	};

	std::ostream& operator<<(std::ostream& os, const iProduct& p);
	iProduct* readRecord(std::ifstream& file);
}
#endif 