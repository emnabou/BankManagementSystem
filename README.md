# BankManagementSystem

A simple Bank Management System implemented in C++, running in the console. This project demonstrates basic file handling, object-oriented programming (OOP) concepts, and modular design using classes.
🚀Features
✅ Create new bank accounts
✅ Deposit money into an account
✅ Withdraw money from an account
✅ Update account holder's name or email
✅ Delete an account
✅ View a single account's details
✅ List all accounts
✅ Data persistence using a text file (accounts.txt)

🛠️ Technologies Used
C++ (OOP principles: classes, encapsulation)
File Handling (for persistent storage)
Console Input/Output

📁 Project Structure
/BankManagementSystem
  ├── main.cpp          // Main program loop and user interface
  ├── account.h         // Account class header file
  ├── account.cpp       // Account class implementation
  ├── bank.h            // Bank system function declarations
  ├── bank.cpp          // Bank system function implementations
  ├── accounts.txt      // Data file storing all accounts (generated at runtime)
  └── README.md         // Project documentation (this file)

 How to Compile and Run
 1. Clone the repository
git clone https://github.com/yourusername/BankManagementSystem.git
cd BankManagementSystem
 
 3. Compile the project using g++
    g++ main.cpp account.cpp bank.cpp -o BankSystem
 5. Run the executable
    On Linux/macOS:
      ./BankSystem
    On Windows:
      BankSystem.exe
