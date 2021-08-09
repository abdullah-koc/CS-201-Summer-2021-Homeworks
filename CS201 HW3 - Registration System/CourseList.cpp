/*
* Title: Registration System
* Author: Muhammet Abdullah Koç
* ID: 21802832
* Section: 1
* Assignment: 3
* Description: CourseList class, keeps list of courses
*/

#include "CourseList.h"

CourseList::CourseList() {
    size = 0;
    head = NULL;
}


//Linkedlist methods

CourseList::~CourseList() {
    while (!isEmpty())
        remove(1);
}

bool CourseList::isEmpty() const {
    return size == 0;
}

int CourseList::getLength() const {
    return size;
}

CourseList::CourseNode *CourseList::find(int index) const {
    if ((index < 1) || (index > getLength()))
        return NULL;

    else {
        CourseNode *cur = head;
        for (int skip = 1; skip < index; ++skip)
            cur = cur->next;
        return cur;
    }

}

bool CourseList::retrieve(int index, Course &dataItem) const {
    if ((index < 1) || (index > getLength()))
        return false;

    CourseNode *cur = find(index);
    dataItem = cur->item;
    return true;
}


bool CourseList::insert(int index, Course newItem) {
    int newLength = getLength() + 1;

    if ((index < 1) || (index > newLength))
        return false;

    CourseNode *newPtr = new CourseNode;
    size = newLength;
    newPtr->item = newItem;

    if (index == 1) {
        newPtr->next = head;
        head = newPtr;
    } else {
        CourseNode *prev = find(index - 1);
        newPtr->next = prev->next;
        prev->next = newPtr;
    }
    return true;
}

bool CourseList::remove(int index) {
    CourseNode *cur;

    if ((index < 1) || (index > getLength()))
        return false;

    --size;
    if (index == 1) {
        cur = head;
        head = head->next;
    } else {
        CourseNode *prev = find(index - 1);
        cur = prev->next;
        prev->next = cur->next;
    }
    cur->next = NULL;
    delete cur;
    cur = NULL;

    return true;
}