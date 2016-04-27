/*Jay Howard
Excercise 3.11.5 Odd Iterator: Write an iterator class for odd numbers named odd_iterator. The class must model (realize) the ForwardIterator concept. That means it must proved the following members:
Default and copy constructor;
operator++ to the next odd element, as pre-increment and post-increment;
operator* as dereference which returns an (odd) int;
operator== and operator!=; and operator =. 
In addition, the class should contain a constructor that accepts an int value. This value will be returned in the dereference operator (as long as the iterator is not incremented). This constructor should throw an exception if the value is even. Likewise the default constructor should initialize the internal value with 1 to provide a legal state.
*/

#include<vector>
#include<iostream>
using namespace std;

class odd_iterator {
public:
	odd_iterator(int i = 1) : value(i) {
		if (i % 2 == 0) {throw invalid_argument("Recieved even value");}
	}
	odd_iterator(const odd_iterator& other) {
		value = other.value;
	}
	
	//Pre-increment
	inline odd_iterator operator++() { 
		value += 2;
		return *this;
	}
	//Post-increment
	inline odd_iterator operator++(int) {
		odd_iterator temp(*this);
		operator++();
		return temp;
	}
	inline int operator*() { return value; }
	inline bool operator==(odd_iterator & rhs) const { return value == rhs.value; }
	inline bool operator!=(odd_iterator & rhs) const { return value != rhs.value; }
	inline void operator=(odd_iterator& rhs) { value = rhs.value; }
private : 
	int value;
};

int main() {
	odd_iterator o1(1);
	odd_iterator o2(1);
	odd_iterator o3(3);
	if (o2 != o3) { cout << "working" << endl; }
	o2 = o3;
	if (o2 == o3) { cout << "still working" << endl; }
	if (++o1 == o3) { cout << "doubly nice" << endl; }
	cout << "The third odd_iterator is " << *o3 << endl;

	system("pause");
	return 0;
}