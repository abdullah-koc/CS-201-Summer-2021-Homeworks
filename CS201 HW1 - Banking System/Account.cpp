/*
* Title: Banking System
* Author: Muhammet Abdullah Koç
* ID: 21802832
* Section: 1
* Assignment: 1
* Description: Account class that have the properties Account ID, Customer, Branch and Amount
*/

#include "Account.h"

#include <iostream>

Account::Account() {
    accountId = -1;
    customer = Customer();
    branch = Branch();
}

Account::Account(int accountId, Customer customer, Branch branch, double amount) {
    this->accountId = accountId;
    this->customer = customer;
    this->branch = branch;
    this->amount = amount;
}

int Account::getAccountID() {
    return accountId;
}

Branch Account::getBranch() {
    return branch;
}

Customer Account::getCustomer() {
    return customer;
}

double Account::getAmount() {
    return amount;
}


void Account::setAccountID(int id) {
    accountId = id;
}

void Account::setBranch(Branch newBranch) {
    branch = newBranch;
}

void Account::setCustomer(Customer newCustomer) {
    customer = newCustomer;
}

void Account::setAmount(double newAmount) {
    amount = newAmount;
}
