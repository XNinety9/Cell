// Main.cpp
#include "Peroxisome.hpp"
#include <iostream>

int main() {
    Peroxisome peroxisome;

    // Simulate a number of steps
    for (int i = 0; i < 1000; ++i) {
        peroxisome.detoxifyHydrogenPeroxide();
    }

    // Access molecule amounts for analysis
    auto water = peroxisome.findMolecule(MoleculeType::Water);
    auto oxygen = peroxisome.findMolecule(MoleculeType::Oxygen);

    if (water && oxygen) {
        std::cout << water->name << " molecules: " << water->amount << std::endl;
        std::cout << oxygen->name << " molecules: " << oxygen->amount << std::endl;
    }

    return 0;
}