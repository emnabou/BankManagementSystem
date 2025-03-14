#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>


class BankAccount
{
private:
    std::string name;
    double balance;
    int accountNumber;
    std::string email;

public:
    BankAccount();
     BankAccount(std::string accountName,double initialBalance,int accountNumber);
     void CreateAccount();
     void showAccount();
     void updateAccount(std::string& name,std::string& email);
    void LoadData(int accountNumber, std::string name, std::string& email, double balance);
    void Deposit(double amount);
    
    void Withdraw( double amount);
    double getBalance() const;
    int getAccountNumber() const;
    std::string getName() const;
    std::string getEmail() const;

};
#endif // _account_h