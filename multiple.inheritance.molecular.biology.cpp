
// A prion is a misfolded protein that causes diseases like "mad cow disease" and Creutzfeldt-Jakob disease in humans. 
// What makes prions special is that they can do three completely different things at the same time.

// 1. It's a Protein (like any normal protein):

class Protein {
public:
    void fold();                    // Shapes itself into 3D structure
    void maintainStructure();       // Keeps its shape
    string getAminoAcidSequence();  // Has a sequence of amino acids
    void performNormalFunction();   // Does useful work for the cell
    void degradeWhenDamaged();      // Gets broken down when broken
};

// 2. It's an Infectious Agent (like a virus or bacteria):

class InfectiousAgent {
public:
    void transmitInfection();    // Spreads disease from one organism to another
    void propagateInHost();      // Multiplies inside the infected organism
    void overcomeHostDefenses(); // Fights off the immune system
    void spreadBetweenCells();   // Moves from cell to cell
};

// 3. It's a Conformational Template (a "shape-changer"):

class ConformationalTemplate {
public:
    void induceStructuralChange();  // Forces other proteins to change shape
    void convertNormalProteins();   // Turns healthy proteins into diseased ones
    void propagateConformation();   // Spreads the bad shape to more proteins
    void resistDegradation();       // Can't be easily destroyed by the cell
};

// 4. How these work together ina Prion Protein : 

class Prion : public Protein, public InfectiousAgent, public ConformationalTemplate {
public:
    void convertPrPcToPrPsc();        // Changes normal protein (PrPc) to disease form (PrPsc)
    void formAmyloidFibrils();        // Creates toxic clumps in brain
    void causeNeurodegeneration();    // Kills brain cells
    void transmitWithoutNucleicAcid(); // Spreads infection without DNA/RNA
};
