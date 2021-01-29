//
//  main.cpp
//  Lab6
//
//  Created by Moeen Khan on 12/1/20.
//

#include <iostream>
#include "cstring.h"

using namespace mystring;
using std::cout;
using std::endl;

int main() {
    char s1[100] = "Hello", s2[100] = "world", s3[100];

    cout << "s1: " << s1 << ": (" << mystring::strlen(s1) << ")" << endl;
    cout << "s2: " << s2 << ": (" << mystring::strlen(s2) << ")" << endl;

    cout << "strcpy: " << mystring::strcpy(s3, s1) << endl;

    cout << "s3: " << s3 << ": (" << mystring::strlen(s3) << ")" << endl;

    cout << "strcat: " << mystring::strcat(s3,  " ") << endl;

    cout << "s3: " << s3 << ": (" << mystring::strlen(s3) << ")" << endl;

    cout << "strcat: " << mystring::strcat(s3,  s2) << endl;

    cout << s3 << ": " << mystring::strlen(s3) << endl;

    char s4[100];

    cout << mystring::strcat(mystring::strcat(mystring::strcpy(s4, s1), " "), s2) << endl;

    cout << s4 << ": " << mystring::strlen(s4) << endl;

    
    const char *pos = strchr(s1, 'e');
    if (!pos)
        cout << "'e' not found in " << s1 << endl;
    else
        cout << "'e' found at position " << (pos - s1) << " in " << s1 << endl;

    pos = strchr(s1, 'q');
    if (!pos)
        cout << "'q' not found in " << s1 << endl;
    else
        cout << "'q' found at position " << (pos - s1) << " in " << s1 << endl;

    pos = strchr(s4, 'l');
    if (!pos)
        cout << "'l' not found in " << s4 << endl;
    else
        cout << "'l' found at position " << (pos - s4) << " in " << s4 << endl;

    pos = strrchr(s4, 'l');
    if (!pos)
        cout << "'l' not found in " << s4 << endl;
    else
        cout << "'l' last found at position " << (pos - s4) << " in " << s4 << endl;

    pos = strrchr(s4, ',');
    if (!pos)
        cout << "',' not found in " << s4 << endl;
    else
        cout << "',' last found at position " << (pos - s1) << " in " << s4 << endl;
    
    cout << "strcmp(s1, s1): " << mystring::strcmp(s1, s1) << endl;
    cout << "strcmp(s1, s2): " << mystring::strcmp(s1, s2) << endl;
    cout << "strcmp(s2, s1): " << mystring::strcmp(s2, s1) << endl;
    cout << "strcmp(s1, s4): " << mystring::strcmp(s1, s4) << endl;
    

    return 0;
     
}


