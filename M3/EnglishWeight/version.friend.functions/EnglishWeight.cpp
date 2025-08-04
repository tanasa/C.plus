// FILENAME:   EnglishWeight.cpp
// PROGRAMMER: Bogdan Tanasa
// DATE:       Aug 2nd, 2025
// COMPILER:   g++
// REQUIRED:   EnglishWeight.h, EnglishWeight.cpp
// PURPOSE:
// This file contains all the functions that make our EnglishWeight class work.

#include "EnglishWeight.h" 

// Constructor 1: Makes a weight with 0 pounds and 0 ounces
EnglishWeight::EnglishWeight()
{
    pounds = 0;  // Start with 0 pounds
    ounces = 0;  // Start with 0 ounces
}

// Constructor 2: Makes a weight with some pounds and 0 ounces
EnglishWeight::EnglishWeight(int p)
{
    pounds = p;  // Use the pounds they gave us
    ounces = 0;  // Start with 0 ounces
}

// Constructor 3: Makes a weight with pounds AND ounces
EnglishWeight::EnglishWeight(int p, int o)
{
    pounds = p;  // Use the pounds they gave us
    ounces = o;  // Use the ounces they gave us
}

// ============================================================================
// GETTER FUNCTIONS - to see the private data
// ============================================================================

int EnglishWeight::getPounds()
{
    return pounds;
}

int EnglishWeight::getOunces()
{
    return ounces;
}

// ============================================================================
// OPERATOR FUNCTIONS - to do math with weights
// ============================================================================

// ADDITION: weight1 + weight2

EnglishWeight EnglishWeight::operator+(EnglishWeight other)
{

    EnglishWeight result;

    result.pounds = pounds + other.pounds;
    result.ounces = ounces + other.ounces;
    
    if (result.ounces >= 16)
    {
        result.pounds = result.pounds + (result.ounces / 16);  // Add ounces to extra pounds
        result.ounces = result.ounces % 16;                    // Keep leftover ounces
    }
    
    return result;
}

// SUBTRACTION: weight1 - weight2

EnglishWeight EnglishWeight::operator-(EnglishWeight other)
{
    EnglishWeight result;

    // Transform weight in ounces 
    int myTotalOunces = (pounds * 16) + ounces;                 // weight in ounces
    int otherTotalOunces = (other.pounds * 16) + other.ounces;  // weight in ounces
    int answerInOunces = myTotalOunces - otherTotalOunces;

    if (answerInOunces < 0)
    {
        answerInOunces = 0;
    }
    
    // Convert back to pounds and ounces
    result.pounds = answerInOunces / 16;  // How many whole pounds?
    result.ounces = answerInOunces % 16;  // How many leftover ounces?
    
    return result;
}

// MULTIPLICATION: weight * number

EnglishWeight EnglishWeight::operator*(double num)
{
    
    EnglishWeight result;
    
    int totalOunces = (pounds * 16) + ounces;
    totalOunces = (int)(totalOunces * num);
    
    result.pounds = totalOunces / 16;  // whole pounds?
    result.ounces = totalOunces % 16;  // leftover ounces?
    
    return result;
}

// DIVISION: weight / number

EnglishWeight EnglishWeight::operator/(double num)
{
    // check for division by zero
    if (num == 0)
    {
        cout << "Error: Cannot divide by zero!" << endl;
        return EnglishWeight(0, 0);  // Return zero weight
    }
        
    EnglishWeight result;
    
    int totalOunces = (pounds * 16) + ounces;
    totalOunces = (int)(totalOunces / num);

    result.pounds = totalOunces / 16;  // whole pounds?
    result.ounces = totalOunces % 16;  // leftover ounces?
    
    return result;
}

// DIVISION: weight1 / weight2 (returns a ratio)

double EnglishWeight::operator/(EnglishWeight other)
{
    
    if (other.pounds == 0 && other.ounces == 0)
    {
        cout << "Error: Cannot divide by zero weight!" << endl;
        return 0.0;
    }
    
    int myTotalOunces = (pounds * 16) + ounces;
    int otherTotalOunces = (other.pounds * 16) + other.ounces;
    double ratio = (double)myTotalOunces / otherTotalOunces;
    
    return ratio;
}

// MULTIPLICATION: number * weight (same as weight * number)

EnglishWeight operator*(double num, EnglishWeight weight)
{
    return weight * num;  // Just use the other multiplication function
}

// ============================================================================
// FRIEND FUNCTIONS : special functions that can see private data : 
// ============================================================================


// OUTPUT: cout << weight
ostream& operator<<(ostream& out, EnglishWeight weight)
{
    // Print pounds
    out << weight.pounds << " lb ";
    // Print ounces
    out << weight.ounces << " oz";

    return out;
}

// INPUT: cin >> weight
istream& operator>>(istream& in, EnglishWeight& weight)
{
    int pounds, ounces;
    
    // read the pounds from the user
    cout << "Enter pounds: ";
    in >> pounds;
    
    // If pounds is negative
    if (pounds < 0)
    {
        cout << "Error: Pounds cannot be negative. Setting to 0." << endl;
        pounds = 0;
    }
    
    // read the ounces from the user
    cout << "Enter ounces: ";
    in >> ounces;
    
    // check if ounces is negative
    if (ounces < 0)
    {
        cout << "Error: Ounces cannot be negative. Setting to 0." << endl;
        ounces = 0;
    }

    // check if ounces is 16 or more
    else if (ounces >= 16)
    {
        cout << "Error: Ounces must be 0-15. Converting to pounds." << endl;
        pounds = pounds + (ounces / 16);  // Add extra pounds
        ounces = ounces % 16;             // Keep leftover ounces
    }
    
    // set the weight with the corrected values
    weight.pounds = pounds;
    weight.ounces = ounces;
    
    return in;
}