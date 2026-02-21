//
// Created by matheus on 20/02/26.
//

#include "expenses.h"

Expenses::Expenses(double value, std::string description) {
    this->value = value;
    this->description = description;
}

double Expenses::getValue() {return value;}
void Expenses::setValue(double value){this->value = value;}

std::string Expenses::getDescription() {return description;}
void Expenses::setDescription(std::string description){ this->description = description;}