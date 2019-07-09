#include <iomanip>
#include "Grocery.h"

extern int FWPrice;
extern int FWdescription;
namespace sict{

	Grocery::Grocery(const std::string p_description, double p_price, std::string p_tax) {
		description = p_description;
		price = p_price;
		std::string TaxCode = p_tax.substr(1, 1);

		try {
			if (TaxCode == "H" || TaxCode == "P") {
				TaxStr = p_tax;
			}
			else {
				TaxStr = p_tax;
				throw "TaxCode should ONLY be 'H' or 'P'.";
			}
		}
		catch (const char* msg) {
			std::cout << "error" << std::endl;
		}
	}

	Grocery&& Grocery::operator=(Grocery&& src) {
		if (this != &src) {
			description = src.description;
			price = src.price;
			TaxStr = src.TaxStr;
			src.description = "";
			src.price = 0;
			src.TaxStr = "";
		}
		return std::move(*this);
	}

	Grocery::Grocery(Grocery&& src) {
		*this = std::move(src);
	}
	

	void Grocery::display(std::ostream& os) const {
		if (TaxStr.substr(1, 1) != "H"&&TaxStr.substr(1, 1) != "P") {
			os << "*unlisted tax symbol* : " << std::setw(FWdescription) << left << description
				<< std::setw(FWPrice) << std::fixed << std::setprecision(2) << price
				<< " " << TaxStr << std::endl;
		}
		else {
			os << std::setw(FWdescription) << description
			   << std::setw(FWPrice) << std::fixed << std::setprecision(2) << price
			   << " " << TaxStr << std::endl;
		}

	}




}



