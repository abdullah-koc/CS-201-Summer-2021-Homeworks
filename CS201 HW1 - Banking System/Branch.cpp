/*
* Title: Banking System
* Author: Muhammet Abdullah Koç
* ID: 21802832
* Section: 1
* Assignment: 1
* Description: Branch class that have properties Branch ID and Branch Name
*/

#include "Branch.h"

Branch::Branch() {
    branchId = -1;
    branchName = "";
}

Branch::Branch(int branchId, string branchName) {
    this->branchId = branchId;
    this->branchName = branchName;
}

int Branch::getBranchId() {
    return branchId;
}

string Branch::getBranchName() {
    return branchName;
}

void Branch::setBranchID(int id) {
    branchId = id;
}

void Branch::setBranchName(string name) {
    branchName = name;
}