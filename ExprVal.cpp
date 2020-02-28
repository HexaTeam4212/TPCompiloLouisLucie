//
// Created by LUCIE BOVO on 20/02/2020.
//

#include "ExprVal.h"

int ExprVal::getValue() {
    return val;
}

void ExprVal::display() {
    Symbol::display();
    cout << "(" << val << ")" << endl;
}