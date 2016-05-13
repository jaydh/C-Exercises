/*Jay Howard
Excercise 3.11.3 Generic Stack
Write a stack implementaiton for a generic value type. The maximal size of the stack is defined in the class (hard-wired). Provide the following functions: Constructor, Destructor if necessary, top:show last element, pop: remove last element (without returning), push: insert new element, clear: delete all entries, size: number of elements, full: whether a stack is full, empty: whether a stack is empty.

I interpret the problem to mean the stack can contain any value type, but only one. 

3.11.7 Stack of bool
Specialize your stack implementation from Exercise 3.11.3 for bool. Use an unsigned char for 8 bool as in Section 3.6.1.

3.11.8 Stack with custom size
Revise your stack implementation from Exercise 3.11.3( and optionally that of Exercise 3.11.7) with a user-defined size. The size is passed as the second template argument. The default should be 4096.
*/

#include<stdexcept>
#include<assert.h>
#include<vector>
#include<string>
#include<iostream>
#include<memory>

using namespace std;

template<typename T, int the_max_size = 4096>
class genStack{
public:
	explicit genStack() {}
	~genStack() {clear();}

	//Returns a copy of the top element
	T& top() const { return the_stack.back(); }
	
	//Pops from the stack with a temp variable
	T pop() { 
		if (empty()) throw out_of_range("Stack underflow");

		auto toPop = the_stack.back();
		the_stack.pop_back();
		return toPop;
	}

	//Pushes onto the stack. Checks to make sure container doesn't exceed the size and if passed in element matches the type in the stack.
	template<typename P>
	void push(P p) { 
		if (full()) throw out_of_range("Stack overflow");
		assert(typeid(T) == typeid(P));
		the_stack.push_back(p); 
	}

	inline void clear() { the_stack.clear(); }
	inline int size() const { return int(the_stack.size()); }
	inline bool full() const { return the_stack.size() == the_max_size; }
	inline bool empty() const { return the_stack.empty(); }

private: 
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

	explicit genStack(int size = 0) : the_stack(new unsigned char[(the_max_size + 7) / 8]) { topIndex = -1; }
	~genStack() { clear(); }

	inline bool top() const { 
		bool_proxy top{ the_stack[topIndex / 8], topIndex % 8 };
		return top;
	}
	bool pop() {
		if (empty()) throw out_of_range("Stack underflow");

		auto toPop = top();
		bool_proxy byte{ the_stack[topIndex / 8], topIndex % 8 };
		topIndex -= 1;
		byte = false;
		return toPop;
	}

	void push(bool b) {
		if (full()) throw out_of_range("Stack overflow");
		topIndex += 1;
		bool_proxy byte{ the_stack[topIndex / 8], topIndex % 8 };
		byte = b;
	}

	void clear() { the_stack.reset(nullptr); }
	inline int size() const { return topIndex + 1; }

	inline bool empty() const { return topIndex == 0; }
	inline bool full() const { return size() == the_max_size; }
	
private:
	int topIndex;
	int the_max_size = 4096;
	unique_ptr<unsigned char[]> the_stack;
};


int main() {
	genStack<string> G;
	G.push(string("Just push"));
	G.push(string("More pushing. Force push."));
	cout << G.pop() << endl;;


	genStack<bool> boolStack(10);
	cout << "Pushing {true, true, false, true} to bool specialization of generic stack." << endl;
	boolStack.push(true);
	boolStack.push(true);
	boolStack.push(false);
	boolStack.push(true);
	cout << boolalpha << "Now popping the top(of size " << boolStack.size() << "): ";
	cout << boolStack.pop() << endl;
	cout << "The new top is " << boolStack.top() << endl;
	boolStack.clear();

	system("pause");
	return 0;
}