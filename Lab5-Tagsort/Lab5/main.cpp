//
//  main.cpp
//  Lab5
//
//  Created by Moeen Khan on 12/1/20.
//


#include <iostream>
#include <fstream>
#include <cstdlib>

#include "tagsort.h"

using namespace std;

int main() {
    try {
        const int CAPACITY=100;
        int a[CAPACITY];
        int *ap[CAPACITY];
        int size = 0;

        ifstream ifs("numbers.txt");
        if (!ifs) {
            cout << "file not found" << endl;
            exit(1);
        }

        int num;
        ifs >> num;

        while (ifs) {
            if (size == CAPACITY) throw string("Array capacity exceeded");
            a[size] = num;
            ap[size] = &a[size];
            size++;
            ifs >> num;
        }

        cout << "Before sort:" << endl;
        cout << "(through the pointer array): ";
        for (int i = 0; i < size; i++)
            cout << *ap[i] << (i < size-1 ? ", " : "");
        cout << endl;
        cout << "(through the data array): ";
        for (int i = 0; i < size; i++)
            cout << a[i] << (i < size-1 ? ", " : "");
        cout << endl << endl;

        sort(ap, size);

        cout << "After sort:" << endl;
        cout << "(through the pointer array): ";
        for (int i = 0; i < size; i++)
            cout << *ap[i] << (i < size-1 ? ", " : "");
        cout << endl;
        cout << "(through the data array): ";
        for (int i = 0; i < size; i++)
            cout << a[i] << (i < size-1 ? ", " : "");
        cout << endl;

    } catch (string msg) {
        cerr << "**** Error *** " << msg << endl;
        return 1;
    }
}
