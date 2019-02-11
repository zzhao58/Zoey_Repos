#ifndef SICT_LVLIST_H
#define SICT_LVLIST_H


#include<iostream>
#include "List.h"

namespace sict {

	template <typename T, typename L, typename V, int N>
	class LVList : public List<T,N> {
	public :
		V accumulate(const L& label) const {

			List<T, N> baseList = (List<T, N>)*this;
			V summary = SummableLVPair<L, V>::getInitialValue();
			for (size_t i = 0; i <= baseList.size(); i++) {
				summary = baseList[i].sum(label,summary);
			}
			return summary;
		}
	};
}

#endif
