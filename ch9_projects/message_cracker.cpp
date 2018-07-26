#include "ex2/letter_freq_checker.h"

#include <iostream>
#include <iomanip>
#include <fstream>

int main(int argc, char* argv[]) {
    if(argc < 1) {
	    std::cout << "please include a filename!\n";
        return 0;
    }
    std::ifstream file(argv[1]);
    double* frequencies = letter_freq(file);
    char c = 'A';
    double percent;
    for(int i = 0; i < NUM_CHARS; i++) {
	    percent = frequencies[i] * 100;
	    std::cout << c << std::setw(8) << std::fixed <<std::setprecision(2) << percent << "%\n";
	    c++;
    }


    return 1;
}
