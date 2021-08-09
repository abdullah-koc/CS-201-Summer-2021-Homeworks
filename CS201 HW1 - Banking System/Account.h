/*
* Title: Banking System
* Author: Muhammet Abdullah Koç
* ID: 21802832
* Section: 1
* Assignment: 1
* Description: Header file for account class
*/

#ifndef BANKING_ACCOUNT_H
#define BANKING_ACCOUNT_H

#include "Customer.h"
#include "Branch.h"


class Account {
public:
    Account();

    Account(int accountId, Customer customer, Branch branch, double amount);

    int getAccountID();

    Customer getCustomer();

    Branch getBranch();

    double getAmount();

    void setAccountID(int id);

    void setCustomer(Customer newCustomer);

    void setBranch(Branch newBranch);

    void setAmount(double newAmount);

private:
    int accountId;
    Customer customer;
    Branch branch;
    double amount;
};


#endif //BANKING_ACCOUNT_H
