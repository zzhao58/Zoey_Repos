//Taxable.h
//zhi zhao (109079178)

#ifndef SICT_TAXABLE_H
#define SICT_TAXABLE_H

namespace sict {
	class Taxable {
		float taxRate;
	public:
		Taxable(float f) :taxRate {f} {}

		float operator()(float price) {
			return price * (1 + taxRate);
		}
	};
}


#endif
