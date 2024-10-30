// HydrogenPeroxide.h
#pragma once
#include "Molecule.hpp"

class HydrogenPeroxide : public Molecule {
public:
    HydrogenPeroxide(uint64_t amount = 0)
            : Molecule(MoleculeType::HydrogenPeroxide, "Hydrogen Peroxide", 34.0147, amount) {}
};