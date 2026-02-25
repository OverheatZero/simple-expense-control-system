//
// Created by matheus on 20/02/26.
//
#include <iostream>


#include "expenses.h"
#include "ExpensesList.h"


//TODO: adicionar tratamento de input
//TODO: Imprimir número com mais duas casas para o usuário (ex 2.00)
//TODO: Adicionar sistema de múltiplas listas

ExpensesList list;

void menu() {
    int option;
    std::cout << "\n----Menu Principal ----\n\n"
                 "1 - Adicionar Despesa\n"
                 "2 - Listar Despesas\n"
                 "3 - Alterar Status de Despesa\n"
                 "4 - Editar Despesas\n"
                 "5 - Excluir Despesas\n"
                 "6 - Sair\n"
                 "Selecione:\n";
    std::cin >> option;

    switch (option){
        case 1: {

            double value;
            std::string description;

            std::cout << "Adicionando uma nova despesa.\n";
            std::cout << "Digite o valor: ";
            std::cin >> value;

            std::cout << "Digite a descrição da despesa: ";
            std::getline(std::cin >> std::ws, description);
            list.addExpense(value, description);
            break;
        }
        case 2:
            list.listExpenses();
            break;
        case 3:
            list.listExpenses();
            int idStatus;
            std::cout << "Digite o id da despesa que deseja mudar o status: ";
            std::cin >> idStatus;
            list.changeStatus(idStatus);

            break;
        case 4:
            list.listExpenses();
            int idEdit;
            std::cout  << "Digite o id da despesa que deseja editar: ";
            std::cin >> idEdit;
            list.editExpense(idEdit);
            break;
        case 5:
            int excludeId;
            list.listExpenses();
            std::cout << "Digite o id da despesa que deseja excluir: ";
            std::cin >> excludeId;
            list.removeExpense(excludeId);
            std::cout << "Excluindo a despesa...";
            break;
        case 6:
            std::cout << "\nSaindo...\n";
            exit(1);
        default:
            std::cout <<"\nDigite uma opção válida!\n";
            break;
    }
}

int main(){
    std::cout << "Bem vindo ao gerenciador de despesas!\n";
    while (true) {
        menu();
    }
}
