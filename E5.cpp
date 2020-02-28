//
// Created by Louis on 18/02/2020.
//

#include "E5.h"
#include "E3.h"
#include "E2.h"
#include "E8.h"

bool E5::transition(Automata &automate, Symbol *s){
    switch(*s){
        case INT:
            automate.decalage(s, new E3);
            break;
        case OPENPAR:
            automate.decalage(s, new E2);
            break;
        case EXPR:
            automate.decalage(s, new E8);
            break;
        default:
            automate.decalage(new Symbol(ERROR), nullptr);
    }
    return false;
}

void E5::print() const {
    cout << 5 << endl;
}
