#ifndef SICT_DATATABLE_H
#define SICT_DATATABLE_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <numeric>
#include <algorithm>
#include <fstream>
extern int FW;
extern int ND;

namespace sict {
	template <typename T>
	class DataTable {
		std::vector<T> x;
		std::vector<T> y;

	public:
		DataTable(std::ifstream& file){
			T p_x, p_y;

			if (file.is_open())
			{
				while (file >> p_x >> p_y)
				{
					x.push_back(p_x);
					y.push_back(p_y);
				}
			}
		}

		T mean() const
		{
			T s;
			s = std::accumulate(y.begin(), y.end(), (T)0) / y.size();  // how to make sure you need sum of Y not sum of X
			return s;
		}

		T sigma() const
		{
			T upper, s;
			T sigma{ 0 };

			s = std::accumulate(y.begin(), y.end(), (T)0) / y.size();

			upper = std::accumulate(y.begin(), y.end(), (T)0, [s](T a, T b) {return a + (b - s)*(b - s); }); //how convert to the formular

			sigma = std::sqrt(upper / (y.size() - 1));
			return sigma;
		}



		T median() const
		{
			T median{ 0 };
			std::vector<T> a = y;

			std::sort(a.begin(), a.end());   // why didn't write lambda expresstion

			return a[y.size() / 2];
		}

		T slope() const
		{
			T slope{ 0 };
			T count1, count2, count3, count4;
			count1 = std::inner_product(x.begin(), x.end(), y.begin(), (T)0);
			count2 = std::accumulate(x.begin(), x.end(), (T)0);
			count3 = std::accumulate(y.begin(), y.end(), (T)0);
			count4 = std::inner_product(x.begin(), x.end(), x.begin(), (T)0);

			slope = (x.size()*count1 - count2 * count3) / ((x.size())*count4 - count2 * count2);

			return slope;
		}

		T intercept() const
		{
			T intercept{ 0 };
			T count1, count2;

			count1 = std::accumulate(y.begin(), y.end(), (T)0);
			count2 = std::accumulate(x.begin(), x.end(), (T)0);

			intercept = (count1 - slope()*count2) / y.size();

			return intercept;
		}

		void displayData(std::ostream& os) const
		{
			os << "Data Values" << std::endl;
			os << "------------" << std::endl;
			os << std::setw(FW) << "x" << std::setw(FW) << "y" << std::endl;

			for (size_t i = 0; i < x.size() && i < y.size(); i++)
			{
				os << std::fixed << std::setprecision(ND) << std::setw(FW) << x[i] << std::setw(FW) << y[i] << std::endl;
			}
		}

		void displayStatistics(std::ostream& os) const
		{
			os << std::endl;
			os << "Statistics" << std::endl;
			os << "----------" << std::endl;
			os << std::setw(FW) << std::right << "y mean"    << std::setw(5) << "=" << std::setw(9) << std::right << mean() << std::endl;
			os << std::setw(FW) << std::right << "y sigma"   << std::setw(5) << "=" << std::setw(9) << std::right << sigma() << std::endl;
			os << std::setw(FW) << std::right << "y median"  << std::setw(5) << "=" << std::setw(9) << std::right << median() << std::endl;
			os << std::setw(FW) << std::right << "slope"     << std::setw(5) << "=" << std::setw(9) << std::right << slope() << std::endl;
			os << std::setw(FW) << std::right << "intercept" << std::setw(4) << "=" << std::setw(9) << std::right << intercept() << std::endl;
		}
	};
}
#endif