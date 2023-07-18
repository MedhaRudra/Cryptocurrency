#pragma once
#include<iostream>
using namespace std;

class Transaction {
private:
    string sender;
    string receiver;
    int amount;

public:
    Transaction(string _sender, string _receiver, int amount);

    string getSender() const;
    string getReceiver() const;
    int getAmount() const;

    string toString();
};