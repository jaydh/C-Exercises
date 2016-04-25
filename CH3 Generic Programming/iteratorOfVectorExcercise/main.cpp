/*Jay Howard
Excercise 3.11.4 Iterator of a Vector
Add the methods beign() and end() for returning a begin and end iterator to class vector. Add the types iterator and const_iterator to the class as well. Note that pointers are models of the concept of random-access iterators.
Use the STL function sort for ordering vector entries to demonstrate that your iterators work as they should.
*/

#include<memory>
#include<vector>
#include<algorithm>
#include<iostream>

namespace test {
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

		int size() const { return my_size; }

		const T& operator[](int i) const {
			check_index(i);
			return data[i];
		}

		void push_back(const T& x) {
			data[my_size++] = x;
		}

		using iterator = T * ;
		using const_iterator = const T * ;

		iterator begin() { return &data[0]; }
		const_iterator begin() const { return &data[0]; }
		iterator end() { return &data[size()]; }
		const_iterator end() const { return &data[size()]; }

	private:
		int my_size;
		std::unique_ptr<T[]> data;
	};
}

int main() {
	std::vector<int> testV { 1,3,21,7,54,3 };
	test::vector<int> newVect(7);
	newVect.push_back(1);
	newVect.push_back(3);
	newVect.push_back(21);
	newVect.push_back(7);
	newVect.push_back(54);
	newVect.push_back(3);

	std::sort(testV.begin(), testV.end());
	std::sort(newVect.begin(), newVect.end());

	for (auto i = testV.begin(); i != testV.end(); ++i)
		std::cout << *i << ' ';
	std::cout << std::endl;
	for (auto i = newVect.begin(); i != newVect.end(); ++i)
		std::cout << *i << ' ';
	std::cout << std::endl;
	
	system("pause");

	return 0;
}