/*
* Title: Registration System
* Author: Muhammet Abdullah Koç
* ID: 21802832
* Section: 1
* Assignment: 3
* Description: CourseList class, keeps list of courses
*/

#ifndef REGISTRATION_SYSTEM_COURSELIST_H
#define REGISTRATION_SYSTEM_COURSELIST_H

#include <iostream>
#include "Course.h"

using namespace std;

class CourseList {
public:
    CourseList();

    ~CourseList();

    bool isEmpty() const;

    int getLength() const;

    bool retrieve(int index, Course &dataItem) const;

    bool insert(int index, Course newItem);

    bool remove(int index);


private:

    struct CourseNode {
        Course item;
        CourseNode *next;
    };
    int size;
    CourseNode *head;

    CourseNode *find(int index) const;
};


#endif //REGISTRATION_SYSTEM_COURSELIST_H
