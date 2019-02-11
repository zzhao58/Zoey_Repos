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
		LVPair() : label(""), value(0) {};

		LVPair(const L& p_label, const V& p_value) {
			label = p_label;
			value = p_value;
		}

		virtual void display(std::ostream& os) const {
			os << label << " : " << value << std::endl;
		}
	};

	template<>
	LVPair<std::string, std::string>::LVPair(): label(""), value("") {};

	template <typename L, typename V>
	std::ostream& operator<<(std::ostream& os, const LVPair<L,V>& pair) {  //os<<pair
		pair.display(os);
		return os;
	} 

	//derived from base class which is LVPair
	template <typename L, typename V>
	class SummableLVPair : public LVPair<L, V> {
		static V		initValue;
		static size_t	minWidth;
	public:
		SummableLVPair() {};
		SummableLVPair(const L& label, const V& v) : LVPair<L, V>(label, v) {//we can get the max width
			if (minWidth < label.size()) {
				minWidth = label.size();
			}
		}

		static const V& getInitialValue() {
			return initValue;
		}


		V sum(const L& label, const V& sum) const {//label:outside tpye, sun:up to now the sum of value
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

	template<>//speciallize depens on the second parameter
	int SummableLVPair<std::string, int>::initValue = 0;

	template<>
	std::string SummableLVPair<std::string, std::string>::initValue = "";

	template<>//when recievd string and string , sum should be concate not plus together
	std::string SummableLVPair<std::string, std::string>::sum(const std::string& label, const std::string& sum) const {
		return (label == this->label) ? sum + " " + this->value : sum;
	};
}
#endif