//
//  gcd.h
//  Lab4
//
//  Created by Moeen Khan on 11/6/20.
//

#ifndef gcd_h
#define gcd_h

inline int gcd(int a, int b) {return b == 0 ? a : gcd(b, a % b);}

#endif /* gcd_h */
