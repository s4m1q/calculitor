#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <vector>
#include "Header_samir+sani-denisov.h"
#include "interface.h"
#include "Header_alina+sani-fedoriko.h"
#include "Count.h"
#define Max_size 1000
using namespace std;

int main()
{

    setlocale(LC_ALL, "RU");


	
	
	int type = interface_cal(); // выдаёт число, от него будет зависеть работа программы (выбор вида калькулятора)


	

	


	if (type == 1)
	{
		string str = {};
		getline(cin, str);

		std::stack<char> charStack;



		for (char c : str)
		{
			charStack.push(c);
		}

	}
	else if (type == 2)
	{
		string str = {};
		getline(cin, str);

		std::stack<char> charStack;



		for (char c : str)
		{
			charStack.push(c);
		}

	}
	else if (type == 3)
	{
		string str = {};
		getline(cin, str);

		std::stack<char> charStack;



		for (char c : str)
		{
			charStack.push(c);
		}

	}
	else if (type == 4)
	{
		string str = {};
		getline(cin, str);

		std::stack<char> charStack;



		for (char c : str)
		{
			charStack.push(c);
		}

	}

	int type = interface_cal(); // выдаёт число, от него будет зависеть работа программы (выбор вида калькулятора)
	
		

	/*string operation = {};
	float a = 0, b = 0;
	cin >> operation;
	cin >> a >> b;
	Calculate c(operation, a, b); // это вспомогательный калькулятор для обычных чисел. нужен такой же для мнимых (Саня Ф - это ты делаешь с классом итд)
	double s = c.result();		// функции должны к нему обращаться для подсчёта, работает только с рациональынми числами.
	cout << s;
	
}