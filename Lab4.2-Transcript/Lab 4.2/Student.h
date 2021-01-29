//
//  Student.h
//  Lab 4.2
//
//  Created by Moeen Khan on 11/12/20.
//

#ifndef Student_h
#define Student_h
#include <vector>
#include <string>
#include "Course.h"
using namespace std;



class Student {

private:
    std::string name;
    int id;
    std::vector<Course> courses;
    public:
        Student(int id, std::string name) : id(id), name(name) {}
        std::string getName() const {return name;}
        int getId() const {return id;}
        double getGPA() const;
    vector<Course> &getCourses(){return courses;}
    void print(std::ostream &os) const;
    };

inline std::ostream &operator <<(std::ostream &os, const Student &student) {student.print(os); return os;}

#endif /* Student_h */
