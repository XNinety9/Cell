// AminoAcid.hpp
#pragma once
#include "Molecule.hpp"

class AminoAcid : public Molecule {
  public:
    AminoAcid(uint64_t amount = 0) : Molecule(MoleculeType::AminoAcid, "Amino Acid", /* molecularWeight */ 135.0, amount) {}
};