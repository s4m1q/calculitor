#pragma once

/*
Функции работают по следующему принципу: если нужно, например, прибавить к первому комп. числу второе, 
то из первого числа вызывается функция "plus", в качестве аргументов передаются поля второго числа (real, imag). 
Функция изменяет поля ПЕРВОГО числа (из которого она вызвана), второе при этом не меняется. 
Это распростроняется на операции: + - * / sin cos tg ctg pow_comp log10 ln
*/

class Complex {
public:
	Complex() :real(0), imag(0) {}
	Complex(double real, double imag);

	void print()const;

	void plus(double real, double imag);
	void minus(double real, double imag);
	void mult(double real, double imag);
	void divide(double real, double imag);

	void sinus();
	void cosin();
	void tg();
	void ctg();

	void pow_comp(double real, double imag); // возведение в комплексную или вещественную степень

	void log_10();
	void ln();
private:
	double real, imag;
};
