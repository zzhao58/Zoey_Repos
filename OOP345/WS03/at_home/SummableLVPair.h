#ifndef SICT_SUMMABLELVPAIR_H
#define SICT_SUMMABLELVPAIR_H


#include<iostream>
#include"LVPair.h"

namespace sict {

	template <typename L, typename V>
	class SummableLVPair : public LVPair<L, V> {
		static V		initValue;
		static size_t	minWidth;
	public:
		SummableLVPair() {};
		SummableLVPair(const L& label, const V& v) : LVPair<L,V>(label, v) {
			if (minWidth < label.size()) {
				minWidth = label.size();
			}
		}

		static const V& getInitialValue() {
			return initValue;
		}


		V sum(const L& label, const V& sum) const {
			return label == this->label ? sum + this->value : sum;

		}

		void display(std::ostream& os) const {
			os.setf(std::ios::left);
			os.width(minWidth);
			LVPair<L, V>::display(os);
		}

	};

	template <typename L, typename V>
	size_t SummableLVPair<L, V>::minWidth = 0u;

	template<>
	int SummableLVPair<std::string, int>::initValue = 0;

	template<>
	std::string SummableLVPair<std::string, std::string>::initValue = "";

	template<>
	std::string SummableLVPair<std::string, std::string>::sum(const std::string& label, const std::string& sum) const {
		if(sum.length() == 0)
			return (label == this->label) ? this->value : sum;
		else
			return (label == this->label) ? sum + " " + this->value : sum;
	}; 

}

#endif