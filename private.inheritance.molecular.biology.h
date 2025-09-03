// When CodonReader privately inherits from GeneSequence, all of the public members of GeneSequence become private members of CodonReader.
// Based on the molecular_biology.h file, these are the functions that became private in the CodonReader class:
// void appendBasePair(char base);
// std::string findSubsequence(size_t start, size_t length) const;
// void printSequence() const;

// This means that any code using an object of the CodonReader type cannot directly call these functions. 
// Instead, the CodonReader's public methods, like loadSequence and getNextCodon, must internally call the now-private GeneSequence functions to perform their tasks. 
// This design enforces a specific, limited interface for the user, preventing them from improperly modifying or accessing the underlying DNA sequence.

#ifndef MOLECULAR_BIOLOGY_H
#define MOLECULAR_BIOLOGY_H

#include <iostream>
#include <string>

// The base class representing a DNA gene sequence.
class GeneSequence {
private:
    std::string sequence;
public:
    // Public functions for a sequence
    void appendBasePair(char base);
    std::string findSubsequence(size_t start, size_t length) const;
    void printSequence() const;
};

// The derived class that privately inherits from GeneSequence.
// It will only expose functions for reading codons.
class CodonReader : private GeneSequence {
public:
    CodonReader();
    // Public function to add the sequence to read
    void loadSequence(const std::string& dna);
    // Public function to get the next codon
    std::string getNextCodon();
    // Public function to check if there are more codons
    bool hasMoreCodons() const;
};

#endif // MOLECULAR_BIOLOGY_H
