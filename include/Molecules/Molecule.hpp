// Molecule.hpp
#pragma once
#include <string>
#include <cstdint>
#include <memory>
#include "MoleculeType.hpp"

// Type alias for shared pointers to Molecule
using MoleculePtr = std::shared_ptr<class Molecule>;

class Molecule {
public:
    MoleculeType type;
    std::string name;
    uint64_t amount;           // Number of molecules
    double molecularWeight;    // in g/mol

    Molecule(MoleculeType type, const std::string& name, double molecularWeight, uint64_t amount = 0)
            : type(type), name(name), molecularWeight(molecularWeight), amount(amount) {}

    virtual ~Molecule() = default;
};