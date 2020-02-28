//
// Created by Louis on 18/02/2020.
//

#include "ExprMult.h"

int ExprMult::getval() {
    return(expr_gauche->getval()*expr_droit->getval());
}

void ExprMult::display() {
    Symbol::display();
}

Expression* ExprMult::geteg(){
    return(expr_gauche);
}
Expression* ExprMult::geted() {
    return(expr_droit);
}