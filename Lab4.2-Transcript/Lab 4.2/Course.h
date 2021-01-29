//
//  Course.h
//  Lab 4.2
//
//  Created by Moeen Khan on 11/12/20.
//

#ifndef Course_h
#define Course_h
#include <iostream>
using namespace std;

class Course{
private:
    int code;
    int credits;
    char grade;
public:
    Course(int code, int credits, int grade) : code(code), credits(credits), grade(grade) {};

    int getCode() const {return code;}
    int getCredits() const {return credits;}
    int getGrade() const {return grade;}
    void print(std::ostream &os) const{
        os << "\t" << code << " (" << credits << " credits): " << grade << endl;
    }
//    void print(std::ostream &os, const Course &course) const;

};

inline std::ostream &operator <<(std::ostream &os, const Course &course) {course.print(os); return os;}

#endif /* Course_h */
