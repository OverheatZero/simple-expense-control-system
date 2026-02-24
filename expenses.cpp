//
// Created by matheus on 20/02/26.
//

#include "expenses.h"

#include <iostream>

Expenses::Expenses(double value, std::string description, int expenseId) {
    this->value = value;
    this->description = description;
    this->status = ExpenseStatus::ACTIVE;
    this->expenseId = expenseId;
}

double Expenses::getValue() {return value;}
void Expenses::setValue(double value){this->value = value;}

std::string Expenses::getDescription() {return description;}
void Expenses::setDescription(std::string description){ this->description = description;}

ExpenseStatus Expenses::getStatus() {return status;}
void Expenses::setStatus(ExpenseStatus status){this->status = status;}

int Expenses::getExpenseId() {return expenseId;}
void Expenses::setExpenseId(int expenseId){this->expenseId = expenseId;}

void Expenses::incrementNextId() {nextId++;}
int Expenses::getNextId() {return nextId;}

int Expenses::nextId = 1;

Expenses Expenses::createExpense(double value, std::string description) {
    int const expenseId = getNextId();
    incrementNextId();

    return Expenses(value, description, expenseId);
}
