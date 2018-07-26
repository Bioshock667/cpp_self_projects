
/* Programmer: Seth Lemanek
Number in text : P7.17
Description in text
Implement a function
	void fill_with_values(int[] a, int size, IntFunPointer f)
that sets the ith element of array a to f(i).  Here IntFunPointer is a typedef for a pointer
to a function that consumes an int and yields an int.  Provide a main function in which you call
the fill_with_values function so that an array of ten integers is filled with 1, 4, 9, 16, 25, ..., 100.

Algorithm
1. Set each value of a to the return result of a function with i passed to it
*/

#include<iostream>

int square(int x) {
	return x * x;
}

typedef int (*IntFunPointer)(int);

void fill_with_values(int* a, int size, IntFunPointer f) {
	for (int i = 0; i < size; i++) {
		a[i] = (*f)(i);
	}
}

int main() {
	const int A_SIZE = 11;
	int a[A_SIZE];
	fill_with_values(a, A_SIZE, &square);
	for (int i = 0; i < A_SIZE; i++) {
		std::cout << a[i] << std::endl;
	}
}
