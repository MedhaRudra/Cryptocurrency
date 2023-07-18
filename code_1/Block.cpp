#include<iostream>
#include <sstream>


#include "Transaction.hpp"
#include "Block.hpp"
#include "sha256.hpp"

using namespace std;

Block::Block(vector<Transaction> _transactions, time_t _timestamp, string _previousHash) {
    nonce = -1;
    transactions = _transactions;
    previousHash = _previousHash;
    timestamp = _timestamp;
    hash = calculateHash();
}

void Block::setPreviousHash(string _previousHash) {
    // TODO
    previousHash = _previousHash;
}

string Block::calculateHash() {
    // TODO
    stringstream ss;
    ss << nonce << timestamp << previousHash;

    for(auto &transaction : transactions) {
        ss << transaction.toString();
    }

    string data = ss.str();
    return sha256(data);  
}

void Block::mineBlock(unsigned int difficulty) {
    // TODO
    string target(difficulty, '0'); 
    while (hash.substr(0, difficulty) != target) {
        nonce++;
        hash = calculateHash();
    }
}

string Block::toString() {
    // TODO
    stringstream ss;
    ss << "\nBlock=================================="
       << "\nNonce: " << nonce
       << "\nPrevious Hash: " << previousHash
       << "\nHash: " << hash
       << "\nTransactions: ";
    
    for(auto &transaction : transactions) {
        ss << "\n\t" << transaction.toString();
    }

    ss << "\n========================================\n";
    return ss.str();
}