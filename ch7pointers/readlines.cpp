
#include <iostream>
#include <cstdio>
/*
Programmer: Seth Lemanek
Number in text : P7.13
Description in text
Write a program that reads lines of text and appends them to a char buffer[1000].  Stop after reading 1000 characters.  As you read them,
replace all newline characters '\n' with '\0' terminators.  Establish an array char* lines[1000], so that the pointers in that array point to the beginnings
of the lines in text.  Only consider 100 input lines if input has more lines. then display the lines in reverse order.

Algorithm
1. read characters one-by-one until 1000 chars have been entered, replacing each enter with null chars
2. declare an array of pointers (char strings)
3. Set each value to each null terminated string
4. Print the array of C-strings in reverse order
*/
int main() {
	const int NUM_LINES = 100;
	const int LINE_LENGTH = 10;
	const int STRING_LENGTH = NUM_LINES * LINE_LENGTH;
	char buffer[STRING_LENGTH];
	for (int i = 0; i < STRING_LENGTH - 1; i++) {
		buffer[i] = std::getchar(); //What I learned: cin buffers chars by wait for enter key.  To get the I/O to read individual chars, it requires certain libraries based on OS.
		if (buffer[i] == '\n')
			buffer[i] = (char)0;
	}
	buffer[STRING_LENGTH - 1] = '\0';
	char* lines[NUM_LINES];
	for (int i = 0; i < NUM_LINES; i++) {
		lines[i] = buffer + LINE_LENGTH * i;
	}
	for (int i = NUM_LINES - 1;i  >= 0; i--) {
		std::cout << lines[i] << " ";
	}
	std::cout << "\n";
}
