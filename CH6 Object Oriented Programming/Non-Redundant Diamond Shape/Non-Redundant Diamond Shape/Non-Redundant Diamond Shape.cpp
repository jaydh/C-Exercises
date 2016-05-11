/* Jay Howard
Excercise 6.7.1 Non-redudnat Diamond Shape
Implement the diamond shape from Section 6.3.2 such that the name is only printed once. Distinguish in derived classes between all_info() and my_infods() and call the two functions appropriately. 
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
	virtual void all_info() const { cout << "[person]	My name is " << name << endl; }
private:
	string name;
};

class student
	: public person
{
public:
	student(const string& name, const string& passed) : person(name), passed(passed) {}
	virtual void all_info() const {
		cout << "[student] My name is " << get_name() << endl;
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

class student_updated
	: public person
{
public:
	student_updated(const string& name, const string& passed) : person(name), passed(passed) {}
	virtual void all_info() const {
		person::all_info();
		cout << "I passed the following grades: " << passed << endl;
	}
private:
	string passed;
};
class mathematician_updated :
	public person {
public:
	mathematician_updated(const string& name, const string& proved) : person(name), proved(proved) {}
	virtual void all_info() const override {
		person::all_info();
		cout << "	I proved : " << proved << endl;
	}
private:
	string proved;
};

class math_student :
	public student_updated, public mathematician_updated {
public:
	math_student(const string& name, const string& passed, const string& proved) : student_updated(name, passed), mathematician_updated(name, proved){}
	virtual void all_info() const override {
		student_updated::all_info();
		mathematician_updated::all_info();
	}

};

int main()
{
	math_student bob("Robert Robson", "Algebra", "Fermat's Last Theorem");
	bob.all_info();
	cin.get();
    return 0;
}

