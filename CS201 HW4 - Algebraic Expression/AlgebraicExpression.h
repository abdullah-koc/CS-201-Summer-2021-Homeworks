/*
* Title: Algebraic Expression
* Author: Muhammet Abdullah Koç
* ID: 21802832
* Section: 1
* Assignment: 4
* Description: Header file for Algebraic Expression class
*/

#ifndef ALGEBRAICEXPRESSION_H
#define ALGEBRAICEXPRESSION_H

#include "Stack.h"
#include <sstream>

class AlgebraicExpression {
public:

// It converts an infix expression exp to its equivalent postfix form .
    string infix2postfix(const string exp);

// It evaluates a postfix expression .
    double evaluatePostfix(const string exp);

private:

    string dToS(const double d); //converting double to string

    double sToD(const string s); //converting string to double

    int precede(const string op); //returning preceded operation

    double calculate(double op1, double op2, string oprtr); //calculating expression
};


#endif //ALGEBRAICEXPRESSION_H
