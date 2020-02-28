//
// Created by Louis on 18/02/2020.
//

#include "E0.h"
#include "E1.h"
#include "E2.h"
#include "E3.h"

bool E0::transition(Automata &automate, Symbol *s){
    switch(*s){
        case EXPR:
            automate.decalage(s, new E1);
            break;
        case OPENPAR:
            automate.decalage(s, new E2);
            break;
        case INT:
            automate.decalage(s, new E3);
            break;
        default:
            automate.decalage(new Symbol(ERROR), nullptr);
    }
    return false;
}

void E0::print() const {
    cout << 0 << endl;
}

