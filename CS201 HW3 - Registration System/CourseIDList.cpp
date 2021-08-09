/*
* Title: Registration System
* Author: Muhammet Abdullah Koç
* ID: 21802832
* Section: 1
* Assignment: 3
* Description: CourseIDList class, keeps the list of course ids that a particular student takes
*/

#include "CourseIDList.h"

CourseIDList::CourseIDList() {
    studentID = -1;
    size = 0;
    head = NULL;
}

//initializing list with student id
CourseIDList::CourseIDList(int studentID) {
    this->studentID = studentID;
    size = 0;
    head = NULL;
}

int CourseIDList::getStudentID() {
    return studentID;
}

//Linkedlist methods

CourseIDList::~CourseIDList() {
    while (!isEmpty())
        remove(1);
}

bool CourseIDList::isEmpty() const {
    return size == 0;
}

int CourseIDList::getLength() const {
    return size;
}

CourseIDList::IndexNode *CourseIDList::find(int index) const {
    if ((index < 1) || (index > getLength()))
        return NULL;

    else {
        IndexNode *cur = head;
        for (int skip = 1; skip < index; ++skip)
            cur = cur->next;
        return cur;
    }

}

bool CourseIDList::retrieve(int index, int &dataItem) const {
    if ((index < 1) || (index > getLength()))
        return false;

    IndexNode *cur = find(index);
    dataItem = cur->item;
    return true;
}


bool CourseIDList::insert(int index, int newItem) {
    int newLength = getLength() + 1;

    if ((index < 1) || (index > newLength))
        return false;

    IndexNode *newPtr = new IndexNode;
    size = newLength;
    newPtr->item = newItem;

    if (index == 1) {
        newPtr->next = head;
        head = newPtr;
    } else {
        IndexNode *prev = find(index - 1);
        newPtr->next = prev->next;
        prev->next = newPtr;
    }
    return true;
}

bool CourseIDList::remove(int index) {
    IndexNode *cur;

    if ((index < 1) || (index > getLength()))
        return false;

    --size;
    if (index == 1) {
        cur = head;
        head = head->next;
    } else {
        IndexNode *prev = find(index - 1);
        cur = prev->next;
        prev->next = cur->next;
    }
    cur->next = NULL;
    delete cur;
    cur = NULL;

    return true;

}