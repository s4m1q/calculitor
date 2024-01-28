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
    //setlocale(LC_ALL, "RU");
    //interface_cal();
	Calculate c("cos", 2.3, 5.9);
	double s = c.result();
	std::cout << s;
	
}