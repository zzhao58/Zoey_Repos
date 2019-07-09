#ifndef SICT_GROCERY_H
#define SICT_GROCERY_H

#include <iostream>
#include <string>
#include <array>
namespace sict {
	class Grocery {

		std::string description;
		double price;
		std::string TaxStr;
	public:
		Grocery(const std::string, double, std::string);
		Grocery&& operator=(Grocery&&);
		Grocery(Grocery&&);
		void display(std::ostream&) const;
	};

}

#endif

======================================== =
try { cart.push_back(std::move(Gerocery(description, price, tax))); }
catch (const char * msg) {
	std::cout << msg << "File open failed!" << std::endl;
}