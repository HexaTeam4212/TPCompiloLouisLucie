//
// Created by LUCIE BOVO on 27/02/2020.
//

#include "ExprPar.h"
#include <iostream>


int ExprPar::getval() {
    return(expr->getval());
}

void ExprPar::Affiche() {
    Symbole::Affiche();
}