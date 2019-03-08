#ifndef W6_IPRODUCT_H
#define W6_IPRODUCT_H
#include <fstream>

namespace w6 {

	class iProduct {
	public:
		virtual double price() const = 0;
		virtual void display(std::ostream& os) const;

	};
}

#endif