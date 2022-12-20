#include "milk.h"
#include "bread.h"
#include "rice.h"
#include "soap.h"
#include "wash_powd.h"
#include "air_fresh.h"
enum ConsoleColor {
	Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray,
	LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};
void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
void GotoXY(int X, int Y)
{
	HANDLE hConsole;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { X, Y };
	SetConsoleCursorPosition(hStdOut, coord);
}
#include <stdio.h>
/*0 Ч черный
1 Ч синий
2 Ч зеленый
3 Ч голубой
4 Ч красный
5 Ч лиловый
6 Ч желтый
7 Ч белый
8 Ч серый
9 Ч свело - синий
A Ч светло - зеленый
B Ч светло - голубой
— Ч светло - красный
E Ч светло - желтый
F Ч €рко - белый
system("color F0");*/  // ”становка белого фона и черного текста
int get_var(int count);
void print_menu();
void main()
{
	setlocale(LC_ALL, "ru");
	int variant;
	product* goods[6] = { new milk("молоко"), new bread("хлеб"), new rice("рис"), new soap("мыло"), new wash_powd("стиральный порошок"), new air_fresh("освежитель воздуха") };
	do
	{
		print_menu();
		variant = get_var(6);
		switch (variant)
		{
		case 1:
		{
			goods[0]->entrance();
			break;
		}
		case 2:
		{
			goods[1]->entrance();
			break;
		}
		case 3:
		{
			goods[2]->entrance();
			break;
		}
		case 4:
		{
			goods[3]->entrance();
			break;
		}
		case 5:
		{
			goods[4]->entrance();
			break;
		}
		case 6:
		{
			goods[5]->entrance();
			break;
		}
		break;
		}
		if (variant != 6) system("pause");
	} while (variant != 6);
}
int get_var(int count)
{
	int variant;
	char s[100];
	scanf("%s", s);
	while (sscanf(s, "%d", &variant) != 1 || variant < 1 || variant > count)
	{
		SetColor(1, 0);
		cout << "ошибка. следует попробовать снова - ";
		scanf("%s", s);
	}
	return variant;
}
void print_menu()
{
	SetColor(2, 0);
	cout << "молоко=1, хлеб=2, рис=3, мыло=4, стиральный порошок=5, освежитель воздуха=6" << endl;
}