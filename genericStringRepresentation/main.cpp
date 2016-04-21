/*
Jay Howard
Excercise 3.11.1 String Representation
Write a gerneric function to_string that takes an argument of an arbitrary type (as const&) and generates a string by piping it to a std::stringstream and returning the result string.
*/

#include<string>
#include<sstream>
#include<iostream>
using namespace std;

template <typename T>
inline string to_string(const T& from) {
	stringstream to;
	to << from;
	return to.str();
}

int main() {
	auto testString = "This is a string";
	auto testChar = 'c';
	auto testInt = "42";

	cout << to_string(testString) << endl << to_string(testChar) << endl << to_string(testInt) << endl << to_string("This is an rvalue") << endl;
	system("PAUSE");
	return 0;
}