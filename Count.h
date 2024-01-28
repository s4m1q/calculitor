#pragma once

#include <iostream>
#include <string>
#include <cmath>

class Calculate {
private:
	std::string operation;
	double a, b;

public:
	Calculate(std::string operation_, double a_, double b_);
	double result() {
		if (operation == "+") {
			return a + b;
		}
		else if (operation == "-") {
			return a - b;
		}
		else if (operation == "*") {
			return a * b;
		}
		else if (operation == "%") {
			if ((int)a == a && (int)b == b) {
				return (int)a % (int)b;
			}
			else {
				std::cout << " Problem";
				return 0;
			}

		}
		else if (operation == "/") {
			if (b == 0) {
				std::cout << "Problem" << "\n"; // надо что-то делать
				return 0;
			}
			else {
				return a / b;
			}
		}
		else if (operation == "^") {
			return pow(a, b);
		}
		else if (operation == "!") { // только для целой части
			long long temp = 1;
			for (int i = 0; i < a; i++) {
				temp *= i;
			}
		}
		else if (operation == "sqrt") {
			return sqrt(a);
		}
		else if (operation == "sin") {
			return sin(a);
		}
		else if (operation == "cos") {
			return cos(a);
		}
		else if (operation == "tg") { // из-за округления cos!=0;
			return tan(a);
		}
		else if (operation == "ctg") {
			return (1 / tan(a));
		}
		else if (operation == "arcsin") {
			return asin(a);
		}
		else if (operation == "arccos") {
			return acos(a);
		}
		else if (operation == "arctg") {
			return atan(a);
		}
		else if (operation == "arcctg") {
			return (1 / atan(a));
		}
		else if (operation == "log") { // b - основание log
			return log10(a) / log10(b);
		}
		/*else if (operation == "pow_mod") {	саня: ОНО НАДО?   
												самир: нет
		}*/
	}


};
Calculate::Calculate(std::string operation_, double a_, double b_) :operation(operation_), a(a_), b(b_) {}