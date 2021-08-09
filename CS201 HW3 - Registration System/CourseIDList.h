/*
* Title: Registration System
* Author: Muhammet Abdullah Koç
* ID: 21802832
* Section: 1
* Assignment: 3
* Description: CourseIDList class, keeps the list of course ids that a particular student takes
*/

#ifndef COURSEIDLIST_H
#define COURSEIDLIST_H

#include <iostream>

using namespace std;

class CourseIDList {
public:
    CourseIDList();

    CourseIDList(int studentID);

    ~CourseIDList();

    int getStudentID();

    bool isEmpty() const;

    int getLength() const;

    bool retrieve(int index, int &dataItem) const;

    bool insert(int index, int newItem);

    bool remove(int index);


private:
    int studentID;

    struct IndexNode {
        int item;
        IndexNode *next;
    };
    int size;
    IndexNode *head;

    IndexNode *find(int index) const;
};


#endif //COURSEIDLIST_H
