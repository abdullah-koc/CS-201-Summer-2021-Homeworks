/*
* Title: Algebraic Expression
* Author: Muhammet Abdullah Koç
* ID: 21802832
* Section: 1
* Assignment: 4
* Description: AlgebraicExpression class that have methods
*/

#include "AlgebraicExpression.h"


//this method converts infix expression to postfix expression
string AlgebraicExpression::infix2postfix(const string exp) {
    Stack s;
    string temp;
    int itemIndex = 0;
    string postfix = "";

    //adding paranthesis to starting and ending of expression in order to calculate correctly
    string expNew = exp + ")";
    s.push("(");

    int size = expNew.length();

    //if input is empty, return empty string
    if (size <= 1) {
        return "";
    }

    temp = expNew[itemIndex];
    //for each character in expression
    for (int i = 0; i < size; i++) {

        //if character is operand, add to the postfix expression
        if (temp != "*" && temp != "/" && temp != "+" && temp != "-" && temp != "(" && temp != ")") {
            postfix += temp;
        }

            //if character is open paranthesis, push it to stack
        else if (temp == "(") {
            s.push(temp);
        }

            //if character is closing paranthesis, pop stack and add item to postfix expression until open paranthesis is reached
        else if (temp == ")") {
            string popItem;
            s.pop(popItem);
            while (popItem != "(") {
                postfix += popItem;
                s.pop(popItem);
            }
        }

            //if charactter is operator, while (!stack.isEmpty() and top of aStack is not '(' and precedence(character) <= precedence(top of stack),
            // add pop item to the postfix expression
        else if (temp == "*" || temp == "/" || temp == "+" || temp == "-") {
            string popItem;
            s.pop(popItem);
            while (!s.isEmpty() && (popItem == "*" || popItem == "/" || popItem == "+" || popItem == "-") &&
                   (precede(temp) <= precede(popItem))) {
                postfix += popItem;
                s.pop(popItem);
            }
            s.push(popItem); //push last item again because it is removed at last while loop
            s.push(temp); //push new operator
        }

        temp = expNew[++itemIndex]; //next item
    }
    return postfix;
}

//this method evaluates postfix expression and returns result
double AlgebraicExpression::evaluatePostfix(const string exp) {
    Stack s;
    string operand1;
    string operand2;
    int itemIndex = 0;
    string temp;
    temp = exp[itemIndex];
    int size = exp.length();

    //if size is 0 or 0/0 is entered, return 0
    if (size == 0 || exp == "00/") {
        return 0;
    }


    for (int i = 0; i < size; i++) {  //for each character in postfix form
        if (temp != "*" && temp != "/" && temp != "+" && temp != "-") { //if character is operand, push into stack
            s.push(temp);
        } else {
            s.pop(operand1);
            s.pop(operand2);
            //convert characters to double for calculation
            double op1 = sToD(operand1);
            double op2 = sToD(operand2);
            double res = calculate(op2, op1, temp); //calculation
            string toPush = dToS(res); //convert result to string for pushing into stack
            s.push(toPush);
        }
        temp = exp[++itemIndex];
    }
    string result;
    s.pop(result);
    return sToD(result); //returning result as double
}

//this function returns which of operations are preceded
int AlgebraicExpression::precede(const string op) {
    if (op == "*" || op == "/") {
        return 1;
    } else if (op == "+" || op == "-") {
        return 0;
    } else {
        return -1;
    }
}

//this function calculates equation
double AlgebraicExpression::calculate(double op1, double op2, string oprtr) {
    if (oprtr == "+") {
        return op1 + op2;
    }
    if (oprtr == "-") {
        return op1 - op2;
    }
    if (oprtr == "*") {
        return op1 * op2;
    }
    return op1 / op2;
}

//this function converts double to string
string AlgebraicExpression::dToS(const double d) {
    ostringstream s;
    s << d;
    return s.str();
}

//this function converts string to double
double AlgebraicExpression::sToD(const string s) {
    double d;
    istringstream(s) >> d;
    return d;
}

