#pragma once
#include "hous_chem.h"
#include "time.h"
class air_fresh : public product, hous_chem, time
{
public:
	air_fresh(string giv_name) : product(giv_name) {};
	time hous_chem_3;
	hous_chem commodity;
	virtual void entrance()
	{
		cout << commodity.chemicals << endl;
		cout << "���������� �������" << endl;
		cout << "�����������(�������������) - ";
		cin >> hous_chem_3.entr_per;
		sale();
		write_downs();
		data_output();
	}
	void sale()
	{
		cout << "�������(�������������) - ";
		cin >> hous_chem_3.sale_per;
	}
	void write_downs()
	{
		cout << "��������(�������������) - ";
		cin >> hous_chem_3.per_of_write_downs;
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
			ofile << "���������� �������" << endl;
			cout << "�����������" << setw(3) << hous_chem_3.entr_per << setw(3) << "�������" << setw(3) << hous_chem_3.sale_per << setw(3) << "��������" << setw(3) << hous_chem_3.per_of_write_downs << endl;
			if (hous_chem_3.entr_per > hous_chem_3.per_of_write_downs || hous_chem_3.sale_per > hous_chem_3.per_of_write_downs || hous_chem_3.entr_per > hous_chem_3.sale_per)
			{
				throw "������";
				ofile << "������" << endl;
			}
			else ofile << "�����������" << setw(3) << hous_chem_3.entr_per << setw(3) << "�������" << setw(3) << hous_chem_3.sale_per << setw(3) << "��������" << setw(3) << hous_chem_3.per_of_write_downs << endl;
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