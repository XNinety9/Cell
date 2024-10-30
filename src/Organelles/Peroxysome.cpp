// Peroxisome.cpp
#include "Peroxisome.hpp"
#include "Catalase.hpp"
#include "HydrogenPeroxide.hpp"
#include "Water.hpp"
#include "Oxygen.hpp"
#include <algorithm>

Peroxisome::Peroxisome() {
    // Initialize enzymes
    enzymes.push_back(std::make_shared<Catalase>(100)); // Example amount

    // Initialize substrates and products
    substrates.push_back(std::make_shared<HydrogenPeroxide>(1000000)); // Example amount
    substrates.push_back(std::make_shared<Water>(0));
    substrates.push_back(std::make_shared<Oxygen>(0));
}

void Peroxisome::detoxifyHydrogenPeroxide() {
    auto h2o2 = std::dynamic_pointer_cast<HydrogenPeroxide>(findMolecule(MoleculeType::HydrogenPeroxide));
    auto water = std::dynamic_pointer_cast<Water>(findMolecule(MoleculeType::Water));
    auto oxygen = std::dynamic_pointer_cast<Oxygen>(findMolecule(MoleculeType::Oxygen));
    auto catalase = std::dynamic_pointer_cast<Catalase>(findMolecule(MoleculeType::Catalase));

    if (h2o2 && water && oxygen && catalase) {
        // Define the reaction: 2 H2O2 --> 2 H2O + O2 (catalyzed by catalase)
        Reaction reaction(
                {
                        {h2o2, 2}          // Reactants
                },
                {
                        {water, 2},         // Products
                        {oxygen, 1}
                },
                catalase                // Catalyst
        );
        reaction.execute();
    }
}

MoleculePtr Peroxisome::findMolecule(MoleculeType type) {
    auto it = std::find_if(enzymes.begin(), enzymes.end(),
                           [&type](const MoleculePtr& molecule) {
                               return molecule->type == type;
                           });
    if (it != enzymes.end()) {
        return *it;
    }

    it = std::find_if(substrates.begin(), substrates.end(),
                      [&type](const MoleculePtr& molecule) {
                          return molecule->type == type;
                      });
    if (it != substrates.end()) {
        return *it;
    }

    return nullptr; // Molecule not found
}