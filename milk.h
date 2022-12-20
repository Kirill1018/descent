#pragma once
#include "products.h"
#include "time.h"
class milk : public product, time, products
{
public:
	milk(string giv_name) : product(giv_name) {};
	time product_1;
	products produce;
	virtual void entrance()
	{
		cout << produce.output_type << endl;
		cout << "молоко" << endl;
		cout << "поступление(числомес€цгод) - ";
		cin >> product_1.entr_per;
		sale();
		write_downs();
		data_output();
	}
	void sale()
	{
		cout << "продажа(числомес€цгод) - ";
		cin >> product_1.sale_per;
	}
	void write_downs()
	{
		cout << "списание(числомес€цгод) - ";
		cin >> product_1.per_of_write_downs;
	}
	void data_output()
	{
		try
		{
			ofstream ofile("product.txt", ios::out);
			ifstream ifile("product.txt", ios::in);
			if (ifile.is_open())
			{
				string line;
				while (ifile >> line) cout << line << ' ';
			}
			ofile << "молоко" << endl;
			cout << "поступление" << setw(3) << product_1.entr_per << setw(3) << "продажа" << setw(3) << product_1.sale_per << setw(3) << "списание" << setw(3) << product_1.per_of_write_downs << endl;
			if (product_1.entr_per > product_1.per_of_write_downs || product_1.sale_per > product_1.per_of_write_downs || product_1.entr_per > product_1.sale_per)
			{
				throw "ошибка";
				ofile << "ошибка" << endl;
			}
			else ofile << "поступление" << setw(3) << product_1.entr_per << setw(3) << "продажа" << setw(3) << product_1.sale_per << setw(3) << "списание" << setw(3) << product_1.per_of_write_downs << endl;
			if (ifile.is_open())
			{
				string line;
				while (ifile >> line) cout << line << ' ';
			}
		}
		catch (const char* s)
		{
			cout << s << endl;
		}
	}
};