//
// Created by Louis on 18/02/2020.
//

#include "ExprMult.h"

ExprMult::~ExprMult() {
    delete expr_gauche;
    delete expr_droit;
}

int ExprMult::getValue() {
    return(expr_gauche->getValue() * expr_droit->getValue());
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