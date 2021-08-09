/*
* Title: Banking System
* Author: Muhammet Abdullah Koç
* ID: 21802832
* Section: 1
* Assignment: 1
* Description: Header File for Customer class
*/

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>

using namespace std;


class Customer {
public:
    Customer();

    Customer(int customerId, string customerName);

    int getCustomerId();

    string getCustomerName();

    void setCustomerID(int id);

    void setCustomerName(string name);

private:
    int customerId;
    string customerName;
};


#endif //CUSTOMER_H
