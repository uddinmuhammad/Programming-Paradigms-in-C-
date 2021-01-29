//
//  RationalException.h
//  Lab4
//
//  Created by Moeen Khan on 11/6/20.
//

#ifndef RationalException_h
#define RationalException_h

#include <string>

using namespace std;

class RationalException {
public:
    RationalException(string message) : message(message) {}
    string getMessage() {return message;}
private:
    string message;
};

#endif /* RationalException_h */
