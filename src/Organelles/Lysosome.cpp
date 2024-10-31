// Lysosome.cpp
#include "AminoAcid.hpp"
#include "Lysosome.hpp"
#include "Protease.hpp"
#include "Protein.hpp"
#include <algorithm>

Lysosome::Lysosome() {
    // Initialize enzymes
    enzymes.push_back(std::make_shared<Protease>(100));// Example amount

    // Initialize substrates (e.g., proteins to be degraded)
    substrates.push_back(std::make_shared<Protein>(1000));// Example amount
    substrates.push_back(std::make_shared<AminoAcid>(0));
}

void Lysosome::degradeProteins() {
    auto protease = std::dynamic_pointer_cast<Protease>(findMolecule(MoleculeType::Protease));
    auto protein = std::dynamic_pointer_cast<Protein>(findMolecule(MoleculeType::Protein));
    auto aminoAcid = std::dynamic_pointer_cast<AminoAcid>(findMolecule(MoleculeType::AminoAcid));

    if (protease && protein && aminoAcid) {
        // Define the reaction: Protein --> Amino Acids (catalyzed by protease)
        Reaction reaction(
            {
                { protein, 1 }// Reactants
            },
            {
                { aminoAcid, 10 }// Products (assuming each protein breaks into 10 amino acids)
            },
            protease// Catalyst
        );
        reaction.execute();
    }
}

MoleculePtr Lysosome::findMolecule(MoleculeType type) {
    auto it = std::find_if(enzymes.begin(), enzymes.end(), [&type](const MoleculePtr& molecule) { return molecule->type == type; });
    if (it != enzymes.end()) { return *it; }

    it = std::find_if(substrates.begin(), substrates.end(), [&type](const MoleculePtr& molecule) { return molecule->type == type; });
    if (it != substrates.end()) { return *it; }

    return nullptr;// Molecule not found
}