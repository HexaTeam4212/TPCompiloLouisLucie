//
// Created by Louis on 18/02/2020.
//

#include "E0.h"
#include "E1.h"
#include "E2.h"
#include "E3.h"

bool E0::transition(Controller &automate, Symbol *s){
    switch(*s){
        case EXPR:
            automate.shift(s, new E1);
            break;
        case OPENPAR:
            automate.shift(s, new E2);
            break;
        case INT:
            automate.shift(s, new E3);
            break;
        default:
            automate.shift(new Symbol(ERREUR), nullptr);
    }
    return false;
}

void E0::print() const {
    cout << 0 << endl;
}

