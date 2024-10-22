#include "creature.h"
#include <iostream>

int main() {
    Creature crt{};

    Attributes att{0.2, .1, .5};
    
    crt.attributes = att;

    std::cout << crt.attributes.size_ << " " << crt.attributes.speed_ << " " << crt.attributes.vision_;

    std::cout << crt.attributes.damage_ << std::endl;
}