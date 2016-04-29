/*Jay Howard
Trapezoid Rule
Develop a function for the trapezoid rule, with a functor argument. 
*/

template <typename F, typename T>
class trapezoidRule {
public:
	trapezoidRule(const F& f, const T& h) : f(f), h(h) {}


	T operator()(const T& x) {
		T sum = 0;
		n = (to - from)*h;
		for (int j = from; j != n; i++) {
			sum += f(from + (i*h));
		}
		return h / 2 * (f(from) + f(to)) + sum;
	}
private:
	const F& f;
	T const static h;
	T const static from;
	T const static to;
};

int main() {
	return 0;
}