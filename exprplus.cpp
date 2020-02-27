//
// Created by Louis on 18/02/2020.
//

#include "ExprPlus.h"

int ExprPlus::getval() {
    return(expr_gauche->getval()+expr_droit->getval());
}

void ExprPlus::Affiche() {
    Symbole::Affiche();
}

Expression* ExprPlus::geteg()
{
    return(expr_gauche);
}
Expression* ExprPlus::geted() {
    return(expr_droit);
}