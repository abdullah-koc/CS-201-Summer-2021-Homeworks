/*
* Title: Registration System
* Author: Muhammet Abdullah Koç
* ID: 21802832
* Section: 1
* Assignment: 3
* Description: Student class, keeps information of student
*/

#ifndef STUDENT_H
#define STUDENT_H


#include "CourseIDList.h"

class Student {
public:
    Student();

    Student(int studentID, string firstName, string lastName);

    int getStudentID();

    string getStudentFirstName();

    string getStudentLastName();

private:
    int studentID;
    string firstName;
    string lastName;
};


#endif //STUDENT_H
