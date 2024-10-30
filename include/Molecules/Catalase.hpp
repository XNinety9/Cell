// Catalase.h
#pragma once
#include "Molecule.hpp"

class Catalase : public Molecule {
public:
    Catalase(uint64_t amount = 1)
            : Molecule(MoleculeType::Catalase, "Catalase", 250000.0, amount) {}
};