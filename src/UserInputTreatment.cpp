//
// Created by matheus on 25/02/26.
//

#include "../include/UserInputTreatment.h"
#include <sstream>

int UserInputTreatment::intInputTreatment() {
    std::string input;
    int id;
    while (true) {
        std::getline(std::cin , input);
        std::stringstream stream(input);

        if (stream >> id && stream.eof()) { //verifica se o conteúdo da string é um número válido
            //stream >> value percorre a string colocando o conteúdo em value até achar um caractere inválido, se conseguir formar qualquer número retorna true
            //stream.eof() serve pra conferir se a string foi totalmente percorrida, se sim, retorna true. Se ainda tiver coisa depois, retorna false
            return id;
        }
        std::cout << "Insira uma opção válida!\n";
    }
}


double UserInputTreatment::doubleInputTreatment() {
    std::string input;
    double value;
    while (true) {
        std::getline(std::cin , input);
        std::stringstream stream(input);

        if (stream >> value && stream.eof()) {
            return value;
        }
        std::cout << "Insira um valor válido!\n";
    }
}

std::string UserInputTreatment::stringInputTreatment() {
    std::string descricao;
    while (true) {
        std::getline(std::cin >> std::ws, descricao);

        if (!descricao.empty()) {
            return descricao;
        }
        std::cout << "Digite uma descrição válida!";

    }
}

char UserInputTreatment::charInputTreatment() {
    std::string input;
    char confirm;
    while (true) {
        std::getline(std::cin , input);

        if (input.size() == 1) {
            return input[0];
        }
        std::cout << "Insira uma opção válida!\n";
    }
}


