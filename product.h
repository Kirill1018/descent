#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
class product
{
public:
	product() {};
	string giv_name;
	product(string first_name)
	{
		giv_name = first_name;
	};
	virtual void entrance() = 0;//поступление
protected:
	string name, prod_date;
	int price;
	double prod_weight;
};