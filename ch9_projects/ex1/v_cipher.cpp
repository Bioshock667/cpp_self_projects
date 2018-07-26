/* Self Assignment Project
 * Programmer: Seth Lemanek
 * Number in text: P9.4
 * Description in text:
 * 	Vigenere Cipher.  The trouble with a monoalphabetic cipher is that it
 * can be easily broken by frequency analysis.  The so-called Vigenere cipher
 * overcomes this problem by encoding a letter into one of several cipher 
 * letters, depending on its position in the input document.  Choose a keyword,
 * for example TIGER.  Then encode the first letter like this:
 * ____________________________________________________
 * |A|B|C|D|E|F|G|H|I|J|K|L|M|N|O|P|Q|R|S|T|U|V|W|X|Y|Z|
 * ____________________________________________________
 * |T|U|V|W|X|Y|Z|A|B|C|D|E|F|G|H|I|J|K|L|M|N|O|P|Q|R|S|

 * The encoded alphabet is just the regular alphabet shifted to start at T, the
 * first letter of the keyword TIGER.  The second letter is encrypted according
 * to the following map.
 * ______________________________________________________
 * |A|B|C|D|E|F|G|H|I|J|K|L|M|N|O|P|Q|R|S|T|U|V|W|X|Y|Z|
 * _____________________________________________________
 * |I|K|J|L|M|N|O|P|Q|R|S|T|U|V|W|X|Y|Z|A|B|C|D|E|F|G|H|
 *
 * The third, fourth, and fifth letters in the input text are encrypted using 
 * the alphabet sequences beginning with G, E, and R, and so on.  Because the
 * key is only five letters long, the sixth letter of the input text is encry-
 * pted in the same way as the first.
 */
#include <fstream>
#include <string>
#include <iostream>
#include <cstring> //strlen
using namespace std;
/*
 * Prints usage instructions
 * @param program_name: The name of this program
 */
void usage(string program_name) {
    cout << "Usage: " << program_name << " [-k key][-e][-d] infile outfile\n";
}
/*
 * Outputs an error message to the user and then terminates the program.
 * @param message: the message that the user will see.
 */
void error(string message) {
    cout << "Error: " << message << endl;
    exit(1);
}
/* Outputs a file error message that points to a file
 * @param file_name the name of the file that failed to open
 */
void open_file_error(string file_name) {
    string message = "Cannot open file ";
    message += file_name;
    error(message);
}
/*
 * Computes correct remainder for negative dividend.
 * @param a an integer
 * @param n an integer > 0
 * @return the mathematically correct remainder r such that
      a - r is divisible by n and 0 <= r and r < n
*/
int remainder(int a, int n) {
	if (a >= 0)
	    return a % n;
	else
	    return n - 1 - (-a - 1) % n;
}
/* Encrypts a character using the Caesar cipher.
 * @param ch the character to encrypt
 * @param k the encryption key
 * @return the encrypted character
*/
char encrypt(char ch, int k) {
    const int NLETTER = 'Z' - 'A' + 1;
    if('A' <= ch && ch <= 'Z')
	return static_cast<char> (
			'A' + remainder(ch - 'A' + k, NLETTER));
    if('a' <= ch && ch <= 'z')
	return static_cast<char>(
			'a' + remainder(ch - 'a' + k, NLETTER));
    return ch;
}
/* Encrypts a stream using the Vigenere cipher.
 * @param in the stream to read from
 * @param out the stream to write to
 * @param key the encryption key
 * @param e encrypt/decrypt flag
*/
void e_d_file(istream& in, ostream& out, char* key, bool e) {
    char ch;
    int i = 0, offset;
    int size = strlen(key);
    while(in.get(ch)) {
	offset = key[i++] - 'A';
	if(!e)
	    offset = -offset;
	out.put(encrypt(ch,offset));
	if(i >= size)
	    i = 0;
    }
}
int main(int argc, char* argv[]) {
    if(argc == 1){
	    usage(string(argv[0]));
	    return 1;
    }
    bool e = true;
    char option;
    char* key = "TIGER";
    int nfile = 0;
    ifstream infile;
    ofstream outfile;
    for(int i = 1; i < argc; i++){
    	if(argv[i][0] == '-'){
	    option = argv[i][1];
	    if(option == 'd')
	   	 e = false;
	    else if (option == 'e')
	   	 e = true;
	    else if (option == 'k') 
	    	key = argv[++i]; //set key to the string immediately after and increment
	    else 
	   	 error("Invalid Option");
	}else {
	    nfile++;
	    if(nfile == 1){
		infile.open(argv[i]);
		if(infile.fail())
		    open_file_error(string(argv[i]));
	    }
	    else if (nfile == 2) {
		outfile.open(argv[i]);
		if(outfile.fail())
		    open_file_error(string(argv[i]));
	    }
	}
    }
    if(nfile !=2)
	usage(string(argv[0]));
    e_d_file(infile, outfile, key, e);
    infile.close();
    outfile.close();
}
