/*Jay Howard
3.11.11 Functor
Write a functor for 2 cosx + x^2 and compute the first and second derivatives with the function from Section 3.8.1

3.11.12 Lambda
Compute the same derivatives as in Exercise 3.11.11 but this time with a lambda expression.*/

#include<complex>
#include<iostream>
using namespace std;

class toDerive {
public:
	toDerive() {}

	double operator()(double x) const {
		return 2*cos(x) + pow(x,2);
	}
};

template <typename F, typename T>
class derivative {
public: 
	derivative(const F& f, const T& h) : f(f), h(h) {}

	T operator()(const T&x) const {
		return (f(x + h) - f(x)) / h;
	}

private:
	const F& f;
	T h;
};

int main() {
	double h = 0.0001;

	//First derivative
	using d_tD_f = derivative<toDerive, double>;
	toDerive tD_o;
	d_tD_f d_tD_o(tD_o, h);
	cout << d_tD_o(2.0) << endl;

	//Second derivative
	using dd_tD_f = derivative<d_tD_f, double>;
	dd_tD_f dd_tD_o(d_tD_o, h);
	cout << dd_tD_o(2.0) << endl;

	//Lambda implementation of derivative and function to be derived
	auto toDerive = ([](double x) {return 2 * cos(x) + pow(x, 2); });
	auto derivative = ([h](auto f, auto h, auto x) {return (f(x + h) - f(x)) / h; });
	cout << derivative(toDerive, h, 2.0);
	cin.get();
	return 0;
}