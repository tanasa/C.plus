// FILENAME:   Bogdan_Tanasa_M1_A1.cpp
// PROGRAMMER: Bogdan Tanasa
// DATE:       07/22/2025
// COMPILER:   g++ (Ubuntu) and VS Code
// REQUIRED:   iostream
// PURPOSE:
//    Prompts the user for their first name and displays a greeting using that name.

#include <iostream>   
#include <string>  
using namespace std;  

int main()
{
    string firstName;

    cout << "Enter your first name: ";
    cin >> firstName;

    cout << "Hello, " << firstName << "!" << endl;

    return 0;
}