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
	person(const string& name) : id(name) {}

	void set_name(const string& n) { id = n; }
	string get_name() const { return id; }
	virtual void my_infos() const { cout << "My name is " << id << endl; }
	virtual void all_info() const { my_infos(); }

private:
	string id;
};

class student
	: virtual public person
{
public:
	student(const string& name, const string& passed) : person(name), id(passed) {}
	
	virtual void my_infos() const override { cout << "I passed the following grades: " << id << endl; }
	virtual void all_info() const override {
		person::my_infos();
		student::my_infos();
	}

private:
	string id;
};

class mathematician : 
	virtual public person{
public:
	mathematician(const string& name, const string& proved) : person(name), id(proved) {}
	virtual void my_infos() const override { cout << "I proved: " << id << endl; }
	virtual void all_info() const override {
		person::my_infos();
		mathematician::my_infos();
	}
private:
	string id;
};

class math_student :
	public student, public mathematician {
public:
	math_student(const string& name, const string& passed, const string& proved) : person(name), student(name, passed), mathematician(name, proved) {}
	virtual void my_infos() const override {}
	virtual void all_info() const override {
		person::my_infos();
		student::my_infos();
		mathematician::my_infos();
	}
};

int main()
{
	person jay("Jay");
	student jill("Jill", "Creative Writing");
	mathematician sophie("Sophie", "Riemann Hypothesis");
	math_student bob("Robert Robson", "Algebra", "Fermat's Last Theorem");
	
	jay.all_info();
	jill.all_info();
	sophie.all_info();
	bob.all_info();

	cin.get();
    return 0;
}

