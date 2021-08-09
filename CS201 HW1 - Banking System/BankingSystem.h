/*
* Title: Banking System
* Author: Muhammet Abdullah Koç
* ID: 21802832
* Section: 1
* Assignment: 1
* Description: Header file for Banking System class
*/

#ifndef BANKINGSYSTEM_H
#define BANKINGSYSTEM_H

#include <iostream>
#include "Account.h"

using namespace std;

class BankingSystem {
public :
    BankingSystem();

    ~ BankingSystem();

    void addBranch(const int branchId, const string branchName);

    void deleteBranch(const int branchId);

    void addCustomer(const int customerId, const string customerName);

    void deleteCustomer(const int customerId);

    int addAccount(const int branchId, const int customerId, const double amount);

    void deleteAccount(const int accountId);

    void showAllAccounts();

    void showBranch(const int branchId);

    void showCustomer(const int customerId);

private:

    void deleteAccountHelper(const int accountId, const bool isPrint);

    Account findAccountFromId(const int accountId);

    Customer findCustomerFromId(const int customerId);

    Branch findBranchFromId(const int branchId);

    Account *accounts;
    int accountSize;
    Customer *customers;
    int customerSize;
    Branch *branches;
    int branchSize;
    int accountId;

};


#endif //BANKINGSYSTEM_H
