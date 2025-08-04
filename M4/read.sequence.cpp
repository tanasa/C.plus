#include <iostream>
#include <fstream>
#include <cstring>  // for strlen, strcpy

int main() {

    std::ifstream file("sequence.fasta");
    if (!file) {
        std::cout << "Cannot open file.\n";
        return 1;
    }

    std::string line;
    std::string dna = "";  // to collect the DNA sequence here

    while (std::getline(file, line)) {
        // to skip header line starting with '>'
        if (line[0] == '>') continue;
        dna += line;  // to add DNA line to the sequence
    }

    // Allocate memory to store the DNA sequence using a pointer
    int length = dna.length();
    char* sequence = new char[length + 1];  // +1 for null terminator

    // Copy the string content into the dynamically allocated memory
    strcpy(sequence, dna.c_str());

    // Output the sequence
    std::cout << "DNA sequence: " << sequence << std::endl;

    // Free the memory
    delete[] sequence;

    return 0;
}
