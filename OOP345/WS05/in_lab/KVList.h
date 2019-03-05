#ifndef SICT_KVLIST_H
#define SICT_KVLIST_H

#include <iostream>
#include "KVPair.h"

namespace sict {
	template<class T>
	class KVList {
		T* list;
		size_t current_number;
	public:
		KVList() {
			list = nullptr;
			current_number = 0u;
		}

		KVList(int n) {
			if (n > 0) {
				list = new T[n];
				current_number = n;
			}
			else {
				KVList();
			}
		}

		KVList(KVList&& kl) { 
			list = kl.list;
			current_number = kl.current_number;

			kl.list = nullptr;
			kl.current_number = 0;
		}
		~KVList() {
			delete [] list;
			list = nullptr;
		}

		const T& operator[](size_t i) const {
			return list[i];
		}

		template<typename F>
		void display(std::ostream& os, F f) const {
			for (size_t i = 0; i < current_number; i++) {
				list[i].display(os, f);
			}
		}

		void push_back(const T& t) {
			static size_t n = 0;
			if (n < current_number) {
				list[n] = t;
				++n; 
			}
			
		}
			
		KVList& operator=(const KVList&) = delete;
		KVList& operator=(KVList&&) = delete;
		KVList(KVList&) = delete;


	};

}
#endif 

