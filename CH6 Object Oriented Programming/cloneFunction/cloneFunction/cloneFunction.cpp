/*Jay Howard
Excercise 6.7.3 Clone Function
Write a CRTP class for a member function name clone() that copies the current object--like the Java function clone. Consider the return type of the function must be the one of the cloned object.
*/

#include "stdafx.h"
#include<vector>
using namespace std;

template<typename T>
class cloneableVector : public vector<T> {
public:
	T clone() { new T(static_cast<Derived const &>(*this)); }
};

int main()
{
    return 0;
}

