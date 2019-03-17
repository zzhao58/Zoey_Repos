//Product.cpp
//Zhi Zhao(109079178)

#include <string>
#include <sstream> 
#include <iomanip>
#include <fstream>
#include <iostream>
#include "Product.h"

extern int FW;

namespace sict {
	
	Product::Product(unsigned P_ID, double P_price) {
		productID = P_ID;
		productPrice = P_price;
	}

	double Product::price() const{
		return productPrice;
	}

	void Product::display(std::ostream& os) const{
		os << std::setw(FW) << productID << std::setw(FW) << std::fixed << std::setprecision(2) << productPrice;
	}

	std::ostream& operator<<(std::ostream& os, const iProduct& p) {
		p.display(os);
		os << std::endl;
		return os;
	}

	//iProduct* readRecord(std::ifstream& file) {
	//	iProduct* iProduct_ptr = nullptr;
	//	int t_productID;
	//	double t_productPrice;
	//
	//	if (file.is_open()) {
	//		
	//		if (file) {
	//			file >> t_productID;         //">> could auto ignore the white spaces which inluce ' ',tab,newline"
	//			file >> t_productPrice;
	//			iProduct_ptr = new Product(t_productID, t_productPrice);
	//		}
	//		else {
	//			std::cout << "Can not read the file." << std::endl;
	//		}
	//	}
	//	else {
	//		std::cout << "passed file object can not open!" << std::endl;
	//	}

	//	return iProduct_ptr;
	//}



}