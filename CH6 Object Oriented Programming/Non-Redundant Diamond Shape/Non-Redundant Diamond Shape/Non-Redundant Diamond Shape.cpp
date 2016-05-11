/* Jay Howard
Excercise 6.7.1 Non-redudnat Diamond Shape
Implement the diamond shape from Section 6.3.2 such that the name is only printed once. Distinguish in derived classes between all_info() and my_infos() and call the two functions appropriately. 
*/

#include "stdafx.h"
#include<string>
#include<iostream>
using namespace std;

class person {
public: 
	person() {}
	explicit person(const string& name) : name(name){}

	void set_name(const string& n) { name = n; }
	string get_name() const { return name; }
	virtual void my_infos() const { cout << "My name is " << name << endl; }
	virtual void all_info() const { my_infos(); }
private:
	string name;
};

class student
	: public virtual person
{
public:
	student(const string& name, const string& passed) : person(name), passed(passed) {}
	virtual void my_infos() const { cout << "I passed the following grades: " << passed << endl;}
	
private:
	string passed;
};

class mathematician : 
	public virtual person{
public:
	mathematician(const string& name, const string& proved) : person(name), proved(proved) {}
	virtual void my_infos() const override { cout << "I proved : " << proved << endl; }

private:
	string proved;
};
class math_student :
	public student, public mathematician {
public:
	math_student(const string& name, const string& passed, const string& proved) : student(name, passed), mathematician(name, proved){}
	
	virtual void my_infos() const override {
		student::my_infos();
		mathematician::my_infos();
	}
};

int main()
{
	math_student bob("Robert Robson", "Algebra", "Fermat's Last Theorem");
	bob.all_info();

	cin.get();
    return 0;
}

