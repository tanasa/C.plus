#include <iostream>
#include <string>

using namespace std;

// === Definitions : a structure and classes ===

struct DNABase {
    char base;          // A, C, G, T
    int position;       
    bool isMethylated;  
};

class Molecule {
public:
    string name;

    void describe() {
        cout << "Molecule: " << name << endl;
    }
};

class Protein : public Molecule {
public:
    int numAminoAcids;

    void describe() {
        cout << "Protein: " << name << ", Amino Acids: " << numAminoAcids << endl;
    }
};

class Enzyme : public Protein {
public:
    string function;

    void describe() {
        cout << "Enzyme: " << name << ", Function: " << function << endl;
    }
};

// === main() Function ===

int main() {
    
    // Using the structure

    DNABase base1 = {'G', 128, true};
  
    cout << "DNA Base: " << base1.base 
         << ", Position: " << base1.position 
         << ", Methylated: " << (base1.isMethylated ? "Yes" : "No") 
         << endl;

    // Using the class hierarchy
  
    Molecule molecule;
    molecule.name = "ATP";
    molecule.describe();

    Protein protein;
    protein.name = "Lipase";
    protein.numAminoAcids = 574;
    protein.describe();

    Enzyme enzyme;
    enzyme.name = "Lactase";
    enzyme.numAminoAcids = 1024;
    enzyme.function = "Breaks down lactose";
    enzyme.describe();

    return 0;
}
