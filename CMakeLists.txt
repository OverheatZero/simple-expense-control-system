cmake_minimum_required(VERSION 3.20)
project(simple_expense_control_system)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(simple_expense_control_system
        src/main.cpp
        src/expenses.cpp
        src/ExpensesList.cpp
)

target_include_directories(simple_expense_control_system PRIVATE include)