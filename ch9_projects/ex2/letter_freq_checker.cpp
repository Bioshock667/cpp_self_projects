/* Self Assignment Project
   Programmer: Seth Lemanek
   Number in text: P9.3
   Description in text
	If you encrypt a file using the cipher of Exercise P9.2 (Random
	monoalphabet cipher) it will have all its letters jumbled up, and
	will look as if there is no hope of decrypting it without knowing 
	the keyword. ... The average letter frequencies of English letters
	are well known.  The most common letter is E, which occurs about 13
	percent of the time. 
	Write a program that reads an input file and displays the letter
       	frequencies in that file.  Such a tool will help a code breaker.
	If the most frequent letters in an encrypted file are H and K, then
	there is an excellent chance that they are the encryptions fo E and T.

   Algorithm
	1. Opens and reads a specified file character by character
	2. translate each character to an index integer
	3. the integer at that index will be incremented by 1
	4. calculate the sum and percentage into a double array
	5. return the double array
*/

#include "letter_freq_checker.h"

using namespace std;

double* letter_freq(ifstream& in) {
    double* num_occurences = new double[NUM_CHARS];
    char c;
    int index = 0;
    double total = 0;
    for(int i = 0; i < NUM_CHARS; i++)
	num_occurences[i] = 0;
    while(in.get(c)) {
	if(c >= 'A' && c <= 'Z') {
	    index = (int)c - 65;
	    num_occurences[index]++;
	    total++;
	}
    }
    for(int i = 0; i < NUM_CHARS; i++)
	num_occurences[i] /= total; //convert total occurences to a percentage out of the total
    return num_occurences;
}

