//
// Created by matheus on 21/02/26.
//

#ifndef EXPENSESLIST_H
#define EXPENSESLIST_H
#include <vector>

#include "expenses.h"


class ExpensesList {
public:


    void addExpense(double value, std::string description);
    void removeExpense(int expenseId);
    void editExpense(int expenseId);
    void listExpenses();



    double getTotalValue();
    int getTotalExpenses();

    void changeStatus(int id);
private:
    std::vector<Expenses> vectorExpenses;
    std::string listName; //TODO adicionar um uso futuramente
};



#endif //EXPENSESLIST_H
