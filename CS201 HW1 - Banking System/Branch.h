/*
* Title: Banking System
* Author: Muhammet Abdullah Koç
* ID: 21802832
* Section: 1
* Assignment: 1
* Description: Header file for Branch class
*/

#ifndef BRANCH_H
#define BRANCH_H

#include <iostream>

using namespace std;

class Branch {
public:
    Branch();

    Branch(int branchId, string branchName);

    int getBranchId();

    string getBranchName();

    void setBranchID(int id);

    void setBranchName(string name);

private:
    int branchId;
    string branchName;
};


#endif //BRANCH_H
