/* Self Assignment Project
 * Programmer: Seth Lemanek
 * Date: July 23, 2018
 * Number in text: p9.2
 * Description in text
 * 	The Ceaser cipher, which shifts all letters by a fixed amount, is far too easy to crack.
 * 	Here's a better idea. As the key, don't use numbers but words. Suppose the keyword is FEATHER.
 * 	Then first remove duplicate letters, yielding FEATHR, and append the other letters of the 
 * 	alphabet the other letters of the alphabet in reverse order.
 */

#include "mono_cipher.h"

void encrypt(std::string key, std::ifstream& in, std::ofstream& out) {
    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string s_key;
    size_t pos;
    //go through the characters in key, if found in alphabet take from alphabet and put into s_key
    for(int i = 0; i < key.length(); i++) {
	pos = alphabet.find(key[i]);		//Author Note: Even though the writer asks to remove duplicate chars in the key
	if(pos != std::string::npos) {		//I felt that continously removing and finding chars in alphabet that are in key
	    alphabet.erase(pos, 1);		//avoids the duplicate issue when checking for npos after finding an already taken char
	    s_key += key[i];
	}
    }
    std::string::iterator s = alphabet.end() - 1;
    for(; s != alphabet.begin(); s--)
    	s_key += *s; //append the rest of the alphabet to the key in reverse order

    char c;
    while(in.get(c)) {
	if( c >= 'A' && c <= 'Z') {
	    int i = (int)c - 65; //get the offset from 'A' and use as index for new character
	    out.put(s_key[i]);
	} else
	    out.put(c);
    }
}
