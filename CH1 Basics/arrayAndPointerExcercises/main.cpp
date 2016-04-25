/*
Jay Howard
Excercise 2.8.1 Polynomial
Write a class for polynomials that should at least contain: a constructor giving the degree of the polynomial;
a dynamic array/vector/list of double to store the coefficients; a destructor; and an output function for ostream.
*/


class polynomial {
public:
	polynomial(int newDegree = 0){
		degree = newDegree;
	}
private: 
	int degree;
};

int main() {
	return 0;
}