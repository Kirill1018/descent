#pragma once
#include "hous_chem.h"
#include "time.h"
class wash_powd : public product, hous_chem, time
{
public:
	wash_powd(string giv_name) : product(giv_name) {};
	time hous_chem_2;
	hous_chem commodity;
	virtual void entrance()
	{
		cout << commodity.chemicals << endl;
		cout << "стиральный порошок" << endl;
		cout << "поступление(числомес€цгод) - ";
		cin >> hous_chem_2.entr_per;
		sale();
		write_downs();
		data_output();
	}
	void sale()
	{
		cout << "продажа(числомес€цгод) - ";
		cin >> hous_chem_2.sale_per;
	}
	void write_downs()
	{
		cout << "списание(числомес€цгод) - ";
		cin >> hous_chem_2.per_of_write_downs;
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
			ofile << "стиральный порошок" << endl;
			cout << "поступление" << setw(3) << hous_chem_2.entr_per << setw(3) << "продажа" << setw(3) << hous_chem_2.sale_per << setw(3) << "списание" << setw(3) << hous_chem_2.per_of_write_downs << endl;
			if (hous_chem_2.entr_per > hous_chem_2.per_of_write_downs || hous_chem_2.sale_per > hous_chem_2.per_of_write_downs || hous_chem_2.entr_per > hous_chem_2.sale_per)
			{
				throw "ошибка";
				ofile << "ошибка" << endl;
			}
			else ofile << "поступление" << setw(3) << hous_chem_2.entr_per << setw(3) << "продажа" << setw(3) << hous_chem_2.sale_per << setw(3) << "списание" << setw(3) << hous_chem_2.per_of_write_downs << endl;
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