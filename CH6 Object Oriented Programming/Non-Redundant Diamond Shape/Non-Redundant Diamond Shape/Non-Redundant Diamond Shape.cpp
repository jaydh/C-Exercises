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
	explicit person(const string& name) : id(name) { message = "My name is "; }

	void set_name(const string& n) { id = n; }
	void set_message(const string& m) { message = m; }
	string get_name() const { return id; }
	virtual void my_infos() const { cout << message << id << endl; }
	virtual void all_info() const { my_infos(); }

private:
	string id;
	string message;
};

class student
	: virtual public person
{
public:
	student(const string& name, const string& passed) : person(name), id(passed) { message = "I passed the following grades: "; }
	
	virtual void my_infos() const override { cout << message << id << endl; }
	virtual void all_info() const override {
		person::my_infos();
		my_infos();
	}

protected :
	student(const string& passed) : id(passed) { message = "I passed the following grades: "; }
private:
	string id;
	string message;
};

class mathematician : 
	virtual public person{
public:
	mathematician(const string& name, const string& proved) : person(name), id(proved) { message = "I proved: "; }
	virtual void my_infos() const override { cout << message << id << endl; }
	virtual void all_info() const override {
		person::my_infos();
		my_infos();
	}
protected:
	mathematician(const string& proved) : id(proved) { message = "I proved: "; }

private:
	string id;
	string message;
};
class math_student :
	public student, public mathematician {
public:
	math_student(const string& name, const string& passed, const string& proved) : person(name), student(passed), mathematician(proved){}
	virtual void my_infos() const override {
		person::my_infos();
		student::my_infos();
		mathematician::my_infos();
	}
	virtual void all_info() const override { my_infos(); }
};

int main()
{
	math_student bob("Robert Robson", "Algebra", "Fermat's Last Theorem");
	bob.all_info();

	cin.get();
    return 0;
}

