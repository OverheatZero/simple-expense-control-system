    //
    // Created by matheus on 20/02/26.
    //

    #ifndef EXPENSES_H
    #define EXPENSES_H
    #include <string>


    enum class ExpenseStatus {
        ACTIVE,
        PAID
    };

    class Expenses {
    public:
        Expenses(double value, std::string description, int expenseId);
        double getValue();
        void setValue(double value);

        std::string getDescription();
        void setDescription(std::string description);

        ExpenseStatus getStatus();
        void setStatus(ExpenseStatus status);

        int getExpenseId();
        void setExpenseId(int expenseId);

        static void incrementNextId();
        static int getNextId();

        static Expenses createExpense(double valor, std::string descricao);


    private:
        double value;
        std::string description;
        ExpenseStatus status;
        int expenseId;
        static int nextId;
    };

    #endif //EXPENSES_H
