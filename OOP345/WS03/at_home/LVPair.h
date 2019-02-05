//List.h
//Zhi Zhao(109079178)


#ifndef SICT_LVPPAIR_H
#define SICT_LVPPAIR_H

#include<iostream>
namespace sict {

	template <typename L, typename V>
	class LVPair {
	protected:
		L label;
		V value;		
	public:		
		LVPair() {};

		LVPair(const L& p_label, const V& p_value) {
			label = p_label;
			value = p_value;
		}

		virtual void  display(std::ostream& os) const {
			os << label << " : " << value << std::endl;
		}
	};

	template <typename L, typename V>
	std::ostream& operator<<(std::ostream& os, const LVPair<L,V>& pair) {  //os<<pair
		pair.display(os);
		return os;
	} 
}
#endif