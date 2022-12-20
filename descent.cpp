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
/*0 � ������
1 � �����
2 � �������
3 � �������
4 � �������
5 � �������
6 � ������
7 � �����
8 � �����
9 � ����� - �����
A � ������ - �������
B � ������ - �������
� � ������ - �������
E � ������ - ������
F � ���� - �����
system("color F0");*/  // ��������� ������ ���� � ������� ������
int get_var(int count);
void print_menu();
void main()
{
	setlocale(LC_ALL, "ru");
	int variant;
	product* goods[6] = { new milk("������"), new bread("����"), new rice("���"), new soap("����"), new wash_powd("���������� �������"), new air_fresh("���������� �������") };
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
		cout << "������. ������� ����������� ����� - ";
		scanf("%s", s);
	}
	return variant;
}
void print_menu()
{
	SetColor(2, 0);
	cout << "������=1, ����=2, ���=3, ����=4, ���������� �������=5, ���������� �������=6" << endl;
}