#include "bank.h"
#include "account.h"
#include <vector>
#include <iostream>
#include <fstream>

const std::string FILENAME = "accounts.txt"; // File to store accounts

std::vector<BankAccount> LoadAccounts()
{
    std::vector<BankAccount> accounts;
    std::ifstream file(FILENAME);
    if (file.is_open()) {
        int accNum;
        std::string name, email;
        double balance;
        while (file >> accNum) {
            file.ignore(); // Ignore whitespace/newline
            std::getline(file, name);
            std::getline(file, email);
            file >> balance;
            file.ignore(); // Ignore remaining whitespace/newline

            BankAccount acc;
            acc.LoadData(accNum, name, email, balance); // Function to set private fields
            accounts.push_back(acc);
        }
        file.close();
    }
    return accounts;
}


// --- Helper Function: Save all accounts to file ---
void saveAccounts(const std::vector<BankAccount>& accounts)
{

    std::ofstream file(FILENAME);
    
    for (const auto& account : accounts)
    {
        file << account.getAccountNumber() << "\n"
        << account.getName() << "\n"
        << account.getEmail() << "\n"
        << account.getBalance() << "\n";
    }
    file.close();
    
}

// ---1. Create Account ---
void createAccount()
{
    BankAccount account;
    account.CreateAccount();
    std::vector<BankAccount> accounts = LoadAccounts();
    accounts.push_back(account);
    saveAccounts(accounts);
    std::cout << "Account created successfully\n";
}
// ---2. List All accounts ---
void listAllAccounts()
{
    std::vector<BankAccount> accounts = LoadAccounts();
    if(accounts.size() == 0)
    {
        std::cout << "No accounts found\n";
        return;
    }
    std::cout << "List of all accounts:\n";
    for (auto& account : accounts)
    {
        account.showAccount();
        std::cout << "---------------------------\n";
    }
}

void depositMoney(int accountNumber, double amount)
{
    std::vector<BankAccount> accounts = LoadAccounts();
    for (auto& account : accounts)
    {
        if(account.getAccountNumber() == accountNumber)
        {
            account.Deposit(amount);
            saveAccounts(accounts);
            return;
        }
    }
    std::cout << "Account not found\n";
}

void withdrawMoney(int accountNumber, double amount)
{
    std::vector<BankAccount> accounts = LoadAccounts();
    for (auto& account : accounts)
    {
        if(account.getAccountNumber() == accountNumber)
        {
            account.Withdraw(amount);
            saveAccounts(accounts);
            return;
        }
    }
    std::cout << "Account not found\n";
}
//----Update Account Info---
void updateAccount(int accountNumber)
{
    std::vector<BankAccount> accounts = LoadAccounts();
    for (auto& account : accounts)
    {
        if(account.getAccountNumber() == accountNumber)
        {
            std::string name, email;
            std::cout << "Enter new name: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            std::cout << "Enter new email: ";
            std::getline(std::cin, email);
            account.updateAccount(name, email);
            saveAccounts(accounts);
            std::cout << "Account updated successfully\n";
            return;
        }
    }
    std::cout << "Account not found\n";
}

// ---4. Show Account Details ---
void showAccount(int accountNumber)
{
    std::vector<BankAccount> accounts = LoadAccounts();
    for (auto& account : accounts)
    {
        if(account.getAccountNumber() == accountNumber)
        {
            account.showAccount();
            return;
        }
    }
    std::cout << "Account not found\n";
}
// ---6. Delete Account ---
void deleteAccount(int accountNumber)
{
    std::vector<BankAccount> accounts = LoadAccounts();
    for (auto it = accounts.begin(); it != accounts.end(); ++it)
    {
        if (it->getAccountNumber() == accountNumber)
        {
            accounts.erase(it);
            saveAccounts(accounts);
            std::cout << "Account deleted successfully\n";
            return;
        }
    }
    std::cout << "Account not found\n";
}