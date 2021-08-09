/*
* Title: Registration System
* Author: Muhammet Abdullah Koç
* ID: 21802832
* Section: 1
* Assignment: 3
* Description: RegistrationSystem class header
*/

#ifndef REGISTRATIONSYSTEM_H
#define REGISTRATIONSYSTEM_H

#include "StudentList.h"
#include "CourseList.h"
#include "ListOfCourseIDList.h"

class RegistrationSystem {
public :
    RegistrationSystem();

    ~ RegistrationSystem();

    void addStudent(const int studentId, const string firstName, const string lastName);

    void deleteStudent(const int studentId);

    void addCourse(const int studentId, const int courseId, const string courseName);

    void withdrawCourse(const int studentId, const int courseId);

    void cancelCourse(const int courseId);

    void showStudent(const int studentId);

    void showCourse(const int courseId);

    void showAllStudents();

private:
    StudentList studentList;
    CourseList courseList;
    ListOfCourseIDList listOfCourseIdList;

    void showStudentHelper(int studentID, bool isPrint);

    Course findCourseFromID(const int courseID);

    Student findStudentFromID(const int studentID, int &index);

};


#endif //REGISTRATIONSYSTEM_H
