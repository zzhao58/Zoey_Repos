//KVPair.h
//zhi zhao (109079178)
#ifndef SICT_KVLIST_H
#define SICT_KVLIST_H

#include <iostream>
#include "KVPair.h"

namespace sict {
	template<class T>
	class KVList {
		T* list;
		size_t max;
		size_t current_number;
	public:
		KVList() : list(nullptr), max(0u),current_number(0u) {}

		KVList(int n) {
			if (n > 0) {
				list = new T[n];
				max = n;
				current_number = 0;
			}
			else {
				KVList();
				throw 1;
			}
		}

		KVList(KVList&& src) { //move construct
			if (this != &src) {
				list = src.list;
				max = src.max;
				current_number = src.current_number;

				src.list = nullptr;
				src.max = 0;
				src.current_number = 0;
			}
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
			if (current_number != 0) {
				for (size_t i = 0; i < current_number; i++) {
					list[i].display(os, f);
				}
			}
		}

		void push_back(const T& t) {
			//static size_t n = 0;
			if (current_number < max) {
				list[current_number] = t;
				++current_number;
			}
			else {
				throw 2;
			}
			
		}
			
		KVList& operator=(const KVList&) = delete;
		KVList& operator=(KVList&&) = delete;
		KVList(const KVList&) = delete;
	};

}
#endif 

