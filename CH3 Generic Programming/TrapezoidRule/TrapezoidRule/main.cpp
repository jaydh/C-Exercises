/*Jay Howard
Trapezoid Rule
Develop a function for the trapezoid rule, with a functor argument. 
*/

#include<complex>
#include<iostream>

class exp3__f {
public:
	exp3__f() {}

	double operator() (double x) const {
		return std::exp(3.0 * x);
	}
private:

};

template <typename F, typename T>
class trapezoidRule {
public:
	trapezoidRule(const F& f, const T& h) : f(f), h(h) {}

	T operator()(const T& x, const T from, const T to) const {
		T sum = 0;
		n = (to - from)/h;
		for (T j = 1; j != n; j+= 1) {
			sum += f(from + (j*h));
		}
		return h / 2 * (f(from) + f(to)) + (h*sum);
	}
private:
	const F& f;
	T const static h;
	T const static from;
	T const static to;
};

double exp3_f(double x) {
	return std::exp(3.0 * x);
}

double trapezoid_Rule(double f(double), double h, double from, double to){
	double sum = 0;
	double n = (to - from)/h;
	for (double j = 1; j != (n-1); j += 1) {
		sum += f(from + (j*h));
	}
	return h / 2 * (f(from) + f(to)) + (h*sum);
}

struct exp3_t {
	double operator() (double x) const {
		return std::exp(3.0*x);
	}
};

int main() {

	std::cout << std::fixed << trapezoid_Rule(exp3_f, 0.000001, 0, 4) << std::endl;

	using i_exp3_f = trapezoidRule<exp3_t, double>;
	exp3__f exp3;
	i_exp3_f i_exp3(exp3, 0.000001, 0, 4);
	
	system("pause");
	return 0;
}