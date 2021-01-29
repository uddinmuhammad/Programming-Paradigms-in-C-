//
//  main.cpp
//  Lab 4.2
//
//  Created by Moeen Khan on 11/12/20.
//

#include <string>
#include <vector>
//#include "Course.h"
#include "Student.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

void write(const vector<Student> &students);
bool compare(const Student &stu1, const Student &stu2);

int main(int argc, const char * argv[]) {
    

    ifstream inputFile;
    inputFile.open("Students.txt");
    string word;
    
    if(!inputFile){
        cout << "*** Exception *** input file names.data not found" << endl;
        system("pause");
        exit(1);
    }
    vector<Student> students;
    int id;
    string name;
    int code = 0;
    int credits = 0;
    char grade;

    
    while(!inputFile.eof()){
        int code = 0;
        inputFile >> id;
        inputFile >> name;
        Student student(id, name);
        
        while(code != -1){
            inputFile >> code;
            if(code == -1){
                credits = 0;
                grade = 'Z';
            }
            else{
                inputFile >> credits;
                inputFile >> grade;
                student.getCourses().push_back(Course(code, credits, grade));
            }
        }
        students.push_back(student);
    }
    inputFile.close();
    sort(students.begin(), students.end(), compare);
    write(students);
    
    cout << "\n" << students.size() << " records processed" << endl;
    
    return 0;
}

bool compare(const Student &stu1, const Student &stu2)
{
    return stu1.getGPA() > stu2.getGPA();
}

void write(const vector<Student> &students)
{
    for (auto student : students)
        std::cout << student;
    cout << endl;
}
