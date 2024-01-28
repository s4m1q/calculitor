#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <vector>
#include "Header_samir+sani-denisov.h"
#include "interface.h"
#include "Header_alina+sani-fedoriko.h"
#include "Count.h"

using namespace std;

int main()
{

    setlocale(LC_ALL, "RU");
	string str = {};

    

	int type = interface_cal(); // ����� �����, �� ���� ����� �������� ������ ��������� (����� ���� ������������)
	
		

	string operation = {};
	float a = 0, b = 0;
	cin >> operation;
	cin >> a >> b;
	Calculate c(operation, a, b); // ��� ��������������� ����������� ��� ������� �����. ����� ����� �� ��� ������ (���� � - ��� �� ������� � ������� ���)
	double s = c.result();		// ������� ������ � ���� ���������� ��� ��������, �������� ������ � ������������� �������.
	cout << s;

	
}