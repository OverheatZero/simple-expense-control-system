//
// Created by matheus on 21/02/26.
//

#include "../include/ExpensesList.h"

#include <iostream>
#include <list>
#include <bits/locale_facets_nonio.h>

#include "UserInputTreatment.h"


int ExpensesList::getTotalExpenses() {
    int size = 0;
    for (int i = 0; i<vectorExpenses.size(); i++) {
        if (vectorExpenses[i].getStatus() == ExpenseStatus::ACTIVE) {
            size++;
        }
    }
    return size;
}

double ExpensesList::getTotalValue() {
    double total = 0;
    for (int i = 0; i < vectorExpenses.size(); i++) {
        if (vectorExpenses[i].getStatus() == ExpenseStatus::ACTIVE) {
            total += vectorExpenses[i].getValue();
        }
    }
    return total;
}


void ExpensesList::addExpense(double value, std::string description) {
    Expenses expense = Expenses::createExpense(value, description);
    vectorExpenses.push_back(expense);
}

void ExpensesList::listExpenses() {
    std::cout << "\n----Despesas cadastradas----\n";
    if (vectorExpenses.empty()) {
        std::cout << "Não há nenhuma despesa cadastrada!\n";
        return;
    }
    for (int i = 0; i < vectorExpenses.size(); i++) {
        std::cout <<"Id: " << vectorExpenses[i].getExpenseId() <<" - " << vectorExpenses[i].getDescription()
        << " - R$" << vectorExpenses[i].getValue() << " - Status: " << vectorExpenses[i].toStringStatus() << "\n";
    }
    int totalExpenses = getTotalExpenses();
    double valorTotal = getTotalValue();
    std::cout << "Quantidade de Despesas Ativas: " << totalExpenses << " - Valor total: R$" << valorTotal << "\n" ;
}

void ExpensesList::removeExpense(int expenseId) {
    std::cout << "\n----Excluir Despesa---\n";
    for (int i = 0; i < vectorExpenses.size(); i++) {
        if (vectorExpenses[i].getExpenseId() == expenseId) {
            vectorExpenses.erase(vectorExpenses.begin() + i);
            return;
        }
    }
}

void ExpensesList::editExpense(int expenseId) {
    double valor;
    std::string descricao;
    for (int i = 0; i < vectorExpenses.size(); i++) {
        if (vectorExpenses[i].getExpenseId() == expenseId) {
            valor = vectorExpenses[i].getValue();
            descricao = vectorExpenses[i].getDescription();
            std::cout << "Valor atual da Despesa: R$" << valor << "\n";
            std::cout << "Deseja alterar o valor da despesa? s/n\n";
            char confirm = UserInputTreatment::charInputTreatment();
            if (confirm == 's') {
                std::cout << "Digite o novo valor da despesa: ";
               valor = UserInputTreatment::doubleInputTreatment();
                vectorExpenses[i].setValue(valor);
                std::cout << "Valor da despesa alterado com sucesso.\n\n";
            }
            std::cout << "Descrição atual da despesa: " << descricao << "\n";
            std::cout << "Deseja alterar a descrição da despesa? s/n\n";
            std::cin >> confirm;
            if (confirm == 's' || confirm == 'S') {
                std::cout << "Digite a nova descrição da despesa: ";
                descricao = UserInputTreatment::stringInputTreatment();
                vectorExpenses[i].setDescription(descricao);
                std::cout << "Descrição da despesa alterada com sucesso.\n\n";
            }
            return;
        }
    }
}

void ExpensesList::changeStatus(int id) {
    for (int i = 0; i < vectorExpenses.size(); i++) {
        if (id == vectorExpenses[i].getExpenseId()) {
            vectorExpenses[i].changeExpenseStatus();
        }
    }
}



