// FILENAME:   EnglishWeight_no_friend_functions.h
// PROGRAMMER: Bogdan Tanasa
// DATE:       Aug 2nd, 2025
// COMPILER:   g++
// REQUIRED:   EnglishWeight_version_no_iostream.h, EnglishWeight_version_no_iostream.cpp
// PURPOSE:
//    This is the HEADER FILE - it tells the computer what our EnglishWeight class looks like.
//    Think of it like a recipe card - it shows what ingredients we need, but not how to cook.
//    Our class handles weights in pounds and ounces (16 ounces = 1 pound).
//    This version does NOT use friend functions.

// #ifndef ENGLISHWEIGHT_NFF_H  
// #define ENGLISHWEIGHT_NFF_H  

#pragma once
#include <iostream>  
using namespace std;

class EnglishWeight
{
private:  
    int pounds;  
    int ounces; 

public:  
    
    // CONSTRUCTORS - these create new weight objects
    EnglishWeight();                  
    EnglishWeight(int p);                 
    EnglishWeight(int p, int o);       

    // GETTER FUNCTIONS - these let us see the private data
    int getPounds();    
    int getOunces();    

    // OPERATOR FUNCTIONS - these let us do math with + - * / symbols
    EnglishWeight operator+(EnglishWeight other);  
    EnglishWeight operator-(EnglishWeight other);  
    EnglishWeight operator*(double num);           
    EnglishWeight operator/(double num);           
    double operator/(EnglishWeight other);         

    // MEMBER FUNCTIONS (not friend functions)
    EnglishWeight multiplyByNumber(double num);    // Alternative to number * weight
    void printWeight(ostream& out);                // Alternative to cout << weight
    void readWeight(istream& in);                  // Alternative to cin >> weight

};

// REGULAR FUNCTIONS (not friend functions) - these are outside the class

// MULTIPLICATION: number * weight (regular function, not friend)
EnglishWeight multiplyNumberByWeight(double num, EnglishWeight weight);

// OUTPUT: cout << weight (regular function, not friend)
void printWeightToStream(ostream& out, EnglishWeight weight);

// INPUT: cin >> weight (regular function, not friend)
void readWeightFromStream(istream& in, EnglishWeight& weight);



// #endif  // End of our safety lock 