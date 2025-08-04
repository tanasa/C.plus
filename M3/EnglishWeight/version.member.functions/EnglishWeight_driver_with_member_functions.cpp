// FILENAME:   EnglishWeight_driver_with_member_functions.cpp
// PROGRAMMER: Bogdan Tanasa
// DATE:       Aug 2nd, 2025
// COMPILER:   g++
// REQUIRED:   EnglishWeight_version_with_member_functions.h, EnglishWeight_version_with_member_functions.cpp
// PURPOSE:
//    Test program for EnglishWeight class using MEMBER FUNCTIONS only.
//    Allows user to enter two separate weights (both must include pounds and ounces) 
//    and a number. Outputs the results of seven operations using member functions.
//    NO FRIEND FUNCTIONS - uses only member functions for input/output.

#include <iostream>      
#include <iomanip>       
#include "EnglishWeight_version_with_member_functions.h"  // EnglishWeight class
using namespace std;

int main()
{

    cout << "============================================================" << endl;
    cout << "                ENGLISH WEIGHT CALCULATOR" << endl;
    cout << "============================================================" << endl;
    cout << "This program performs arithmetic operations on English weights." << endl;
    cout << "============================================================" << endl << endl;
    
    EnglishWeight weight1;  
    EnglishWeight weight2;  
    double number;          
    
    // Get first weight from user (must include both pounds and ounces)
    cout << "FIRST WEIGHT:" << endl;
    weight1.readWeight(cin);  // Use member function instead of cin >> weight1
    cout << "You entered: ";
    weight1.printWeight(cout);  // Use member function instead of cout << weight1
    cout << endl << endl;
    
    // Get second weight from user (must include both pounds and ounces)
    cout << "SECOND WEIGHT:" << endl;
    weight2.readWeight(cin);  // Use member function instead of cin >> weight2
    cout << "You entered: ";
    weight2.printWeight(cout);  // Use member function instead of cout << weight2
    cout << endl << endl;
    
    // Get number from user for multiplication and division operations
    cout << "NUMBER FOR OPERATIONS:" << endl;
    cout << "Enter a number: ";
    cin >> number;
    cout << "You entered: " << number << endl << endl;
   
    cout << "============================================================" << endl << endl;
    cout << "                    OPERATION RESULTS" << endl;
    cout << "============================================================" << endl;
    
    
    // OPERATION 1: EnglishWeight1 + EnglishWeight2
    cout << "1. ADDITION:" << endl;
    EnglishWeight sum = weight1 + weight2;
    weight1.printWeight(cout);  // Use member function
    cout << " + ";
    weight2.printWeight(cout);  // Use member function
    cout << " = ";
    sum.printWeight(cout);      // Use member function
    cout << endl << endl;
    
    // OPERATION 2: EnglishWeight1 - EnglishWeight2  
    cout << "2. SUBTRACTION:" << endl;
    EnglishWeight difference = weight1 - weight2;
    weight1.printWeight(cout);     // Use member function
    cout << " - ";
    weight2.printWeight(cout);     // Use member function
    cout << " = ";
    difference.printWeight(cout);  // Use member function
    cout << endl << endl;
    
    // OPERATION 3: EnglishWeight1 / EnglishWeight2 (ratio)
    cout << "3. DIVISION (Weight ÷ Weight - Ratio):" << endl;
    double ratio = weight1 / weight2;
    weight1.printWeight(cout);     // Use member function
    cout << " ÷ ";
    weight2.printWeight(cout);     // Use member function
    cout << " = " << ratio << " (ratio)" << endl;
    cout << "   (weight1 is " << ratio << " times larger than weight2)" << endl << endl;
    
    // OPERATION 4: EnglishWeight1 * number
    cout << "4. MULTIPLICATION (Weight × Number):" << endl;
    EnglishWeight product1 = weight1 * number;
    weight1.printWeight(cout);    // Use member function
    cout << " × " << number << " = ";
    product1.printWeight(cout);   // Use member function
    cout << endl << endl;
    
    // OPERATION 5: number * EnglishWeight1  
    cout << "5. MULTIPLICATION (Number × Weight):" << endl;
    EnglishWeight product2 = weight1.multiplyByNumber(number);  // Use member function
    cout << "   " << number << " × ";
    weight1.printWeight(cout);   // Use member function
    cout << " = ";
    product2.printWeight(cout);  // Use member function
    cout << endl;
    cout << "   (it should be same as operation 4 above)" << endl << endl;
    
    // OPERATION 6: EnglishWeight1 / number
    cout << "6. DIVISION (First Weight ÷ Number):" << endl;
    EnglishWeight quotient1 = weight1 / number;
    weight1.printWeight(cout);  // Use member function
    cout << " ÷ " << number << " = ";
    quotient1.printWeight(cout);  // Use member function
    cout << endl << endl;
    
    // OPERATION 7: EnglishWeight2 / number  
    cout << "7. DIVISION (Second Weight ÷ Number):" << endl;
    EnglishWeight quotient2 = weight2 / number;
    weight2.printWeight(cout);  // Use member function
    cout << " ÷ " << number << " = ";
    quotient2.printWeight(cout);  // Use member function
    cout << endl << endl;
    
    // Display completion message
    cout << "============================================================" << endl;
    cout << "                 ALL OPERATIONS COMPLETED"                    << endl;
    cout << "============================================================" << endl;

    cout << endl << "Press Enter to exit the program...";
    cin.ignore();  
    cin.get();     
    
    return 0; 
} 