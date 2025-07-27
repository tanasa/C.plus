// FILENAME: hello_driver.cpp
// PROGRAMMER: Bogdan Tanasa
// DATE: July 27th, 2025
// COMPILER: g++
// REQUIRED: hello_interface.h, hello_interface.cpp
// PURPOSE: Main driver program that uses functions to get user input and display greeting

#include <iostream>
#include <string>
#include "hello_interface.h"
using namespace std;

int main()
{
    string firstName;
    
    // To get user's first name
    firstName = readUserName();
    
    // To display the greeting
    showGreeting(firstName);
}   