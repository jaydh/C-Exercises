/*Jay Howard
Excercise 4.8.1 Sorting by Magnitude
Create a vector of double and initialize it with the valeus -9.3, -7.4, -3.8, -0.4, 1.3, 3.9, 5.4, 8.2.
You can use an initializer list. Sort the values by magnitude. Write a functor and a lambda expression for the comparison. Try both solutions.
*/

#include<vector>
#include<algorithm>
#include<iostream>

template <typename T>
struct magnitudeSort {
	bool operator()(T i, T j) { return std::abs(i) < std::abs(j); }
};

int main() {
	std::vector<double> v1 { -9.3, -7.4, -3.8, -0.4, 1.3, 3.9, 5.4, 8.2};
	std::vector<double> v2 = v1;
	magnitudeSort<double> m;
	
	//Sorts the vectors by magnitude
	std::sort(v1.begin(), v1.end(), m);
	std::sort(v2.begin(), v2.end(), [](double i, double j) {return std::abs(i) < std::abs(j); });

	//Prints contents of the vectors
	for (auto x : v1) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
	for (auto x : v2) {
		std::cout << x << " ";
	}
	std::cin.get();

	return 0;
}