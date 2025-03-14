#ifndef _bank_h
#define _bank_h

#include <iostream>
#include <string>

// Account management
void createAccount();                     // Add a new account
void showAccount(int accountNumber);      // View account details by account number
void updateAccount(int accountNumber);    // Update account details
void deleteAccount(int accountNumber);    // Delete account by number
void depositMoney(int accountNumber, double amount);   // Deposit to an account
void withdrawMoney(int accountNumber, double amount); // Withdraw from an account
void listAllAccounts();                   // List all existing accounts

#endif // _bank_h