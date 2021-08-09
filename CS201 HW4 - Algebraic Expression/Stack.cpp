/*
* Title: Algebraic Expression
* Author: Muhammet Abdullah Koç
* ID: 21802832
* Section: 1
* Assignment: 4
* Description: Stack class (ADT implementation of Stack)
*/

#include "Stack.h"

Stack::Stack() {
    topPtr = NULL;
}

//copy constructor
Stack::Stack(const Stack &aStack) {
    if (aStack.topPtr == NULL)
        topPtr = NULL;  // original stack is empty

    else {
        // copy first node
        topPtr = new StackNode;
        topPtr->item = aStack.topPtr->item;

        // copy rest of stack
        StackNode *newPtr = topPtr;
        for (StackNode *origPtr = aStack.topPtr->next;
             origPtr != NULL;
             origPtr = origPtr->next) {
            newPtr->next = new StackNode;
            newPtr = newPtr->next;
            newPtr->item = origPtr->item;
        }
        newPtr->next = NULL;
    }
}

//destructor
Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

//isEmpty method
bool Stack::isEmpty() const {
    return topPtr == NULL;
}

//push method
bool Stack::push(string newItem) {
    StackNode *newNode = new StackNode;
    newNode->item = newItem;

    newNode->next = topPtr;
    topPtr = newNode;
    return true;
}

//pop method
bool Stack::pop() {
    if (isEmpty()) {
        return false;
    } else {
        StackNode *temp = topPtr;
        topPtr = topPtr->next;
        temp->next = NULL;
        delete temp;
        return true;
    }
}

//pop method with returning pop item
bool Stack::pop(string &stackTop) {

    if (isEmpty())
        return false;
        // not empty; retrieve and delete top
    else {
        stackTop = topPtr->item;
        StackNode *temp = topPtr;
        topPtr = topPtr->next;
        // return deleted node to system
        temp->next = NULL;  // safeguard
        delete temp;
        return true;
    }
}

//getTop method
bool Stack::getTop(string &stackTop) const {

    if (isEmpty())
        return false;

        // stack is not empty; retrieve top
    else {
        stackTop = topPtr->item;
        return true;
    }

}

