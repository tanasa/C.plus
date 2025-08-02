#include <iostream>
using namespace std;

class Account {

//  Private members can ONLY be accessed by methods that belong to the SAME class
//  Private members CANNOT be accessed from outside the class (like in main())

// Who can access private data:
// yes : ✅ Methods inside the class (like deposit(), withdraw(), balance(), constructor)
// no :  ❌ Code outside the class (like in main() function)


private:
    int account_number;
    double account_balance;
    bool initialized;
    
public:

    // Constructor with default parameters. 
    // If no values are provided, account number defaults to 0 and balance to 0.0
    
    Account(int acct_num = 0, double acct_bal = 0.0) {

        // If account number is 0 (default), mark account as uninitialized
        // Otherwise, set the account number and balance, and mark as initialized

        if (acct_num == 0) {
            initialized = false;
        } else {
            account_number = acct_num;
            account_balance = acct_bal;
            initialized = true;
        }
    }

    void initialize(int acct_num, double acct_bal) {
        account_number = acct_num;
        account_balance = acct_bal;
        initialized = true;
    }

    void deposit(double amount) {
        if (initialized == false) {
            cout << "Error: Account not initialized!" << endl;
            return;
        }
        account_balance += amount;
    }
    
    void withdraw(double amount) {
        if (initialized == false) {
            cout << "Error: Account not initialized!" << endl;
            return;
        }
        account_balance -= amount;
    }
    
    double balance() {
        if (initialized == false) {
            cout << "Error: Account not initialized!" << endl;
            return 0.0;
        }
        return account_balance;
    }
    
    void display() {
        if (initialized == false) {
            cout << "Error: Account not initialized!" << endl;
            return;
        }
        cout << "Account " << account_number << ": $" << account_balance << endl;
    }

};

int main() {
    
    // Create an initialized account
    Account bob(3819, 1000.00);
    
    // Create an uninitialized account
    Account alex;
    
    cout << "=== Bob's Account ===" << endl;
    bob.display();
    
    bob.withdraw(100.00);
    cout << "After withdrawing $100.00: $" << bob.balance() << endl;
    
    bob.deposit(200.00);
    cout << "After depositing $200.00: $" << bob.balance() << endl;
 
    // Who can access the private data :
    // ✅ Methods inside the class (like deposit(), withdraw(), balance(), constructor)
    // ❌ Code outside the class (like in main() function)

    // In main() function:
    // bob.account_balance = 999999.99;  // ❌ COMPILER ERROR!
    // cout << bob.account_number;       // ❌ COMPILER ERROR!

    cout << "\n=== Alex's Account (uninitialized) ===" << endl;
    alex.deposit(50.00);  // This will show an error
    
    cout << "\n=== Initializing Alex's Account ===" << endl;
    alex.initialize(1234, 500.00);
    alex.display();
    alex.deposit(50.00);
    cout << "After depositing $50.00: $" << alex.balance() << endl;
    
    return 0;
}

 WHY we have the initialize() method by showing you the problem it solves:
THE PROBLEM: Two Different Ways to Create Objects

// Scenario 1: I know the account details RIGHT NOW
Account bob(1234, 1000.00);  // ✅ Ready to use immediately

// Scenario 2: I DON'T know the account details yet
Account alex;  // ❌ Can't use yet - no account number or balance!

WHY We Need initialize():
1. DELAYED SETUP
Sometimes you need to create an object BEFORE you have all the information:

Account accounts[100];  // Create 100 accounts, but don't know details yet

// Later, when user provides info:
cout << "Enter account number: ";
int acct_num;
cin >> acct_num;
cout << "Enter initial balance: ";
double balance;
cin >> balance;

// NOW we can set it up:
accounts[0].initialize(acct_num, balance);

Account accounts[100];  // Create 100 accounts, but don't know details yet

Answer: Sometimes you CAN'T!
Situation 1: Arrays
Account accounts[5];  // Creates 5 accounts, ALL uninitialized
// You can't do: Account accounts[5](1,2,3,4,5);  // ❌ Doesn't work!

// You need initialize() for each one:
accounts[0].initialize(1001, 100.00);
accounts[1].initialize(1002, 200.00);
// etc...

Situation 2: Dynamic Creation

Account* create_account_later() {
    Account* acc = new Account();  // Create now, set up later
    return acc;
}

// Somewhere else:
Account* my_account = create_account_later();
// Later when I have the info:
my_account->initialize(9999, 750.00);

WITHOUT initialize() - The Problems:

class BadAccount {
public:
    BadAccount(int num, double bal) { /* setup */ }
    // No default constructor, no initialize method
};

BadAccount accounts[10];  // ❌ ERROR! No default constructor

You'd be forced to always provide values:

BadAccount accounts[10] = {
    BadAccount(1, 100), BadAccount(2, 200), /* ... 8 more ... */
};
// This is clunky and inflexible!

SUMMARY:
initialize() exists because real programs often need to create objects BEFORE they have all the data to set them up. 
It provides flexibility for scenarios where the constructor alone isn't enough!

In this example, the constructor is this function:

Account(int acct_num = 0, double acct_bal = 0.0) {
    if (acct_num == 0) {
        initialized = false;
    } else {
        account_number = acct_num;
        account_balance = acct_bal;
        initialized = true;
    }
}

How to Identify a Constructor:

Same name as the class: Account (class name) = Account (function name)
No return type: Not even void - constructors never return anything
Inside the public section: So it can be called when creating objects

What Makes This Constructor Special:

It has default parameters:
Account(int acct_num = 0, double acct_bal = 0.0)

This means it can work in two ways:
Way 1: With parameters

Account bob(3819, 1000.00);
// acct_num = 3819, acct_bal = 1000.00
// Creates a fully initialized account

Way 2: Without parameters (uses defaults)

Account alex;
// acct_num = 0 (default), acct_bal = 0.0 (default)  
// Creates an uninitialized account

What the Constructor Does:

Checks if account number is 0
If 0: Sets initialized = false (account not ready)
If not 0: Sets up the account with real values and initialized = true

In Simple Terms:
The constructor is like a factory worker that gets called automatically every time you create an Account object. It looks at what information you gave it and decides whether to make a "complete account" or a "placeholder account that needs setup later."
The constructor in this code = the Account(...) function that runs automatically when you create Account objects.

A destructor is the opposite of a constructor - it's a special function that runs automatically when an object is destroyed or deleted.
What a Destructor Looks Like:

class Account {
public:
    ~Account() {  // Destructor - notice the ~ symbol
        // Cleanup code goes here
        cout << "Account is being destroyed!" << endl;
    }
};

class Account {
public:
    ~Account() {  // Destructor - notice the ~ symbol
        // Cleanup code goes here
        cout << "Account is being destroyed!" << endl;
    }
};


When Does It Run?
Automatic destruction:

{
    Account bob(1234, 500.00);  // Constructor runs
    // ... use bob ...
}  // bob goes out of scope - Destructor runs automatically!

Manual destruction:

Account* alex = new Account(5678, 1000.00);  // Constructor runs
delete alex;  // Destructor runs here

What Does It Do?
Common cleanup tasks:

Close files that were opened
Free memory that was allocated
Release network connections
Save data before object dies