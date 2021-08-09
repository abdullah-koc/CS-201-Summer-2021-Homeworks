/*
* Title: Banking System
* Author: Muhammet Abdullah Koç
* ID: 21802832
* Section: 1
* Assignment: 1
* Description: Customer class that have properties Customer ID and Customer Name
*/

#include "Customer.h"

Customer::Customer() {
    customerId = -1;
    customerName = "";
}

Customer::Customer(int customerId, string customerName) {
    this->customerId = customerId;
    this->customerName = customerName;
}

int Customer::getCustomerId() {
    return customerId;
}

string Customer::getCustomerName() {
    return customerName;
}

void Customer::setCustomerID(int id) {
    customerId = id;
}

void Customer::setCustomerName(string name) {
    customerName = name;
}