// Main.cpp
#include "Lysosome.hpp"
#include "Peroxisome.hpp"
#include <iostream>

int main() {
    Peroxisome peroxisome;

    // Simulate a number of steps
    for (int i = 0; i < 1000; ++i) { peroxisome.detoxifyHydrogenPeroxide(); }

    // Access molecule amounts for analysis
    auto water = peroxisome.findMolecule(MoleculeType::Water);
    auto oxygen = peroxisome.findMolecule(MoleculeType::Oxygen);

    if (water && oxygen) {
        std::cout << water->name << " molecules: " << water->amount << std::endl;
        std::cout << oxygen->name << " molecules: " << oxygen->amount << std::endl;
    }

    Lysosome lysosome;

    // Simulate a number of steps
    for (int i = 0; i < 100; ++i) { lysosome.degradeProteins(); }

    // Access molecule amounts for analysis
    auto aminoAcid = lysosome.findMolecule(MoleculeType::AminoAcid);

    if (aminoAcid) { std::cout << aminoAcid->name << " molecules: " << aminoAcid->amount << std::endl; }

    return 0;
}