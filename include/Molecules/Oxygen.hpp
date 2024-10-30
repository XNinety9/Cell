// Oxygen.h
#pragma once
#include "Molecule.hpp"

class Oxygen : public Molecule {
public:
    Oxygen(uint64_t amount = 0)
            : Molecule(MoleculeType::Oxygen, "Oxygen", 31.9988, amount) {}
};