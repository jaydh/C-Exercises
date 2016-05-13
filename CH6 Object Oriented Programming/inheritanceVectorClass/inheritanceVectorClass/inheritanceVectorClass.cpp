/*Jay Howard
Exercise 6.7.2 Inheritance Vector Class
Revise the vector example from Chapter 2. Introduce the base class vector_expression for my_size and operator(). Make vector inherit from this base class. Then make a class ones that is a vector of all ones and also inherits from vector_expression.
*/

#include "stdafx.h"
#include<memory>
#include <iostream>
#include<assert.h>

template<typename T>
class vector_expression{
	void check_size(int that_size) const { assert(my_size == that_size); }
	void check_index(int i) const { assert(i >= 0 && i < my_size); }
public:
	vector_expression(int my_size = 0): my_size(my_size), data(new T[my_size]) {};
	const T& operator()(int i) const
	{
		check_index(i);
		return data[i];
	}

	T& operator()(int i)
	{
		check_index(i);
		return data[i];
	}
	int size() { return my_size; }
	int size() const { return my_size;}

private:
	int my_size;
	std::unique_ptr<T[]> data;
};

template<typename T>
class vector
	:public vector_expression<T>
{
public:
	vector(int my_size = 0) : my_size(my_size), data(new T[my_size]), vector_expression{ my_size } {}

	vector(const vector& that)
		: my_size(that.my_size), data(new T[my_size])
	{
		std::copy(&that.data[0], &that.data[that.my_size], &data[0]);
	}

	vector& operator=(const vector& that)
	{
		check_size(that.my_size);
		std::copy(&that.data[0], &that.data[that.my_size], &data[0]);
		return *this;
	}

	vector operator+(const vector& that) const
	{
		check_size(that.my_size);
		vector sum(my_size);
		for (int i = 0; i < my_size; ++i)
			sum[i] = data[i] + that[i];
		return sum;
	}
private:
	int my_size;
	std::unique_ptr<T[]> data;
};

class ones 
	:public vector_expression<int>
{
public:
	ones(int my_size = 0) : my_size(my_size), data(new int[my_size]), vector_expression{ my_size }{
		for (int i = 0; i != my_size; ++i) {
			(*this)(i) = 1;
		}
	}
private:
	int my_size;
	std::unique_ptr<int[]> data;
};

int main()
{
	vector_expression<double> v{4};
	v(0) = 1, v(1) = 2, v(2) = 3, v(3) = 4;
	vector<double> vec{4};
	vec(0) = 1, vec(1) = 2, vec(2) = 3, vec(3) = 4;
	ones onesV{ 4 };
	
	for (int i = 0; i != v.size(); ++i) {
		std::cout << v(i) << " " << vec(i) << " " << onesV(i) << std::endl;
	}

	std::cin.get();

    return 0;
}

