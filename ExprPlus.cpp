//
// Created by Louis on 18/02/2020.
//

#include "ExprPlus.h"

int ExprPlus::getValue() {
    return(expr_gauche->getValue() + expr_droit->getValue());
}

void ExprPlus::display() {
    Symbol::display();
}

Expression* ExprPlus::geteg()
{
    return(expr_gauche);
}
Expression* ExprPlus::geted() {
    return(expr_droit);
}