#include "Ability.hpp"

Ability::Ability() {
    this->value = 0;
}

Ability::Ability(double value) {
    this->value = value;
}

double Ability::getValue() {
    return this->value;
}