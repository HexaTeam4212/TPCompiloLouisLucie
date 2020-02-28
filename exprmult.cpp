//
// Created by Louis on 18/02/2020.
//

#include "ExprMult.h"

int ExprMult::getval() {
    return(expr_left->getval()*expr_right->getval());
}

void ExprMult::Display() {
    Symbol::Display();
}
