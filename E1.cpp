//
// Created by Louis on 18/02/2020.
//

#include "E1.h"
#include "E4.h"
#include "E5.h"


bool E1::transition(Automata &automate, Symbol *s){
    switch(*s){
        case PLUS:
            automate.decalage(s, new E4);
            break;
        case MULT:
            automate.decalage(s, new E5);
            break;
        case END:
            automate.setAccept(true);
            break;
        default:
            automate.decalage(new Symbol(ERROR), nullptr);
    }
    return false;
}

void E1::print() const {
    cout << 1 << endl;
}
