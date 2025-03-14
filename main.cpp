#include <iostream>
#include <string>
#include "account.h"
#include "bank.h"


void showMenu(){
    std::cout<<"\n=== Bank Management System ===\n";
    std::cout<<"1. Create Account\n";
    std::cout<<"2. View Account Details\n";
    std::cout<<"3. Desposit Money\n";
    std::cout<<"4. Withdraw Money\n";
    std::cout<<"5. Update Account Info\n";
    std::cout<<"6. Delete Account\n";
    std::cout<<"7. List All Accounts\n";
    std::cout<<"8. Exit\n";
    std::cout<<"Enter your choice: ";
}

int main()
{
    
    int choice;
    int accountNumber;
    std::string name;
    do{
        showMenu();
        std::cin>>choice;
        std::cin.ignore();
        switch(choice){
            case 1:
                createAccount();
                break;
            case 2:
                std::cout<<"Provide Account Number: ";
                std::cin>>accountNumber;
                showAccount(accountNumber);
                break;
            case 3:
                std::cout<<"Provide Account Number: ";
                std::cin>>accountNumber;
                std::cout<<"\nProvide amount to deposit: ";
                double amount;
                std::cin>>amount;
                depositMoney(accountNumber, amount);
                break;
            case 4:
                std::cout<<"Provide Account Number: ";
                std::cin>>accountNumber;
                std::cout<<"\nProvide amount to withdraw: ";
                std::cin>>amount;
                withdrawMoney(accountNumber, amount);
                break;
            case 5:
                std::cout<<"Provide Account Number: ";
                std::cin>>accountNumber;
                updateAccount(accountNumber);
                break;
            case 6:
                std::cout<<"Provide Account Number: ";
                std::cin>>accountNumber;
                deleteAccount(accountNumber);
                break;
            case 7:
                listAllAccounts();
                break;
            case 8:
                std::cout<<"Thank you for using our service\n";
                break;
            default:
                std::cout<<"Invalid choice\n";
        }
    }while(choice !=8);



    return 0;
}