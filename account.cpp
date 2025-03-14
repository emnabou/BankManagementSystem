#include "account.h"
#include <string>
#include <iostream>
BankAccount::BankAccount()
{
    name = " ";
    balance = 0.0;
    accountNumber = 0;
}	
BankAccount::BankAccount(std::string accountName,double initialBalance,int accountNumber)
{
    name = accountName;
    balance = initialBalance;
    accountNumber = accountNumber;
}
void BankAccount::CreateAccount()
{
    std::cout << "Enter the account Holder name: ";
    std::getline(std::cin,name);
    std::cout<<"Enter the email address: ";
    std::getline(std::cin,email);
    
    std::cout << "Enter the account number: ";
    std::cin >> accountNumber;
    std::cin.ignore();
    std::cout << "Enter the account initial balance: ";
    std::cin >> balance;
}
void BankAccount::showAccount()
{
    std::cout << "Account Name: " << name << std::endl;
    std::cout<<"Email: "<<email<<std::endl;
    std::cout << "Account Number: " << accountNumber << std::endl;
    std::cout << "Account Balance: " << balance << std::endl;
}
void BankAccount::updateAccount(std::string& newname,std::string& newemail)
{
    name = newname;
    email = newemail;
}

void BankAccount::Deposit(double amount)
{
    balance += amount;
    std::cout << "Deposited $" << amount << ", New Balance: $" << balance << "\n";
}

void BankAccount::Withdraw(double amount)
{
    if(balance < amount)
    {
        std::cout << "Insufficient funds" << std::endl;
    }
    else{
        balance -= amount;
        std::cout << "Withdrew $" << amount << ", New Balance: $" << balance << "\n";
    }

}
void BankAccount::LoadData(int accountNumber, std::string name, std::string& email, double balance)
{
    this->accountNumber = accountNumber;
    this->name = name;
    this->email = email;
    this->balance = balance;
}
int BankAccount::getAccountNumber() const
{
    return accountNumber;
}
std::string BankAccount::getName() const
{
    return name;
} 

double BankAccount::getBalance() const
{
    return balance;
}

std::string BankAccount::getEmail() const
{
    return email;
}