// FILENAME:   EnglishWeight.h
// PROGRAMMER: Bogdan Tanasa
// DATE:       Aug 2nd, 2025
// COMPILER:   g++
// REQUIRED:   EnglishWeight.h, EnglishWeight.cpp
// PURPOSE:    a HEADER FILE - it tells the computer what our EnglishWeight class looks like.

// #ifndef ENGLISHWEIGHT_H  // prevents the file from being included twice
// #define ENGLISHWEIGHT_H  // (a safety lock)

#pragma once 
#include <iostream> 
using namespace std;


class EnglishWeight
{
private: 
    int pounds;  
    int ounces; 

public:   
    
    // CONSTRUCTORS - to create new weight objects
    EnglishWeight();                    // default 
    EnglishWeight(int p);               // a weight with p pounds, 0 ounces  
    EnglishWeight(int p, int o);        // a weight with p pounds, o ounces       

    // GETTER FUNCTIONS - to see the private data
    int getPounds();    
    int getOunces();    

    // OPERATOR FUNCTIONS - to do math with + - * / symbols
    EnglishWeight operator+(EnglishWeight other);  // Addition: weight1 + weight2
    EnglishWeight operator-(EnglishWeight other);  // Subtraction: weight1 - weight2
    EnglishWeight operator*(double num);           // Multiplication: weight * number
    EnglishWeight operator/(double num);           // Division: weight / number
    double operator/(EnglishWeight other);         // Division: weight1 / weight2 (returns ratio)

    // "/" is the operator name : when we write weight1 / weight2, C++ calls this function
    // (EnglishWeight other) : the parameter -- EnglishWeight is the type of the parameter
    // other = the name of the parameter (it could be called differently)

    // FRIEND FUNCTIONS - special functions that can see what  private data
    
    friend EnglishWeight operator*(double num, EnglishWeight weight);  // number * weight
    friend ostream& operator<<(ostream& out, EnglishWeight weight);    // cout << weight
    friend istream& operator>>(istream& in, EnglishWeight& weight);    // cin >> weight

    // ostream& operator<<(ostream& out, EnglishWeight weight)
    // ostream& out = "to send the data" (could be cout, file, etc.)
    // EnglishWeight weight = the weight we want to print
    // ostream& = "return the same stream so we can chain more output"
    
    // istream& operator>>(istream& in, EnglishWeight& weight)
    // istream& in = "to get data from" (could be cin, file, etc.)
    // EnglishWeight& weight = the weight we want to fill with data
    // istream& = "return the same stream so we can chain more input"
};
