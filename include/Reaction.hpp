// Reaction.h
#pragma once
#include "Molecule.hpp"
#include <vector>
#include <algorithm>

class Reaction {
public:
    struct Component {
        MoleculePtr molecule;
        uint64_t stoichiometry; // Molecule count per reaction event
    };

    Reaction(const std::vector<Component>& reactants,
             const std::vector<Component>& products,
             MoleculePtr catalyst = nullptr)
            : reactants_(reactants), products_(products), catalyst_(catalyst) {}

    void execute() {
        // Determine the maximum number of reactions that can occur
        uint64_t maxReactions = UINT64_MAX;
        for (const auto& reactant : reactants_) {
            if (reactant.stoichiometry == 0) continue;
            uint64_t possibleReactions = reactant.molecule->amount / reactant.stoichiometry;
            maxReactions = std::min(maxReactions, possibleReactions);
        }

        if (maxReactions == 0) return; // No reaction can occur

        // Consume reactants
        for (auto& reactant : reactants_) {
            reactant.molecule->amount -= reactant.stoichiometry * maxReactions;
        }

        // Produce products
        for (auto& product : products_) {
            product.molecule->amount += product.stoichiometry * maxReactions;
        }

        // Catalysts are not consumed
    }

private:
    std::vector<Component> reactants_;
    std::vector<Component> products_;
    MoleculePtr catalyst_;
};