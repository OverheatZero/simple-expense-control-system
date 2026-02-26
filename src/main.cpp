//
// Created by matheus on 20/02/26.
//
#include <iostream>


#include "expenses.h"
#include "ExpensesList.h"
#include "UserInputTreatment.h"


//TODO: adicionar tratamento de input / validação do usuário
//TODO: Imprimir número com mais duas casas para o usuário (ex 2.00)
//TODO: Adicionar sistema de múltiplas listas
//TODO separar as lógicas futuramente


ExpensesList list;

void menu() {
    std::cout << "\n----Menu Principal ----\n\n"
                 "1 - Adicionar Despesa\n"
                 "2 - Listar Despesas\n"
                 "3 - Alterar Status de Despesa\n"
                 "4 - Editar Despesas\n"
                 "5 - Excluir Despesas\n"
                 "6 - Sair\n"
                 "Selecione:\n";
    int option = UserInputTreatment::intInputTreatment();

    switch (option){
        case 1: {

            std::cout << "Adicionando uma nova despesa.\n";
            std::cout << "Digite o valor: ";
            double value = UserInputTreatment::doubleInputTreatment();

            std::cout << "Digite a descrição da despesa: ";
            std::string description = UserInputTreatment::stringInputTreatment();
            list.addExpense(value, description);
            break;
        }
        case 2: {
            list.listExpenses();
            break;
        }
        case 3: {
            list.listExpenses();
            std::cout << "Digite o id da despesa que deseja mudar o status: ";
            int idStatus = UserInputTreatment::intInputTreatment();
            list.changeStatus(idStatus);
            break;
        }
        case 4: {
            list.listExpenses();
            std::cout  << "Digite o id da despesa que deseja editar: ";
            int idEdit = UserInputTreatment::intInputTreatment();
            list.editExpense(idEdit);
            break;
        }
        case 5: {
            list.listExpenses();
            std::cout << "Digite o id da despesa que deseja excluir: ";
            int excludeId = UserInputTreatment::intInputTreatment();
            list.removeExpense(excludeId);
            std::cout << "Excluindo a despesa...";
            break;
        }
        case 6: {
            std::cout << "\nSaindo...\n";
            exit(1);
        }
        default: {
            std::cout <<"\nDigite uma opção válida!\n";
            break;
        }
    }
}

int main(){
    std::cout << "Bem vindo ao gerenciador de despesas!\n";
    while (true) {
        menu();
    }
}
