/* Jay Howard
Excercise 6.7.1 Non-redudnat Diamond Shape
Implement the diamond shape from Section 6.3.2 such that the name is only pinted once. Distinguish in derived classes between all_info() and my_infods() and call the two functions appropriately. 
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
	//void all_info() const {	cout << "[person]	My name is " << name << endl;}
	virtual void all_info() const { cout << "[person]	My name is " << name << endl; }
private:
	string name;
};

class student
	: public person
{
public:
	student(const string& name, const string& passed) : person(name), passed(passed) {}
	void all_info() const {
		cout << "[studnet]	My name is " << get_name() << endl;
		cout << "I passed the following grades: " << passed << endl;
	}
	virtual void all_info() const {
		cout << "[studnet] My name is " << name << endl;
		cout << "I passed the following grades: " << passed << endl;
	}
private:
	string passed;
};

class mathematician : 
	public person{
public:
	mathematician(const string& name, const string& proved) : name(name), proved(proved) {}
	virtual void all_info() const override {
		person::all_info();
		cout << "	I proved : " << proved << endl;
	}
private:
	string name;
	string proved;
};

class math_student :
	public student, public mathematician {
public:
	math_student(const string& name, const string& passed, const string& proved) : student(name, passed), mathematician(name, proved){}

};

int main()
{
	math_student bob("Robert Robson", "Algebra", "Fermat's Last Theorem");
    return 0;
}

