// Protease.hpp
#pragma once
#include "Molecule.hpp"

class Protease : public Molecule {
  public:
    Protease(uint64_t amount = 1) : Molecule(MoleculeType::Protease, "Protease", /* molecularWeight */ 50000.0, amount) {}
};
