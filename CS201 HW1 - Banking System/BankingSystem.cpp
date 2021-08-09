/*
* Title: Banking System
* Author: Muhammet Abdullah Koç
* ID: 21802832
* Section: 1
* Assignment: 1
* Description: Banking system class that have several methods
*/

#include <iomanip>
#include "BankingSystem.h"

//Constructor for Banking System that initializes arrays
BankingSystem::BankingSystem() {
    accounts = NULL;
    accountSize = 0;

    customers = NULL;
    customerSize = 0;

    branches = NULL;
    branchSize = 0;

    accountId = 1;
}

//Destructor for BankingSystem class
BankingSystem::~BankingSystem() {
    delete[] accounts;
    delete[] customers;
    delete[] branches;
}

//This method adds branch to the system
void BankingSystem::addBranch(const int branchId, const string branchName) {

    //if there is a branch with same id, show error message and return
    for (int i = 0; i < branchSize; i++) {
        if (branches[i].getBranchId() == branchId) {
            cout << "Branch " << branchId << " already exists." << endl;
            return;
        }
    }

    //adding new branch to the  branch array
    if (branchSize == 0) {
        branches = new Branch[1];
        branches[0] = Branch(branchId, branchName);
    } else {
        Branch *temp = new Branch[branchSize + 1];
        for (int i = 0; i < branchSize; i++) {
            temp[i] = branches[i];
        }
        temp[branchSize] = Branch(branchId, branchName);
        delete[] branches;
        branches = temp;
    }

    branchSize++;

    cout << "Branch " << branchId << " has been added." << endl;
}

//This function deletes branch from branch array
void BankingSystem::deleteBranch(const int branchId) {
    if (branchSize == 0) {
        cout << "Branch " << branchId << " does not exist." << endl;
        return;
    }
    for (int i = 0; i < branchSize; i++) {
        if (branches[i].getBranchId() == branchId) {

            //while deleting branch, this part deletes accounts belonging this branch
            //*****************************************
            int *accountsOfBranch = NULL;
            int accountsOfBranchSize = 0;
            for (int h = 0; h < accountSize; h++) {
                if (accounts[h].getBranch().getBranchId() == branchId) {
                    if (accountsOfBranchSize == 0) {
                        accountsOfBranch = new int[1];
                        accountsOfBranch[0] = accounts[h].getAccountID();
                    } else {
                        int *temparr = new int[accountsOfBranchSize + 1];
                        for (int x = 0; x < accountsOfBranchSize; x++) {
                            temparr[x] = accountsOfBranch[x];
                        }
                        temparr[accountsOfBranchSize] = accounts[h].getAccountID();
                        delete[] accountsOfBranch;
                        accountsOfBranch = temparr;
                    }
                    accountsOfBranchSize++;
                }
            }

            for (int k = 0; k < accountsOfBranchSize; k++) {
                deleteAccountHelper(accountsOfBranch[k], false);
            }
            delete[] accountsOfBranch;
            //*****************************************

            //deleting branch
            Branch *temp = new Branch[branchSize - 1];
            for (int j = 0; j < i; j++) {
                temp[j] = branches[j];
            }
            for (int j = i; j < branchSize - 1; j++) {
                temp[j] = branches[j + 1];
            }
            delete[] branches;
            branches = temp;
            branchSize--;

            cout << "Branch " << branchId << " has been deleted." << endl;
            return;
        }
    }

    cout << "Branch " << branchId << " does not exist." << endl;
}

//This function adds customer to customer array
void BankingSystem::addCustomer(const int customerId, const string customerName) {
    for (int i = 0; i < customerSize; i++) {
        if (customers[i].getCustomerId() == customerId) {
            cout << "Customer " << customerId << " already exists." << endl;
            return;
        }
    }

    if (customerSize == 0) {
        customers = new Customer[1];
        customers[0] = Customer(customerId, customerName);
    } else {
        Customer *temp = new Customer[customerSize + 1];
        for (int i = 0; i < customerSize; i++) {
            temp[i] = customers[i];
        }
        temp[customerSize] = Customer(customerId, customerName);
        delete[] customers;
        customers = temp;
    }

    customerSize++;
    cout << "Customer " << customerId << " has been added." << endl;
}


//This function deletes customer from customer array
void BankingSystem::deleteCustomer(const int customerId) {
    if (customerSize == 0) {
        cout << "Customer " << customerId << " does not exist." << endl;
        return;
    }
    for (int i = 0; i < customerSize; i++) {
        if (customers[i].getCustomerId() == customerId) {

            //while deleting customer, accounts of this customer should be deleted
            //*****************************************
            int *accountsOfCustomer = NULL;
            int accountsOfCustomerSize = 0;
            for (int h = 0; h < accountSize; h++) {
                if (accounts[h].getCustomer().getCustomerId() == customerId) {
                    if (accountsOfCustomerSize == 0) {
                        accountsOfCustomer = new int[1];
                        accountsOfCustomer[0] = accounts[h].getAccountID();
                    } else {
                        int *temparr = new int[accountsOfCustomerSize + 1];
                        for (int x = 0; x < accountsOfCustomerSize; x++) {
                            temparr[x] = accountsOfCustomer[x];
                        }
                        temparr[accountsOfCustomerSize] = accounts[h].getAccountID();
                        delete[] accountsOfCustomer;
                        accountsOfCustomer = temparr;
                    }
                    accountsOfCustomerSize++;
                }
            }

            for (int k = 0; k < accountsOfCustomerSize; k++) {
                deleteAccountHelper(accountsOfCustomer[k], false);
            }
            delete[] accountsOfCustomer;
            //*****************************************


            //deleting customer
            Customer *temp = new Customer[customerSize - 1];
            for (int j = 0; j < i; j++) {
                temp[j] = customers[j];
            }
            for (int j = i; j < customerSize - 1; j++) {
                temp[j] = customers[j + 1];
            }
            delete[] customers;
            customers = temp;
            customerSize--;
            cout << "Customer " << customerId << " has been deleted." << endl;
            return;
        }
    }

    cout << "Customer " << customerId << " does not exist." << endl;
}

//This function adds account to account array
int BankingSystem::addAccount(const int branchId, const int customerId, const double amount) {

    //If there is no branch or customer with given ids, show an error message and return -1.
    //*****************************************
    int count1 = 0;
    for (int i = 0; i < branchSize; i++) {
        if (branchId != branches[i].getBranchId()) {
            count1++;
        }
    }
    if (count1 == branchSize) {
        cout << "Branch " << branchId << " does not exist." << endl;
        return -1;
    }

    int count2 = 0;
    for (int i = 0; i < customerSize; i++) {
        if (customerId != customers[i].getCustomerId()) {
            count2++;
        }
    }
    if (count2 == customerSize) {
        cout << "Customer " << customerId << " does not exist." << endl;
        return -1;
    }
    //*****************************************


    //adding account
    if (accountSize == 0) {
        accounts = new Account[1];
        accounts[0] = Account(accountId, findCustomerFromId(customerId), findBranchFromId(branchId), amount);
    } else {
        Account *temp = new Account[accountSize + 1];
        for (int i = 0; i < accountSize; i++) {
            temp[i] = accounts[i];
        }
        temp[accountSize] = Account(accountId, findCustomerFromId(customerId), findBranchFromId(branchId), amount);
        delete[] accounts;
        accounts = temp;
    }

    cout << "Account " << accountId << " added for customer " << customerId << " at branch " << branchId << "." << endl;

    accountSize++;
    accountId++;

    return accountId - 1;
}

//deleting account
void BankingSystem::deleteAccount(const int accountId) {
    deleteAccountHelper(accountId, true);
}

//This function deletes account. I used a helper because while deleting a customer or branch, the program should not show couts.
void BankingSystem::deleteAccountHelper(const int accountId, const bool isPrint) {
    if (accountSize == 0) {
        if (isPrint) {
            cout << "Account " << accountId << " does not exist." << endl;
        }
        return;
    }

    for (int i = 0; i < accountSize; i++) {
        if (accounts[i].getAccountID() == accountId) {
            Account *temp = new Account[accountSize - 1];
            for (int j = 0; j < i; j++) {
                temp[j] = accounts[j];
            }
            for (int j = i; j < accountSize - 1; j++) {
                temp[j] = accounts[j + 1];
            }
            delete[] accounts;
            accounts = temp;
            accountSize--;
            if (isPrint) {
                cout << "Account " << accountId << " has been deleted." << endl;
            }
            return;
        }
    }
    if (isPrint) {
        cout << "Account " << accountId << " does not exist." << endl;
    }
}


//This function shows all accounts
void BankingSystem::showAllAccounts() {

    if (accountSize == 0) {
        cout << "There is no account." << endl;
        return;
    }

    cout << left << setw(20) << "Account ID" << setw(20) << "Branch ID" << setw(20) << "Branch Name"
         << setw(20) << "Customer ID" << setw(20) << "Customer Name" << setw(20) << "Balance";
    for (int i = 0; i < accountSize; i++) {
        cout << left << setw(20) << accounts[i].getAccountID() << setw(20) << accounts[i].getBranch().getBranchId()
             << setw(20) << accounts[i].getBranch().getBranchName() << setw(20)
             << accounts[i].getCustomer().getCustomerId()
             << setw(20) << accounts[i].getCustomer().getCustomerName() << setw(20) << accounts[i].getAmount();
    }
}

//This function shows branch and accounts belonging to this branch
void BankingSystem::showBranch(const int branchId) {
    for (int i = 0; i < branchSize; i++) {
        if (branchId == branches[i].getBranchId()) {

            int *accountsOfBranch = NULL;
            int accountsOfBranchSize = 0;
            for (int h = 0; h < accountSize; h++) {
                if (accounts[h].getBranch().getBranchId() == branchId) {
                    if (accountsOfBranchSize == 0) {
                        accountsOfBranch = new int[1];
                        accountsOfBranch[0] = accounts[h].getAccountID();
                    } else {
                        int *temparr = new int[accountsOfBranchSize + 1];
                        for (int x = 0; x < accountsOfBranchSize; x++) {
                            temparr[x] = accountsOfBranch[x];
                        }
                        temparr[accountsOfBranchSize] = accounts[h].getAccountID();
                        delete[] accountsOfBranch;
                        accountsOfBranch = temparr;
                    }
                    accountsOfBranchSize++;
                }
            }


            cout << "Branch ID: " << branchId << "   Branch name: " << branches[i].getBranchName()
                 << "    Number of accounts: " << accountsOfBranchSize << endl;
            if (accountsOfBranchSize == 0) {
                return;
            }
            cout << "Accounts at this branch:" << endl;
            cout << left << setw(20) << "Account ID" << setw(20) << "Customer ID" << setw(20) << "Customer Name"
                 << setw(20) << "Balance";

            cout << endl;
            for (int j = 0; j < accountsOfBranchSize; j++) {
                cout << left << setw(20) << findAccountFromId(accountsOfBranch[j]).getAccountID() << setw(20) <<
                     findAccountFromId(accountsOfBranch[j]).getCustomer().getCustomerId() <<
                     setw(20) << findAccountFromId(accountsOfBranch[j]).getCustomer().getCustomerName() <<
                     setw(20) << findAccountFromId(accountsOfBranch[j]).getAmount() << endl;
            }

            delete[] accountsOfBranch;
            return;
        }
    }
    cout << "Branch " << branchId << " does not exist." << endl;
}

//This function shows customer and accounts of this customer.
void BankingSystem::showCustomer(const int customerId) {
    for (int i = 0; i < customerSize; i++) {

        if (customers[i].getCustomerId() == customerId) {
            int *accountsOfCustomer = NULL;
            int accountsOfCustomerSize = 0;
            for (int h = 0; h < accountSize; h++) {
                if (accounts[h].getCustomer().getCustomerId() == customerId) {
                    if (accountsOfCustomerSize == 0) {
                        accountsOfCustomer = new int[1];
                        accountsOfCustomer[0] = accounts[h].getAccountID();
                    } else {
                        int *temparr = new int[accountsOfCustomerSize + 1];
                        for (int x = 0; x < accountsOfCustomerSize; x++) {
                            temparr[x] = accountsOfCustomer[x];
                        }
                        temparr[accountsOfCustomerSize] = accounts[h].getAccountID();
                        delete[] accountsOfCustomer;
                        accountsOfCustomer = temparr;
                    }
                    accountsOfCustomerSize++;
                }
            }

            cout << "Customer ID: " << customerId << "   Customer name: " << customers[i].getCustomerName()
                 << "    Number of accounts: " << accountsOfCustomerSize << endl;

            if (accountsOfCustomerSize == 0) {
                return;
            }
            cout << "Accounts of this customer:" << endl;
            cout << left << setw(20) << "Account ID" << setw(20) << "Branch ID" << setw(20) << "Branch Name"
                 << setw(20) << "Balance";

            cout << endl;
            for (int j = 0; j < accountsOfCustomerSize; j++) {
                cout << left << setw(20) << findAccountFromId(accountsOfCustomer[j]).getAccountID() << setw(20) <<
                     findAccountFromId(accountsOfCustomer[j]).getBranch().getBranchId() <<
                     setw(20) << findAccountFromId(accountsOfCustomer[j]).getBranch().getBranchName() <<
                     setw(20) << findAccountFromId(accountsOfCustomer[j]).getAmount() << endl;
            }

            delete[] accountsOfCustomer;
            return;
        }
    }
    cout << "Customer " << customerId << " does not exist." << endl;
}


//These functions finds customer, branch or account from given id.
Customer BankingSystem::findCustomerFromId(const int customerId) {
    for (int i = 0; i < customerSize; i++) {
        if (customerId == customers[i].getCustomerId()) {
            return customers[i];
        }
    }
    return Customer();
}

Branch BankingSystem::findBranchFromId(const int branchId) {
    for (int i = 0; i < branchSize; i++) {
        if (branchId == branches[i].getBranchId()) {
            return branches[i];
        }
    }
    return Branch();
}

Account BankingSystem::findAccountFromId(const int accountId) {
    for (int i = 0; i < accountSize; i++) {
        if (accountId == accounts[i].getAccountID()) {
            return accounts[i];
        }
    }
    return Account();
}