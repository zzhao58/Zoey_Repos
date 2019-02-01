//List.h
//Zhi Zhao(109079178)



#ifndef SICT_LVPPAIR_H
#define SICT_LVPPAIR_H

#include<iostream>
namespace sict {

	template <typename T, typename V>
	class LVPair {
		T lable;
		V value;
	public:
		LVPair() :lable(0), value(0) {};

		LVPair(const T& p_label, const V& p_value) {
			lable = p_label;
			value = p_value;
		}

		void display(std::ostream& os) const {
			os << lable << ":" << value << std::endl;
		}
	};

	template <typename T, typename V>
	std::ostream& operator<<(std::ostream& os, const LVPair<T,V>& pair) {  //os<<pair
		pair.display(os);
		return os;
	} 
}
#endif