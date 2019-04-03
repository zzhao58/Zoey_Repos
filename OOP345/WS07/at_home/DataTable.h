//DataTable.h
//Zhi Zhao(109079178)
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
		DataTable(std::ifstream& file) {
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
			s = std::accumulate(y.begin(), y.end(), (T)0) / y.size();  
			return s;
		}

		T sigma() const
		{
			T upper, Y_mean;
			T sigma{ 0 };

			Y_mean = mean();

			upper = std::accumulate(y.begin(), y.end(), (T)0, [=](T a, T b) {return a + (b - Y_mean)*(b - Y_mean); }); 

			sigma = std::sqrt(upper / (y.size() - 1));
			return sigma;
		}



		T median() const
		{
			
			std::vector<T> a = y;

			std::sort(a.begin(), a.end(), [](T i, T j){ return i > j; });   // why didn't write lambda expresstion

			return a[y.size() / 2];//we get a index from []. a[i]=value;
		}

		T slope() const
		{
			T slope;
			T exp1, exp2, exp3, exp4;
			exp1 = std::inner_product(x.begin(), x.end(), y.begin(), (T)0);
			exp2 = std::accumulate(x.begin(), x.end(), (T)0);
			exp3 = std::accumulate(y.begin(), y.end(), (T)0);
			exp4 = std::inner_product(x.begin(), x.end(), x.begin(), (T)0);

			slope = (x.size()*exp1 - exp2 * exp3) / ((x.size())*exp4 - exp2 * exp2);

			return slope;
		}

		T intercept() const
		{
			T intercept;
			T sum1, sum2;

			sum1 = std::accumulate(y.begin(), y.end(), (T)0);
			sum2 = std::accumulate(x.begin(), x.end(), (T)0);

			intercept = (sum1 - slope()*sum2) / y.size();

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
			os << std::string(" ", 2) << std::right << "y mean    =" << std::setw(9) << std::right << mean() << std::endl;
			os << std::string(" ", 2) << std::right << "y sigma   =" << std::setw(9) << std::right << sigma() << std::endl;
			os << std::string(" ", 2) << std::right << "y median  =" << std::setw(9) << std::right << median() << std::endl;
			os << std::string(" ", 2) << std::right << "slope     =" << std::setw(9) << std::right << slope() << std::endl;
			os << std::string(" ", 2) << std::right << "intercept =" << std::setw(9) << std::right << intercept() << std::endl;
		}
	}; 
}
#endif
 