// FILENAME:   EnglishWeight_Driver.cpp
// PROGRAMMER: Bogdan Tanasa
// DATE:       Aug 2nd, 2025
// COMPILER:   g++
// REQUIRED:   EnglishWeight.h, EnglishWeight.cpp, EW_Driver.cpp
// PURPOSE:
//    Test program for EnglishWeight class. Allows user to enter two separate
//    weights (both must include pounds and ounces) and a number. Outputs the
//    results of five operations: addition, subtraction, weight*number, 
//    number*weight, and weight/number for both weights.

#include <iostream>      
#include "EnglishWeight.h"  // our custom EnglishWeight class
using namespace std;

int main()
{
    
    cout << "============================================================" << endl;
    cout << "                ENGLISH WEIGHT CALCULATOR" << endl;
    cout << "This program performs arithmetic operations on English weights." << endl;
    cout << "============================================================" << endl << endl;
    
    EnglishWeight weight1;  // First weight (pounds and ounces)
    EnglishWeight weight2;  // Second weight (pounds and ounces)
    double number;          // multiplication / deletion
    
    // the first weight from user (must include both pounds and ounces)
    cout << "FIRST WEIGHT:" << endl;
    weight1.readWeight(cin);  
    cout << "You entered: ";
    weight1.printWeight(cout);
    cout << endl << endl;
    
    // the second weight from user (must include both pounds and ounces)
    cout << "SECOND WEIGHT:" << endl;
    weight2.readWeight(cin);  
    cout << "You entered: ";
    weight2.printWeight(cout);
    cout << endl << endl;
    
    // a number from user for multiplication and division operations
    cout << "NUMBER FOR OPERATIONS:" << endl;
    cout << "Enter a number: ";
    cin >> number;
    cout << "You entered: " << number << endl << endl;
    
    // Display all input data for confirmation
    cout << "First Weight:  ";
    weight1.printWeight(cout);
    cout << endl;
    cout << "Second Weight: ";
    weight2.printWeight(cout);
    cout << endl;
    cout << "Number:        " << number << endl;
    
    // Perform and display all seven operations
    cout << "============================================================" << endl;
    cout << "                    RESULTS"                                  << endl;
    cout << "============================================================" << endl;
    
    
    // OPERATION 1: EnglishWeight1 + EnglishWeight2
    cout << "1. ADDITION:" << endl;
    EnglishWeight sum = weight1 + weight2;
    weight1.printWeight(cout);
    cout << " + ";
    weight2.printWeight(cout);
    cout << " = ";
    sum.printWeight(cout);
    cout << endl << endl;
    
    // OPERATION 2: EnglishWeight1 - EnglishWeight2  
    cout << "2. SUBTRACTION:" << endl;
    EnglishWeight difference = weight1 - weight2;
    weight1.printWeight(cout);
    cout << " - ";
    weight2.printWeight(cout);
    cout << " = ";
    difference.printWeight(cout);
    cout << endl << endl;
    
    // OPERATION 3: EnglishWeight1 / EnglishWeight2 (ratio)
    cout << "3. DIVISION (Weight ÷ Weight - Ratio):" << endl;
    double ratio = weight1 / weight2;
    weight1.printWeight(cout);
    cout << " ÷ ";
    weight2.printWeight(cout);
    cout << " = " << ratio << " (ratio)" << endl;
    cout << " (Weight1 is " << ratio << " times bigger than Weight2)" << endl << endl;
    
    // OPERATION 4: EnglishWeight1 * number
    cout << "4. MULTIPLICATION (Weight × Number):" << endl;
    EnglishWeight product1 = weight1 * number;
    weight1.printWeight(cout);
    cout << " × " << number << " = ";
    product1.printWeight(cout);
    cout << endl << endl;
    
    // OPERATION 5: number * EnglishWeight1  
    cout << "5. MULTIPLICATION (Number × Weight):" << endl;
    EnglishWeight product2 = weight1.multiplyByNumber(number);
    cout << number << " × ";
    weight1.printWeight(cout);
    cout << " = ";
    product2.printWeight(cout);
    cout << endl;
    cout << "It should be same as operation 4 above)" << endl << endl;
    
    // OPERATION 6: EnglishWeight1 / number
    cout << "6. DIVISION (First Weight ÷ Number):" << endl;
    EnglishWeight q1 = weight1 / number;
    weight1.printWeight(cout);
    cout << " ÷ " << number << " = ";
    q1.printWeight(cout);
    cout << endl << endl;
    
    // OPERATION 7: EnglishWeight2 / number  
    cout << "7. DIVISION (Second Weight ÷ Number):" << endl;
    EnglishWeight q2 = weight2 / number;
    weight2.printWeight(cout);
    cout << " ÷ " << number << " = ";
    q2.printWeight(cout);
    cout << endl << endl;
    
    // Display completion message
    cout << "============================================================" << endl;
    cout << "                 ALL OPERATIONS COMPLETED" << endl;
    cout << "============================================================" << endl;
     
    // To exit the program
    cout << endl << "Press Enter to exit the program...";
    cin.ignore();  
    cin.get();     // to press Enter
    
    return 0;      
}