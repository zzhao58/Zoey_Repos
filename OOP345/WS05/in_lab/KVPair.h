#ifndef SICT_KVPAIR_H
#define SICT_KVPAIR_H

extern int fieldWidth;

namespace sict {

	template <typename K,typename V>
	class KVPair {
		K label;
		V value;
	public:
		KVPair() {}

		KVPair(const K& p_k, const V& p_v) {
			 label = p_k;
			 value = p_v;
		}

		template<typename F>
		void display(std::ostream& os, F f) const {

			 os << std::left << std::setw(fieldWidth);
			 os << label << " : "; 
			 os << std::right << std::setw(fieldWidth);
			 os << value << std::setw(fieldWidth) << f(value) << std::endl;
		}

	};
}

#endif 

