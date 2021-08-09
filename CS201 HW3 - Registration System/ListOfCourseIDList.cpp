/*
* Title: Registration System
* Author: Muhammet Abdullah Koç
* ID: 21802832
* Section: 1
* Assignment: 3
* Description: ListOfCourseIDList class, keeps list of course id lists of students in registration system class
* This list keeps items sorted, therefore, index of student in student list equals to index of course id list in this class
*/

#include "ListOfCourseIDList.h"

ListOfCourseIDList::ListOfCourseIDList() {
    size = 0;
    head = NULL;
}

ListOfCourseIDList::~ListOfCourseIDList() {
    while (!isEmpty()) {
        remove(1);
    }
}

bool ListOfCourseIDList::isEmpty() const {
    return size == 0;
}

int ListOfCourseIDList::getLength() const {
    return size;
}

ListOfCourseIDList::Node *ListOfCourseIDList::find(int index) const {
    if ((index < 1) || (index > getLength()))
        return NULL;

    else {
        Node *cur = head;
        for (int skip = 1; skip < index; ++skip)
            cur = cur->next;
        return cur;
    }

}

bool ListOfCourseIDList::retrieve(int index, CourseIDList *&dataItem) const {
    if ((index < 1) || (index > getLength()))
        return false;

    Node *cur = find(index);
    dataItem = &cur->item;
    return true;
}


bool ListOfCourseIDList::insert(CourseIDList newItem) {
    int newLength = getLength() + 1;

    Node *newPtr = new Node;
    size = newLength;
    newPtr->item = newItem;

    int index = 1;
    for (int i = 1; i < getLength(); i++) {
        if (newItem.getStudentID() > find(i)->item.getStudentID()) {
            index++;
        }
    }
    if (getLength() == 1) {
        head = newPtr;
        newPtr->next = NULL;
        newPtr->prev = NULL;
        return true;
    }

    if (index == 1) {
        head->prev = newPtr;
        newPtr->next = head;
        newPtr->prev = NULL;
        head = newPtr;

    } else {
        Node *previ = find(index - 1);
        newPtr->next = previ->next;
        newPtr->prev = previ;
        if (previ->next != NULL) {
            previ->next->prev = newPtr;
        }
        newPtr->prev->next = newPtr;
    }
    return true;
}

bool ListOfCourseIDList::remove(int index) {
    Node *cur;

    if ((index < 1) || (index > getLength()))
        return false;


    if (getLength() == 1 && index == 1) {
        cur = head;
        head = NULL;
    } else if (index == 1) {
        cur = head;
        head->next->prev = NULL;
        head = head->next;
    } else if (index == getLength()) {
        cur = find(index);
        cur->prev->next = NULL;

    } else {
        cur = find(index);
        (cur->prev)->next = cur->next;
        (cur->next)->prev = cur->prev;
    }
    --size;
    cur->next = NULL;
    cur->prev = NULL;

    delete cur;
    cur = NULL;

    return true;
}