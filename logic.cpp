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
	Calculate c("cos", 0.5, 5.9);
	std::cout << c.result();
	
}