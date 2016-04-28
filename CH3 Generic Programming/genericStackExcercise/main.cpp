/*Jay Howard
Excercise 3.11.3 Generic Stack
Write a stack implementaiton for a generic value type. The maximal size of the stack is defined in the class (hard-wired). Provide the following functions: Constructor, Destructor if necessary, top:show last element, pop: remove last element (without returning), push: insert new element, clear: delete all entries, size: number of elements, full: whether a stack is full, empty: whether a stack is empty.

I interpret the problem to mean the stack can contain any value type, but only one. 

3.11.7 Stack of bool
Specialize your stack implementation from Exercise 3.11.3 for bool. Use an unsigned char for 8 bool as in Section 3.6.1.
*/

#include<assert.h>
#include<vector>
#include<string>
#include<iostream>
#include<memory>

using namespace std;

template<typename T>
class genStack{
public:
	explicit genStack(int size = 0) :the_max_size(size) { }
	~genStack() {clear();}

	//Returns a copy of the top element
	T& top() const { return the_stack.back(); }
	
	//Pops from the stack with a temp variable
	T pop() { 
		if (stack.empty()) throw underflow_error;

		auto toPop = the_stack.back();
		the_stack.pop_back();
		return toPop;
	}

	//Pushes onto the stack. Checks to make sure container doesn't exceed the size and if passed in element matches the type in the stack.
	template<typename P>
	void push(P p) { 
		if (stack.full()) throw overflow_error;
		assert(typeid(T) == typeid(P));
		the_stack.push_back(p); 
	}

	void clear() { the_stack.clear(); }
	int size() const { return the_stack.size(); }
	bool full() const { return the_stack.size() == the_max_size; }
	bool empty() const { return the_stack.empty(); }

private: 
	const int the_max_size;
	vector<T> the_stack;
};


template<>
class genStack<bool> {
public:

	//Proxy class copied from p.138
	class bool_proxy {
	public:
		bool_proxy(unsigned char& byte, int p) : byte(byte), mask(1 << p) {}
		operator bool() const { return byte & mask; }
		bool_proxy& operator=(bool b) {
			if (b) byte |= mask;
			else byte &= ~mask;
			return *this;
		}
	private:
		unsigned char& byte;
		unsigned char mask;
	};

	explicit genStack(int size = 0) : the_max_size(size), the_stack(new unsigned char[(the_max_size + 7) / 8 ]) {}
	~genStack() { the_stack.reset; }
	 

	inline unsigned char top() {	
		auto temp = the_stack.get();
	}
	
private:
	int the_max_size;
	unique_ptr<unsigned char[]> the_stack;
};


int main() {
	genStack<string> G(255);
	G.push(string("Just push"));
	G.push(string("More pushing. Force push."));
	cout << G.pop() << endl;;

	system("pause");
	return 0;
}