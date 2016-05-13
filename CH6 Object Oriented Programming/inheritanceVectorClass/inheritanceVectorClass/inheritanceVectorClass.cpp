/*Jay Howard
Exercise 6.7.2 Inheritance Vector Class
Revise the vector example from Chapter 2. Introduce the base class vector_expression for my_size and operator(). Make vector inherit from this base class. Then make a class ones that is a vector of all ones and also inherits from vector_expression.
*/

#include "stdafx.h"
#include<memory>

template<typename T>
class vector_expression{
public:
	vector_expression(int my_size = 0): my_size(my_size), data(new double[my_size]) {};
	T operator()(int i) { return data[i]; }
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
	vector(unsigned my_size = 0) : my_size(my_size), data(new double[my_size]) {}
	vector(const vector& that)
		: my_my_size(that.my_my_size), data(new double[my_my_size])
	{
		for (int i = 0; i<my_my_size; ++i)
			data[i] = that.data[i];
	}

	void operator=(const vector& that)
	{
		assert(that.my_my_size == my_my_size);
		for (int i = 0; i<my_my_size; ++i)
			data[i] = that.data[i];
	}

	double& operator[](int i) const {
		assert(i >= 0 && i<my_my_size);
		return data[i];
	}

	double& operator[](int i) {
		assert(i >= 0 && i<my_my_size);
		return data[i];

	}

	vector operator+(const vector& that) const {
		assert(that.my_my_size == my_my_size);
		vector sum(my_my_size);
		for (int i = 0; i < my_my_size; ++i)
			sum[i] = (*this)[i] + that[i];
		return sum;
	}
private:
	int my_size;
	std::unique_ptr<T[]> data;
};

template<typename T>
class ones 
	:public vector_expression<T>, public vector<T>
{
public:
	ones(int my_size = 0) : my_size(my_size), data(new double[my_size]) {}
private:
	int my_size;
	std::unique_ptr<T[]> data;
};

int main()
{
    return 0;
}

