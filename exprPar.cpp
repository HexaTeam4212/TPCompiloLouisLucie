//
// Created by LUCIE BOVO on 27/02/2020.
//

#include "exprPar.h"
#include <iostream> 

int ExprPar::getval() {
    cout << "ExprPar::getval() " << endl ;
    //expr->Affiche();
    int age;
    cin >> age;
    return(expr->getval());
    //return(7);
}

void ExprPar::Affiche() {
    Symbole::Affiche();
    cout << " Parenthèse " << endl ;
}