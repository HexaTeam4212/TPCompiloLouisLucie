//
// Created by Louis on 18/02/2020.
//

#include "exprmult.h"

int ExprMult::getval() {
    return(expr_gauche->getval()*expr_droit->getval());
}
//ExprMult::ExprMult(const Symbole &s1, const Symbole &s2) : s1(s1), s2(s2) {}

void ExprMult::Affiche() {
    Symbole::Affiche();
    cout << " plus " << endl ;
}