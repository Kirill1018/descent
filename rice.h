#pragma once
#include "products.h"
#include "time.h"
class rice : public product, products, time
{
public:
	rice(string giv_name) : product(giv_name) {};
	time product_3;
	products produce;
	virtual void entrance()
	{
		cout << produce.output_type << endl;
		cout << "рис" << endl;
		cout << "поступление(числомес€цгод) - ";
		cin >> product_3.entr_per;
		sale();
		write_downs();
		data_output();
	}
	void sale()
	{
		cout << "продажа(числомес€цгод) - ";
		cin >> product_3.sale_per;
	}
	void write_downs()
	{
		cout << "списание(числомес€цгод) - ";
		cin >> product_3.per_of_write_downs;
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
			ofile << "рис" << endl;
			cout << "поступление" << setw(3) << product_3.entr_per << setw(3) << "продажа" << setw(3) << product_3.sale_per << setw(3) << "списание" << setw(3) << product_3.per_of_write_downs << endl;
			if (product_3.entr_per > product_3.per_of_write_downs || product_3.sale_per > product_3.per_of_write_downs || product_3.entr_per > product_3.sale_per)
			{
				throw "ошибка";
				ofile << "ошибка" << endl;
			}
			else ofile << "поступление" << setw(3) << product_3.entr_per << setw(3) << "продажа" << setw(3) << product_3.sale_per << setw(3) << "списание" << setw(3) << product_3.per_of_write_downs << endl;
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