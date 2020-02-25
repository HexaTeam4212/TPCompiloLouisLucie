//
// Created by Louis on 18/02/2020.
//

#include "exprplus.h"

//ExprPlus::ExprPlus(const Entier &s1, const Entier &s2){
//    this->s1 = s1;
//    this->s2 = s2;
//    Symbole(EXPR);
//}

int ExprPlus::getval() {
    return(expr_gauche->getval()+expr_droit->getval());
}

void ExprPlus::Affiche() {
    Symbole::Affiche();
    cout << " plus " << endl ;
}