//
// Created by LUCIE BOVO on 27/02/2020.
//

#include "exprPar.h"

int ExprPar::getval() {
    cout << "ExprPar::getval() " << endl ;
    return(expr->getval());
}

void ExprPar::Affiche() {
    Symbole::Affiche();
    cout << " Parenthèse " << endl ;
}