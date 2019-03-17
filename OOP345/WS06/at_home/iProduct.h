#ifndef SICT_IPRODUCT_H
#define SICT_IPRODUCT_H
#include <fstream>
#include <string>

namespace sict {

	class iProduct {

	public:
		virtual double price() const = 0;
		virtual void display(std::ostream& os) const = 0;
	};
}

#endif
