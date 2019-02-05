//List.h
//Zhi Zhao(109079178)



#ifndef SICT_LIST_H
#define SICT_LIST_H

#include <iostream>

 namespace sict {

	 template <typename T, int N>
	 class List {
		 T a[N];
		 static size_t num_element;

	 public:
		 size_t size() const {
			 return num_element;
		 }

		 const T& operator[](size_t i) const {
			 return a[i];
		 }

		 void operator+=(const T& t) {
			 if (num_element < N) {
				 a[num_element] = t;
				 num_element++;
			 }
			 
		 }

		 ~List(){
			 num_element--;
		 }
	};
	 template <typename T, int N>
	 size_t List<T,N>::num_element = 0u;
}
#endif
