
/* Programmer: Seth Lemanek
	Number in text : P7.6
	Description in text
	Write a function that returns a pointer to the maximum value of an array of floating point data :
			double* maximum(double a[], int a_size)

				Algorithm
				1. set pointer to the first element of array
				2. while incrementing pointer to a_size, compare values
				3. return pointer
*/
#include<iostream>

double* maximum(double a[], int a_size) {
	double* max = a;
	double* current = a;
	for (int i = 0; i < a_size; i++) {
		current++;
		if (*current > *max)
			max = current;
		}
	return max;
}


int main()
{
	const int A_SIZE = 6;
	double data[A_SIZE] = { 0.6, 22.0, 6.9, 3.3, 1.2, 0.0 };
	double* max = maximum(data, A_SIZE);
	std::cout << "The highest value is: " << *max << std::endl;
	return 0;
}
