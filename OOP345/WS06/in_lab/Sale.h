//Sale.h
//Zhi Zhao(109079178)

#ifndef SICT_SALE_H
#define SICT_SALE_H

#include <iostream>
#include <fstream>
#include <deque>
#include "Product.h"

namespace sict {

	class Sale {
		std::deque<Product*> iProduct_container;
	public:
		Sale(const char*);
		void display(std::ostream& os) const;

	};
}
#endif
