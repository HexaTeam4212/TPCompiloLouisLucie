//
// Created by Louis on 18/02/2020.
//

#include "expr.h"

int Expr::getVal() const {
    return val;
}

void Expr::setVal(int val) {
    Expr::val = val;
}

void Expr::Affiche() {
    Symbole::Affiche();
    cout<<"("<<val<<")";

}
