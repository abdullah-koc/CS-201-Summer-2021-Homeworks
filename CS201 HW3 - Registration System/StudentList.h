/*
* Title: Registration System
* Author: Muhammet Abdullah Koç
* ID: 21802832
* Section: 1
* Assignment: 3
* Description: StudentList class, keeps the list of students
*/

#ifndef STUDENTLIST_H
#define STUDENTLIST_H


#include "Student.h"

class StudentList {
public:
    StudentList();

    ~StudentList();

    bool isEmpty() const;

    int getLength() const;

    bool retrieve(int index, Student &dataItem) const;

    bool insert(Student newItem);

    bool remove(int index);


private:

    struct StudentNode {
        Student item;
        StudentNode *prev;
        StudentNode *next;
    };
    int size;
    StudentNode *head;

    StudentNode *find(int index) const;
};


#endif //STUDENTLIST_H
