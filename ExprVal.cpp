//
// Created by LUCIE BOVO on 20/02/2020.
//

#include "ExprVal.h"

int ExprVal::getval() {
    return val;
}

void ExprVal::Display() {
    Symbol::Display();
    cout << "(" << val << ")" << endl;
}