// TaxableProduct.h
// Zhi Zhao(109079178)

#ifndef SICT_TAXABLEPRODUCT_H
#define SICT_TAXABLEPRODUCT_H

#include <iostream>
#include <string>
#include <array>
#include "Product.h"

namespace sict {

	class TaxableProduct : public Product{
		std::array<float, 2> taxRate = { 0.13f, 0.08f };
		char TaxCode;
	public:
		TaxableProduct(unsigned, double , char );
		double price() const;
		void display(std::ostream&) const;		
	};
}

#endif