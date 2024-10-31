// Protein.hpp
#pragma once
#include "Molecule.hpp"

class Protein : public Molecule {
  public:
    Protein(uint64_t amount = 0) : Molecule(MoleculeType::Protein, "Protein", /* molecularWeight */ 100000.0, amount) {}
};
