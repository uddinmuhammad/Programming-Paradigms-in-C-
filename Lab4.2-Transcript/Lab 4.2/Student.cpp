//
//  Student.cpp
//  Lab 4.2
//
//  Created by Moeen Khan on 11/12/20.
//

#include "Student.h"
//#include "Course.h"
//

double findScore(char grade){
    double score = 0.0;
    switch (grade) {
        case 'A':
            score = 4.0;
            break;
        case 'B':
            score = 3.0;
            break;
        case 'C':
            score = 2.0;
            break;
        case 'D':
            score = 1.0;
            break;
        case 'F':
            score = 0.0;
            break;
        default:
            break;
    }
    return score;
}

double Student::getGPA() const{
    double points = 0.0;
    int totalCredits = 0;

    for(int i = 0; i < courses.size(); i++){
        points += findScore(courses[i].getGrade()) * courses[i].getCredits();
        totalCredits += courses[i].getCredits();
    }
    return points/totalCredits;
}
void Student::print(std::ostream &os) const{
    os << id << " " << name << ": " << getGPA() << endl;
    
    for (auto course : courses)
    {
        os << course;
    }
}
