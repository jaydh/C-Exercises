/*
Jay Howard
Excercise 2.8.1 Polynomial
Write a class for polynomials that should at least contain: a constructor giving the degree of the polynomial;
a dynamic array/vector/list of double to store the coefficients; a destructor; and an output function for ostream.

2.8.2 Write a move assignment operator for the polynomial. Define the copy constructor as default. To test whether your assignment is used write a function polynomial f(double c2, double c1, double c0) that takes three coefficients and returns a polynomial. Print out a message in your move assignment or use a debugger to make sure your assignment is used.

2.8.3 Expand the program with a constructor and an assignment operator for a initializer list. The degree of the polynomial hsould be the length of the initializer list minus one afterward.
*/


#include<valarray>
#include<string>
#include<iostream>
#include<assert.h>


//Polynomial class that implements valarray to store coefficeints to allow for element-wise operations, i.e. you want to add/subtract coefficients of same-degree variables. Polynomials should be in expanded form(e.g. x^5 + 0x^4 + 0x^3... +2x)

class Polynomial {
public:
	//Default constructor for Polynomial. Sets default coefficients to 0, representing the zero polynomial. Sets default variable to 'x'
	Polynomial(std::valarray<double> newCoefficients = { 0 }, char newVariable = 'x') {
		//Checks if the given polynomial representaiton has nonnegative degree
		assert(newCoefficients.size() > 0);
		
		degree = newCoefficients.size() - 1;
		coefficients = newCoefficients;
		variable = newVariable;
	}
	//Move Constructor
	Polynomial(Polynomial&& p)
		:degree(p.degree), coefficients(p.coefficients), variable(p.variable) {
		p.degree = 0;
		p.coefficients = { 0 };
		p.variable = 'x';
	}
	//Destructor
	~Polynomial() {}

	//Move assignment operator
	Polynomial& operator=(Polynomial&& src) {
		//Checks if polynomials have the same degree or if the current polynomial is the 0 polynomial
		assert(degree == src.degree || (degree == 0 && coefficients[0] == 0));
		
		std::swap(degree, src.degree);	
		std::swap(coefficients, src.coefficients);
		return *this;
	}

	void output(std::ostream& o) {
		int currentDegree = degree;
		for (int j = 0; j != (degree + 1); ++j) {
			//Omit coefficients with value 0
			if (coefficients[j] == 0) { 
				currentDegree--;
				continue;
			}
			o << "+(" << coefficients[j] << variable << "^" << currentDegree-- << ") ";
			
			//Adds trailing paranethesis
			if (j == degree) {
				o << ")";
			}
		};
	}
	
	void printVal(std::valarray<double> v) {
		for (auto x : v) {
			std::cout << x << "\n";
		}
	}

private:
	int degree;
	char variable;
	std::valarray<double> coefficients;
};

Polynomial makeTwoDegreePoly(double c2, double c1, double c0) {
	Polynomial p({ c2,c1,c0 });
	return p;
}


int main() {

	Polynomial P({ 1,2,0,-35,4,3,-2 });
	P.output(std::cout);
	std::cout << "\n";
	
	Polynomial toMove;
	toMove = makeTwoDegreePoly(1, 90, 4);
	toMove.output(std::cout);

	char c;
	std::cin >> c;
	return 0;
}