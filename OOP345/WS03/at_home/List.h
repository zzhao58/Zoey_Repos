//List.h
//Zhi Zhao(109079178)



#ifndef SICT_LIST_H
#define SICT_LIST_H

#include <iostream>

 namespace sict {

	 template <typename T, int N>
	 class List {
	 protected:
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


	 //derived from base class which is List class.
	 template <typename T, typename L, typename V, int N>
	 class LVList : public List<T, N> {
	 public:
		 V accumulate(const L& label) const {//same label ' value . plus together

			 List<T, N> baseList = (List<T, N>)*this;
			 V summary = SummableLVPair<L, V>::getInitialValue();
			 for (size_t i = 0; i <= baseList.size(); i++) {//size is for how many element for an array
				 summary = baseList[i].sum(label, summary);//call fucntion sun depends on type.
			 }
			 return summary;
		 }
	 };

}
#endif
