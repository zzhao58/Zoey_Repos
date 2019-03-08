// Product.h
// Zhi Zhao(109079178)

#ifndef SICT_PRODUCT_H
#define SICT_PRODUCT_H

#include <iostream>
#include <string>
#include "iProduct.h"

class Product : public w6::iProduct
	// Holds information about a product that consists of its product number and its cost
{
	std::string ProductID;
	double price;
public:
	Product();
	Product(std::string& ProductNumber, double ProductCost);
	~Product();

	double price() const;
	void display(std::ostream& os) const;
	

};

void Product::display(std::ostream& os) const;
Product::operator<<(std::ostream& os, const iProduct& p);
#endif 
