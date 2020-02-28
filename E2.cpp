//
// Created by Louis on 18/02/2020.
//


#include "E3.h"
#include "E2.h"
#include "E6.h"


bool E2::transition(Controller &automate, Symbol *s){
    switch(*s){
        case INT:
            automate.shift(s, new E3);
            break;
        case OPENPAR:
            automate.shift(s, new E2);
            break;
        case EXPR:
            automate.shift(s, new E6);
            break;
        default:
            automate.shift(new Symbol(ERREUR), nullptr);
    }
    return false;
}

void E2::print() const {
    cout << 2 << endl;
}
