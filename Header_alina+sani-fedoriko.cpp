#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <complex>
#include "Complex.h"
#include <stdexcept>

using namespace std;

Complex::Complex(double real, double imag)
{
	this->imag = imag;
	this->real = real;
}

void Complex::print() const
{
	cout << this->real << " " << this->imag << "i" << endl;
}

void Complex::plus(double real, double imag)
{
	this->real += real;
	this->imag += imag;
}

void Complex::minus(double real, double imag)
{
	this->real -= real;
	this->imag -= imag;
}

void Complex::mult(double real, double imag)
{
	double new_real = this->real * real - this->imag * imag;
	double new_imag = this->real * imag + this->imag * real;
	this->real = new_real;
	this->imag = new_imag;
}

void Complex::divide(double real, double imag)
{
	if (real == 0 && imag == 0)
		throw std::invalid_argument("Cannot divide by zero");
	else if (imag == 0) {
		this->real /= real;
		this->imag /= real;
	}
	else {
		double new_real = (this->real * real + this->imag * imag) / (real * real + imag * imag);
		double new_imag = (real * this->imag - this->real * imag) / (real * real + imag * imag);
		this->real = new_real;
		this->imag = new_imag;
	}
}

void Complex::sinus()
{
	if (this->imag == 0)
		this->real = sin(this->real * M_PI / 180);
	else {
		complex <double> c1(this->real, this->imag);
		complex <double> c2 = sin(c1);
		this->real = c2.real();
		this->imag = c2.imag();
	}
}

void Complex::cosin()
{
	if (this->imag == 0)
		this->real = cos(this->real * M_PI / 180);
	else {
		complex <double> c1(this->real, this->imag);
		complex <double> c2 = cos(c1);
		this->real = c2.real();
		this->imag = c2.imag();
	}
}

void Complex::tg()
{
	if (this->imag == 0)
		this->real = tan(this->real * M_PI / 180);
	else {
		complex <double> c1(this->real, this->imag);
		complex <double> c2 = tan(c1);
		this->real = c2.real();
		this->imag = c2.imag();
	}
}

void Complex::ctg()
{
	if (this->imag == 0)
		this->real = (double)1/(tan(this->real * M_PI / 180));
	else {
		complex <double> c1(this->real, this->imag);
		c1 = tan(c1);

		Complex t1(1, 0);

		t1.divide(c1.real(), c1.imag());

		this->real = t1.real;
		this->imag = t1.imag;
	}
}

void Complex::pow_comp(double real, double imag)
{
	complex <double> c1(this->real, this->imag);
	complex <double> c2(real, imag);

	complex <double> res = pow(c1,c2);

	this->real = res.real();
	this->imag = res.imag();
}

void Complex::log_10() 
{
	complex <double> c1(this->real, this->imag);
	c1 = log10(c1);
	this -> real = c1.real();
	this -> imag = c1.imag();
}

void Complex::ln()
{
	complex <double> c1(this->real, this->imag);
	c1 = log(c1);
	this->real = c1.real();
	this->imag = c1.imag();
}

