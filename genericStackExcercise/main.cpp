/*Jay Howard
Excercise 3.11.3 Generic Stack
Write a stack implementaiton for a generic value type. The maximal size of the stack is defined in the class (hard-wired). Provide the following functions: Constructor, Destructor if necessary, top:show last element, pop: remove last elemtn (without returning), push: insert new element, clear: delete all entries, size: number of elements, full: wheter a stack is full, empty: whether a stack is empty.

I interpret the problem to mean the stack can contain any value type, but only one. 
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
	explicit genStack(int maxSize) :the_max_size(maxSize) { }
	~genStack() { }

	T top() { return the_stack.back(); }
	
	T pop() { 
		auto toPop = the_stack.back();
		the_stack.pop_back();
		return toPop;
	}

	template<typename P>
	void push(P p) { 
		assert(the_stack.size() <= the_max_size);
		//assert(typeid(top()) == typeid(p));
		the_stack.push_back(p); 
	}
	void clear(T t) { the_stack.clear(); }
	int size() const { return the_stack.size(); }
	bool full() const { return the_stack.size() == the_max_size; }
	bool empty() const { return the_stack.empty(); }

private: 
	const int the_max_size;
	vector<T> the_stack;
};

int main() {
	genStack<string> G(255);
	G.push("this is a push");
	G.push("keep on pushing!");
	cout << G.pop() << endl;;
	system("pause");
	return 0;
}