/*Jay Howard
Excercise 3.11.4 Iterator of a Vector
Add the methods beign() and end() for returning a begin and end iterator to class vector. Add the types iterator and const_iterator to the class as well. Note that pointers are models of the concept of random-access iterators.
Use the STL function sort for ordering vector entries to demonstrate that your iterators work as they should.
*/

#include<memory>

template <typename T>
class vector {
public: 
	explicit vector(int size)
		:my_size(size), data(new T[my_size])
	{}

	vector(const vector& that)
		:my_size(that.my_size), data(new T[my_size])
	{
		std::copy(&that.data[0], &that.data[that.my_size], &data[0]);
	}

	int size() const { return my_size };

	const T& operatro[](int i) const {
		check_index(i);
		return data[i];
	}

private:
	int my_size;
	std::unique_ptr<T[]> data;
};

int main() {
	return 0;
}