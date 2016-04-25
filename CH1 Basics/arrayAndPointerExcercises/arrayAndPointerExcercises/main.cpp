//
//  Arrays and Pointers.cpp
//  Excercises
//
//  Created by Jay Howard on 4/14/16.
//  Copyright © 2016 Jay Howard. All rights reserved.
//
/*
From "Discovering Modern C++ An Intensive Course for Scientists, Engineers, and Programmerss"
Excercise 1.10.2
1. Write the following declarations: pointer to a character, array of 10 integers, pointer to an array of 10 integers, pointer to an array of character strings, pointer to pointer to a character, integer constant, pointer to an integer constant, constant pointer to an ingeter. Initialize all these objects

2. Make a small program that creates arrays on the stack (fixed-size arrays) and arrays on the head (using allocation). Use valgrind to check what happens when you do not delete them correctly.
*/

//Pointer practice for part one of the excercise
void partOne() {
	//point to a character
	char c;
	//pointer to above character
	char* pointToC = &c;
	//array of 10 integers
	int ints[10] = { 1,2,3,4,5,6,7,8,9, 10 };
	//pointer to above array of 10 integers
	int* pointToInts = ints;
	//point to an array of 10 chars
	char chars[10];
	char* pointToChars = chars;
	//pointer to pointer of character (points to pointsToC)
	char** pointToPointToChar = &pointToC;
	//constant integer
	const int constInt = 1;
	//pointer to integer constant
	int const* pointToConstInt = &constInt;
	//constant pointer to integer 
	int i = 1;
	int* const constPointToInt = &i;

}

void partTwo() {
	int ints[200];

}

int main() {
	partOne();
	partTwo();
	return 0;
}