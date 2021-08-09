/*
* Title: Registration System
* Author: Muhammet Abdullah Koç
* ID: 21802832
* Section: 1
* Assignment: 3
* Description: StudentList class, keeps the list of students (sorted doubly linked list)
*/

#include "StudentList.h"

StudentList::StudentList() {
    size = 0;
    head = NULL;
}

//Linkedlist methods

StudentList::~StudentList() {
    while (!isEmpty()) {
        remove(1);
    }
}

bool StudentList::isEmpty() const {
    return size == 0;
}

int StudentList::getLength() const {
    return size;
}

StudentList::StudentNode *StudentList::find(int index) const {
    if ((index < 1) || (index > getLength()))
        return NULL;

    else {
        StudentNode *cur = head;
        for (int skip = 1; skip < index; ++skip)
            cur = cur->next;
        return cur;
    }

}

bool StudentList::retrieve(int index, Student &dataItem) const {
    if ((index < 1) || (index > getLength()))
        return false;

    StudentNode *cur = find(index);
    dataItem = cur->item;
    return true;
}


bool StudentList::insert(Student newItem) {
    int newLength = getLength() + 1;

    StudentNode *newPtr = new StudentNode;
    size = newLength;
    newPtr->item = newItem;

    //finding index where student will be inserted according to his/her student id
    int index = 1;
    for (int i = 1; i < getLength(); i++) {
        if (newItem.getStudentID() > find(i)->item.getStudentID()) {
            index++;
        }
    }

    //if new item is the first, insert it into head
    if (getLength() == 1) {
        head = newPtr;
        newPtr->next = NULL;
        newPtr->prev = NULL;
        return true;
    }

    //if size is larger than 1, and new item will be inserted into head, do operations
    if (index == 1) {
        head->prev = newPtr;
        newPtr->next = head;
        newPtr->prev = NULL;
        head = newPtr;

    } else {
        StudentNode *previ = find(index - 1);
        newPtr->next = previ->next;
        newPtr->prev = previ;
        if (previ->next != NULL) {
            previ->next->prev = newPtr;
        }
        newPtr->prev->next = newPtr;
    }
    return true;
}

bool StudentList::remove(int index) {
    StudentNode *cur;

    if ((index < 1) || (index > getLength()))
        return false;


    //if list has one element and this element will be deleted
    if (getLength() == 1 && index == 1) {
        cur = head;
        head = NULL;
    } else if (index == 1) { //if list size > 1 and first element will be deleted
        cur = head;
        head->next->prev = NULL;
        head = head->next;
    } else if (index == getLength()) { //if last element of list will be deleted
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