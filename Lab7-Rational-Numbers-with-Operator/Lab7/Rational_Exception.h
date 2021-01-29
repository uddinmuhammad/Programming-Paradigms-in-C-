//
//  Rational_Exception.h
//  Lab7
//
//  Created by Moeen Khan on 12/10/20.
//

#ifndef Rational_Exception_h
#define Rational_Exception_h

#include <string>

using namespace std;

class RationalException {
public:
    RationalException(string what) : what(what) {}
    string getWhat() {return what;}
private:
    string what;
};

#endif /* Rational_Exception_h */
