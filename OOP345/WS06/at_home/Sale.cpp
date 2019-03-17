//Sale.cpp
//Zhi Zhao(109079178)

#include <iostream>
#include <string>
#include <fstream>
#include "Sale.h"

extern int FW;
namespace sict
{
	Sale::Sale(const char* filename) {
		unsigned lineNum = 0;
		std::ifstream fin(filename);
		std::string line; 

		try{
			while (std::getline(fin, line)){
				lineNum++;
			}
			fin.close();

			fin.open(filename);
			for (size_t i = 0; i < lineNum; i++){
				iProduct_container.push_back(dynamic_cast<Product*>(readRecord(fin)));
			}
			
			fin.close();
		}
		catch(const char* msg){
			std::cout << msg << " File open failed!" << std::endl;
		}
	}


	void Sale::display(std::ostream& os) const {
		os.width(FW);
		os.setf(std::ios::right); 
		os << "Product No";

		os.width(FW);
		os.setf(std::ios::right);
		os << "Cost";

		os.width(8);
		os.setf(std::ios::left);
		os << "Taxable";

		os << std::endl;

		double total = 0;
		for (size_t i = 0; i < iProduct_container.size(); i++) {
			iProduct_container[i]->display(os);
			std::cout << std::endl;
			total += iProduct_container[i]->price();
		}

		os.width(FW);
		os.setf(std::ios::right);
		os << "Total";

		os.width(FW);
		os.setf(std::ios::right); 
		os.fixed;
		os.precision(2);
		os << total << std::endl;
		
	}


}

