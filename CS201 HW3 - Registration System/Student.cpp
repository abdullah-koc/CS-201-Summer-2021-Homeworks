/*
* Title: Registration System
* Author: Muhammet Abdullah Koç
* ID: 21802832
* Section: 1
* Assignment: 3
* Description: Student class, keeps information of student
*/

#include "Student.h"

Student::Student() {
    studentID = -1;
    firstName = "";
    lastName = "";
}

Student::Student(int studentID, string firstName, string lastName) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
}


int Student::getStudentID() {
    return studentID;
}

string Student::getStudentFirstName() {
    return firstName;
}

string Student::getStudentLastName() {
    return lastName;
}

