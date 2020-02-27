//
// Created by LUCIE BOVO on 20/02/2020.
//

#include "ExprVal.h"

int ExprVal::getval() {
    cout << "ExprVal::getval()" << endl ;
    return val;
}

void ExprVal::Affiche() {
    Symbole::Affiche();
    cout << "(" << val << ")" << endl;
}