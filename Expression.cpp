//
// Created by LUCIE BOVO on 20/02/2020.
//

#include "Expression.h"



void Expression::Affiche() {
    Symbole::Affiche();
}

int Expression::getval() {
    return -1111;
}

Expression* Expression::geteg()
{
    return(expr_gauche);
}
Expression* Expression::geted() {
    return(expr_droit);
}