#include "mono_cipher.h"

#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
    if(argc < 2) {
	    std::cout << "please include two filenames!\n";
        return 0;
    }
    std::ifstream infile(argv[1]);
    std::ofstream outfile(argv[2]);
    encrypt("FEATHER", infile, outfile);
    std::cout << "Encyption complete!\n";
    return 1;
}
