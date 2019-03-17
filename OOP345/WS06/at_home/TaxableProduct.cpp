// TaxableProduct.cpp
// Zhi Zhao(109079178)

#include <iomanip>
#include "TaxableProduct.h"

extern int FW;
namespace sict {

	TaxableProduct::TaxableProduct(unsigned P_Number, double P_Price, char Tax) :Product(P_Number, P_Price) {
		TaxCode = Tax;
	}

	double TaxableProduct::price() const {
		double aftertaxprice;
		if (TaxCode == 'H') {
			aftertaxprice = Product::price() * (1 + taxRate[0]);
		}
		else if (TaxCode == 'P') {
			aftertaxprice = Product::price() * (1 + taxRate[1]);
		}
		else {
			std::cout << "TaxCode should ONLY be 'H' or 'P'." << std::endl;
		}

		return aftertaxprice;
	}

	void TaxableProduct::display(std::ostream &os) const {
		Product::display(os);
		if (TaxCode == 'H')
			std::cout << " " << "HST";
		if (TaxCode == 'P')
			std::cout << " " << "PST";
	}

	iProduct* readRecord(std::ifstream& file) {
		iProduct* iProduct_ptr = nullptr;
		unsigned t_productID;
		double t_productPrice;
		char dim, t_TaxCode;

		if (file.is_open()) {
			file >> t_productID;
			file >> t_productPrice;
			
			dim = file.get();
			if (dim == ' ') {
				file >> t_TaxCode;

				if (t_TaxCode == 'H' || t_TaxCode == 'P') {
					iProduct_ptr = new TaxableProduct(t_productID, t_productPrice, t_TaxCode);
				}
				else {
					std::cout << "TaxCode should ONLY be 'H' or 'P'." << std::endl;
				}
			}
			else {
				iProduct_ptr = new Product(t_productID, t_productPrice);
			}
		}
		else {
			std::cout << "passed file object can not open!" << std::endl;
		}

		return iProduct_ptr;
	}
	 
}
