/*
Jay Howard
Excercise 2.8.1 Polynomial
Write a class for polynomials that should at least contain: a constructor giving the degree of the polynomial;
a dynamic array/vector/list of double to store the coefficients; a destructor; and an output function for ostream.
*/

#pragma once

#include<valarray>
#include<string>
#include<iostream>
#include<assert.h>


//Polynomial class that implements valarray to store coefficeints to allow for element-wise operations, i.e. you want to add/subtract coefficients of same-degree variables. Polynomials should be in expanded form(e.g. x^5 + 0x^4 + 0x^3... +2x)

class Polynomial {
public:
	//Constructor for Polynomial. Sets default degree and coeffecient to 0, which represents the zero element. Sets default variable to 'x'
	Polynomial(int newDegree = 0, std::valarray<double> newCoefficients = { 0 }, char newVariable = 'x') {
		//Checks if the given degree is 
		assert(newDegree == (newCoefficients.size() - 1));
		degree = newDegree;
		coefficients = newCoefficients;
		variable = newVariable;
	}
	~Polynomial() {}

	void output(std::ostream& o) {
		for (int j = 0; j != degree + 1; ++j) {
			if (j == degree) {
				o << "+(" << coefficients[j] << ")";
				continue;
			}
			if (coefficients[j] == 0) { continue; }

			o << "+(" << coefficients[j] << variable << "^" << degree - j << ") ";
		};
	}

private:
	int degree;
	char variable;
	std::valarray<double> coefficients;
};

int main() {
	Polynomial P(6, { 1,2,0,-35,4,3,-2 });
	P.output(std::cout);
	char c;
	std::cin >> c;
	return 0;
}