/*
* Title: Registration System
* Author: Muhammet Abdullah Koç
* ID: 21802832
* Section: 1
* Assignment: 3
* Description: Course class, keeps information of course
*/

#ifndef COURSE_H
#define COURSE_H

#include <iostream>

using namespace std;

class Course {
public:
    Course();

    Course(int courseID, string courseTitle);

    int getCourseID();

    string getCoursetitle();

private:
    int courseID;
    string courseTitle;
};


#endif //COURSE_H
