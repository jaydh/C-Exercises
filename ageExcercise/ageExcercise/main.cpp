//
//  Age.cpp
//  Excercises
//
//  Created by Jay Howard on 4/14/16.
//  Copyright © 2016 Jay Howard. All rights reserved.
/*
From "Discovering Modern C++ An Intensive Course for Scientists, Engineers, and Programmerss"
Excercise 1.10.1 Age: Write a program that asks input from the keyboard and prints teh result on the screen and writes it to a file. The quesiton is: "What is your age?"
*/

#include <iostream>
#include <fstream>
#include <string>


using namespace std;

void stringToOstream(string s, ostream& o) {
	if (o.good()) {
		o << s;
	}
	else {
		cout << "Read error with outstream.";
	}

}

string stringFromIstream(istream& i) {
	if (!i.good()) {
		cout << "Read error with instream.";
		return "";
	}

	string s;
	i >> s;
	return s;
}

int main() {
	auto question = "What age are you? \n";

	stringToOstream(question, cout);
	auto response = stringFromIstream(cin);
	ofstream file("responses.txt");
	stringToOstream(response, file);

	return 0;
}