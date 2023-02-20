# Cryptocurrency BuffCoin Project 

## Project Description:
This project demonstrates a simple implementation of a cryptocurrency using C++. The project consists of a command-line interface that allows users to send and receive `BuffCoins`, check their current balance, check validity of a blockchain and mine new blocks.

## Project Components:

- A blockchain data structure to store the transaction history of the cryptocurrency.
- A mining algorithm to add new blocks to the blockchain and reward miners with new cryptocurrency.
- A proof-of-work algorithm to ensure that mining new blocks requires computational effort.

## Project Workflow:

- Users can send BuffCoins to other users by specifying the recipient's detail and the amount of cryptocurrency to be sent.
- Transactions are verified by checking that the sender has enough cryptocurrency in their wallet to complete the transaction.
- Valid transactions are added to a transaction pool.
- Miners select transactions from the transaction pool and use a proof-of-work algorithm to create a new block in the blockchain.
- The miner is rewarded with a pre-defined amount of new cryptocurrency.
- The new block is added to the blockchain and the transaction pool is cleared.

## Project Requirements:

- C++ compiler
- SHA-256 based algorithm for hashing blocks
- Random number generator for proof-of-work algorithm

## Conclusion:
This project demonstrates a simple implementation of a cryptocurrency using C++. While the implementation is not suitable for use in a production environment, it provides a good starting point for understanding the basic concepts behind cryptocurrencies such as blockchains, wallets, transactions, and mining.



