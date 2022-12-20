#pragma once
#include "products.h"
#include "time.h"
class bread : public product, time, products
{
public:
	bread(string giv_name) : product(giv_name) {};
	time product_2;
	products produce;
	virtual void entrance()
	{
		cout << produce.output_type << endl;
		cout << "����" << endl;
		cout << "�����������(�������������) - ";
		cin >> product_2.entr_per;
		sale();
		write_downs();
		data_output();
	}
	void sale()
	{
		cout << "�������(�������������) - ";
		cin >> product_2.sale_per;
	}
	void write_downs()
	{
		cout << "��������(�������������) - ";
		cin >> product_2.per_of_write_downs;
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
			ofile << "����" << endl;
			cout << "�����������" << setw(3) << product_2.entr_per << setw(3) << "�������" << setw(3) << product_2.sale_per << setw(3) << "��������" << setw(3) << product_2.per_of_write_downs << endl;
			if (product_2.entr_per > product_2.per_of_write_downs || product_2.sale_per > product_2.per_of_write_downs || product_2.entr_per > product_2.sale_per)
			{
				throw "������";
				ofile << "������" << endl;
			}
			else ofile << "�����������" << setw(3) << product_2.entr_per << setw(3) << "�������" << setw(3) << product_2.sale_per << setw(3) << "��������" << setw(3) << product_2.per_of_write_downs << endl;
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