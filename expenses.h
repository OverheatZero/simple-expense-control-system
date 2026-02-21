//
// Created by matheus on 20/02/26.
//

#ifndef EXPENSES_H
#define EXPENSES_H
#include <string>


class Expenses {
public:
    Expenses(double value, std::string description);
    double getValue();
    void setValue(double value);

    std::string getDescription();
    void setDescription(std::string description);

private:
    double value;
    std::string description;
};

#endif //EXPENSES_H
