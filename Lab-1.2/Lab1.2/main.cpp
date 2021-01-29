//
//  main.cpp
//  Lab1.2
//
//  Created by Moeen Khan on 8/29/20.
//  Copyright © 2020 Moeen Khan. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include<string.h>
#include<stdio.h>


using namespace std;

int main() {
    
    const int NUM_EMPL = 50;
    string names[NUM_EMPL];
    int emplIds[NUM_EMPL];
    int count = 0;
    
    ifstream inputFile;
    inputFile.open("names.txt");
    
    if(!inputFile){
        cout << "file Not found" << endl;
        system("pause");
        exit(1);
    }
    
    while(!inputFile.eof()){
        
        if(count >= 50){
            cout << "*** Exception *** array capacity exceeded" << endl;
            system("pause");
            exit(1);
        }
        
        inputFile >> names[count];
        emplIds[count] = count + 1001;
        count++;
    }
   
    int numberOfEmpl = count;
    
    for(int i = 0; i < numberOfEmpl; i++){
        cout << names[i] << ", " << emplIds[i] << endl;
    }
    
    int n = sizeof(names)/sizeof(names[0]);
    
    for (int j=0; j<n-1; j++)
    {
        for (int i=j+1; i<n; i++)
        {
            if (strcmp(name[j], names[i]) > 0)
            {
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[i]);
                strcpy(arr[i], temp);
            }
        }
    }
    
    
    ofstream outputFile;
    outputFile.open("results.txt");
    
    if(!outputFile){
        cout << "file not found" << endl;
        system("pause");
        exit(1);
    }
    
    int out = 0;
    while(out < numberOfEmpl){
        outputFile << names[out] << ", " << emplIds[out] << endl;
        out++;
    }
    
    return 0;
}

void sortStrings(char arr[][], int n)
{
    char temp[];
  
    // Sorting strings using bubble sort
    for (int j=0; j<n-1; j++)
    {
        for (int i=j+1; i<n; i++)
        {
            if (strcmp(arr[j], arr[i]) > 0)
            {
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[i]);
                strcpy(arr[i], temp);
            }
        }
    }
}
