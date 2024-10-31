// Lysosome.hpp
#pragma once
#include "Molecule.hpp"
#include "Reaction.hpp"
#include <vector>

class Lysosome {
  public:
    Lysosome();
    ~Lysosome() = default;

    void degradeProteins();
    MoleculePtr findMolecule(MoleculeType type);

  private:
    std::vector<MoleculePtr> enzymes;
    std::vector<MoleculePtr> substrates;
};