//
// Created by LUCIE BOVO on 27/02/2020.
//

#include "ExprPar.h"
#include <iostream>


int ExprPar::getValue() {
    return(expr->getValue());
}

void ExprPar::display() {
    Symbol::display();
}