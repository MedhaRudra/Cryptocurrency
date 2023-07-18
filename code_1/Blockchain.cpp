#include<iostream>
#include <sstream>

#include "Transaction.hpp"
#include "Block.hpp"
#include "Blockchain.hpp"
#include<vector>

using namespace std;

Blockchain::Blockchain() {
    Transaction genesis("BFC","BFC",0);
    pending.push_back(genesis);

    Block gBlock(pending, time(nullptr), "In the beginning..");
    chain.push_back(gBlock);

    Transaction freeMoney("BFC","make money by mining",0);
    pending.push_back(freeMoney);

    difficulty = 4;
    miningReward = 10;
}

Block Blockchain::getLatestBlock() { 
    return chain.back();
}

void Blockchain::addTransaction(string src, string dst, int coins) {
    // TODO
    Transaction transaction(src, dst, coins);
    pending.push_back(transaction);
}

bool Blockchain::isChainValid() { 
    // TODO
    for (size_t i = 1; i < chain.size(); i++) {
        Block currentBlock = chain[i];
        Block previousBlock = chain[i-1];

        if (currentBlock.calculateHash() != currentBlock.hash) {
            return false;
        }

        if (currentBlock.previousHash != previousBlock.hash) {
            return false;
        }
    }
    return true;
}

bool Blockchain::minePendingTransactions(string minerAddress) {
    // TODO
    if (pending.size() == 0) {
        return false;
    }

    Block block(pending, time(nullptr), getLatestBlock().hash);
    block.mineBlock(difficulty);

    Transaction rewardTransaction("BFC", minerAddress, miningReward);
    pending.clear();
    pending.push_back(rewardTransaction);

    chain.push_back(block);
    return true;
}

int Blockchain::getBalanceOfAddress(string address) {
    // TODO
    int balance = 0;

    for (const auto& block : chain) {
        for (const auto& transaction : block.transactions) {
            if (transaction.getSender() == address) {
                balance -= transaction.getAmount();
            }

            if (transaction.getReceiver() == address) {
                balance += transaction.getAmount();
            }
        }
    }

    return balance;
}

void Blockchain::prettyPrint() {
    // TODO
    for(auto &block : chain) {
        cout << block.toString();
    }
}