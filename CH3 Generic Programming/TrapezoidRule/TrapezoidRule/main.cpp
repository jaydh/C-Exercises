/*Jay Howard
Trapezoid Rule
Develop a function for the trapezoid rule, with a functor argument. 
*/

#include<complex>
#include<iostream>

double exp3_f(double x) {
	return std::exp(3.0 * x);
}

double trapezoid_Rule(double f(double), double h, double from, double to) {
	double sum = 0;
	double n = (to - from) / h;
	for (double j = 1; j != (n - 1); j += 1) {
		sum += f(from + (j*h));
	}
	return h / 2 * (f(from) + f(to)) + (h*sum);
}

template <typename F, typename T>
class trapezoidRule {
public:
	trapezoidRule(const F& f, const T& h) : f(f), h(h) {}

	T operator()(const T from, const T to) const {
		T sum = 0;
		T n = (to - from)/h;
		for (T j = 1; j != (n-1); j+= 1) {
			sum += f(from + (j*h));
		}
		return h / 2 * (f(from) + f(to)) + (h*sum);
	}
private:
	const F& f;
	T const h;
	T const static from;
	T const static to;
};

struct exp3_t {
	double operator() (double x) const {
		return std::exp(3.0*x);
	}
};

struct sincos_t {
	double operator() (double x)  const {
		return (x < 1) ? std::sin(x) : std::cos(x);
	}
};

template<typename F, typename T>
class fin_diff {
public:
	fin_diff(const F& f, const T& h) : f(f), h(h) {}

	T operator()(const T& x) {
		return (f(x + h)) - f(x)) / h;
	}
private:
	const F& f;
	T h;
};

int main() {

	double h = 0.0001;
	std::cout << std::fixed << trapezoid_Rule(exp3_f, h, 0, 4) << std::endl;

	using i_exp3_f = trapezoidRule<exp3_t, double>;
	exp3_t exp3;
	i_exp3_f i_exp3(exp3, h);
	std::cout << i_exp3(0, 4) << std::endl;

	using i_sincos_f = trapezoidRule<sincos_t, double>;
	sincos_t sincos;
	i_sincos_f i_sincos(sincos, h);
	std::cout << i_sincos(0, 4) << std::endl;

	
	system("pause");
	return 0;
}