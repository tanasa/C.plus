// FILENAME: hello_interface.cpp
// PROGRAMMER: Bogdan Tanasa
// DATE: July 27th, 2025
// COMPILER: g++
// REQUIRED: hello_interface.h
// PURPOSE: Implementation file containing functions defined in the header file

#include <iostream>
#include <string>
#include "hello_interface.h"
using namespace std;

// Function to read first name and return it
string readUserName()
{
    string firstName;
    cout << "Enter your first name: ";
    cin >> firstName;
    return firstName;
}

// Function to display greeting message 
// const = "read-only" - the function cannot modify the original string

void showGreeting(const string& firstName)
{
    cout << "Hello, " << firstName << "!" << endl;
}