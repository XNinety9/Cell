// Peroxisome.h
#pragma once
#include "Molecule.hpp"
#include "Reaction.hpp"
#include <vector>

class Peroxisome {
public:
    Peroxisome();
    ~Peroxisome() = default;

    void detoxifyHydrogenPeroxide();
    MoleculePtr findMolecule(MoleculeType type);

private:
    std::vector<MoleculePtr> enzymes;
    std::vector<MoleculePtr> substrates;
};