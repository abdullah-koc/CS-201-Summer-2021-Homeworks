/*
* Title: Registration System
* Author: Muhammet Abdullah Koç
* ID: 21802832
* Section: 1
* Assignment: 3
* Description: Course class, keeps information of course
*/

#include "Course.h"

Course::Course() {
    courseID = -1;
    courseTitle = "";
}

Course::Course(int courseID, string courseTitle) {
    this->courseID = courseID;
    this->courseTitle = courseTitle;
}

int Course::getCourseID() {
    return courseID;
}

string Course::getCoursetitle() {
    return courseTitle;
}