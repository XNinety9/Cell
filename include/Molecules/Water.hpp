// Water.h
#pragma once
#include "Molecule.hpp"
#include "MoleculeType.hpp"

class Water : public Molecule {
public:
    Water(uint64_t amount = 0)
            : Molecule(MoleculeType::Water, "Water", 18.01528, amount) {}
};