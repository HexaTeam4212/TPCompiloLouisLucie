//
// Created by Louis on 18/02/2020.
//

#include "ExprPlus.h"

int ExprPlus::getval() {
    return(expr_left->getval()+expr_right->getval());
}

void ExprPlus::Display() {
    Symbol::Display();
}

Expression* ExprPlus::geteleft()
{
    return(expr_left);
}
Expression* ExprPlus::geteright() {
    return(expr_right);
}