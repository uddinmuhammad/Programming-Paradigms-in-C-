//
//  Simple.hpp
//  Lab3.2.1
//
//  Created by Moeen Khan on 11/3/20.
//

#ifndef Simple_hpp
#define Simple_hpp

#include <stdio.h>




#include <iostream>
using namespace std;


template <class T>
class Simple{
        private:
            T value;
        public:
    Simple<T>(T value) : value(value) {};
    T getVal() {return value;};
            void setVal(T val);
            void print();
    };

    template<class T>
    void Simple<T>::setVal(T val){
            value = val;
        }
    template<class T>
    void Simple<T>::print(){
            cout << value << endl;
        }
#endif /* Simple_hpp */
