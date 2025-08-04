// FILENAME:   EnglishWeight_version_with_member_functions.cpp
// PROGRAMMER: Bogdan Tanasa
// DATE:       Aug 2nd, 2025
// COMPILER:   g++
// REQUIRED:   EnglishWeight_with_member_functions.h, EnglishWeight_with_member_functions.cpp
// PURPOSE: the file contains all the functions that make our EnglishWeight class work.

#include "EnglishWeight_version_with_member_functions.h"  

// ============================================================================
// CONSTRUCTORS - to create new weight objects
// ============================================================================

// Constructor 1: Makes a weight with 0 pounds and 0 ounces
EnglishWeight::EnglishWeight()
{
    pounds = 0;  
    ounces = 0;  
}

// Constructor 2: Makes a weight with some pounds and 0 ounces
EnglishWeight::EnglishWeight(int p)
{
    pounds = p;  
    ounces = 0;  
}

// Constructor 3: Makes a weight with pounds AND ounces
EnglishWeight::EnglishWeight(int p, int o)
{
    pounds = p; 
    ounces = o;  
}

// ============================================================================
// GETTER FUNCTIONS - to see the private data
// ============================================================================

// Returns how many pounds
int EnglishWeight::getPounds()
{
    return pounds;
}

// Returns how many ounces
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
        result.pounds = result.pounds + (result.ounces / 16);  // to add extra pounds
        result.ounces = result.ounces % 16;                    // to keep leftover ounces
    }
    
    return result;
}

// SUBTRACTION: weight1 - weight2
EnglishWeight EnglishWeight::operator-(EnglishWeight other)
{
    
    EnglishWeight result;
    
    int myTotalOunces = (pounds * 16) + ounces;                 // weight in ounces
    int otherTotalOunces = (other.pounds * 16) + other.ounces;  // weight in ounces
    int answerInOunces = myTotalOunces - otherTotalOunces;
    
    if (answerInOunces < 0)
    {
        answerInOunces = 0;
    }
    
    result.pounds = answerInOunces / 16;  // whole pounds?
    result.ounces = answerInOunces % 16;  // leftover ounces?
    
    return result;
}

// MULTIPLICATION: weight * number

EnglishWeight EnglishWeight::operator*(double num)
{
    
    EnglishWeight result;
    
    int totalOunces = (pounds * 16) + ounces;
    totalOunces = (int)(totalOunces * num);
    result.pounds = totalOunces / 16;  // How many whole pounds?
    result.ounces = totalOunces % 16;  // How many leftover ounces?
    
    return result;
}

// DIVISION: weight / number

EnglishWeight EnglishWeight::operator/(double num)
{

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

// ============================================================================
// MEMBER FUNCTIONS - These are regular member functions (not friend functions)
// ============================================================================

// MEMBER FUNCTION: Alternative to number * weight
EnglishWeight EnglishWeight::multiplyByNumber(double num)
{
    
    return *this * num;  // Use the existing operator* function
}

// MEMBER FUNCTION: Alternative to cout << weight
void EnglishWeight::printWeight(ostream& out)
{
    out << pounds << " lbs ";
    out << ounces << " oz";
}

// MEMBER FUNCTION: Alternative to cin >> weight
void EnglishWeight::readWeight(istream& in)
{
    int pounds, ounces;    //local variables
    
    // read pounds from user
    cout << "Enter pounds: ";
    in >> pounds;
    
    // if pounds is negative
    if (pounds < 0)
    {
        cout << "Error: Pounds cannot be negative. Setting to 0." << endl;
        pounds = 0;
    }
    
    // read ounces from user
    cout << "Enter ounces: ";
    in >> ounces;
    
    // if ounces is negative
    if (ounces < 0)
    {
        cout << "Error: Ounces cannot be negative. Setting to 0." << endl;
        ounces = 0;
    }

    // if ounces is 16 or more
    else if (ounces >= 16)
    {
        cout << "Error: Ounces must be 0-15. Converting to pounds." << endl;
        pounds = pounds + (ounces / 16);  // to add extra pounds
        ounces = ounces % 16;             // to keep leftover ounces
    }
    
    // Set the weight with the corrected values
    this->pounds = pounds;  // Set the OBJECT's pounds (not local variable)
    this->ounces = ounces;  // Set the OBJECT's ounces (not local variable)

    // If we wrote:
    // pounds = pounds;  // it would be confusing!
    // ounces = ounces;  
    // the compiler wouldn't know if we mean:
    // the object's pounds/ounces (member variables)
    // the local pounds/ounces (local variables)

    // Generally speaking, we need this->:
    // when we have naming conflicts between member variables and local variables
    // when we want to be explicit about which variable you're referring to
    // when we are working with pointers to objects
    
    // In this case, we need it because we have local variables named pounds and ounces 
    // that conflict with the member variables of the same names :) !
}

// ============================================================================
// REGULAR FUNCTIONS - These are outside the class (not friend functions)
// ============================================================================

// REGULAR FUNCTION: number * weight 
EnglishWeight multiplyNumberByWeight(double num, EnglishWeight weight)
{
    return weight * num;  // Use the existing operator* function
}

// REGULAR FUNCTION: cout << weight
void printWeightToStream(ostream& out, EnglishWeight weight)
{
    weight.printWeight(out);  // to use the member function
}

// REGULAR FUNCTION: cin >> weight 
void readWeightFromStream(istream& in, EnglishWeight& weight)
{
    weight.readWeight(in);  // to use the member function
}

 