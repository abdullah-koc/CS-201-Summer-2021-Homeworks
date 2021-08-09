/*
* Title: Registration System
* Author: Muhammet Abdullah Koç
* ID: 21802832
* Section: 1
* Assignment: 3
* Description: ListOfCourseIDList class, keeps list of course id lists of students in registration system class
*/

#ifndef LISTOFCOURSEIDLIST_H
#define LISTOFCOURSEIDLIST_H

#include "CourseIDList.h"


class ListOfCourseIDList {
public:
    ListOfCourseIDList();

    ~ListOfCourseIDList();

    bool isEmpty() const;

    int getLength() const;

    bool retrieve(int index, CourseIDList *&dataItem) const;

    bool insert(CourseIDList newItem);

    bool remove(int index);


private:

    struct Node {
        CourseIDList item;
        Node *prev;
        Node *next;
    };
    int size;
    Node *head;

    Node *find(int index) const;
};


#endif //LISTOFCOURSEIDLIST_H
