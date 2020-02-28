//
// Created by Louis on 18/02/2020.
//

#include "E3.h"


bool E3::transition(Automata &automate, Symbol *s){
    switch(*s){
        case PLUS:
            automate.reduction(1, 5);
            break;
        case MULT:
            automate.reduction(1, 5);
            break;
        case CLOSEPAR:
            automate.reduction(1, 5);
            break;
        case END:
            automate.reduction(1, 5);
            break;
        default:
            automate.decalage(new Symbol(ERROR), nullptr);
    }
    return true;
}

void E3::print() const {
    cout << 3 << endl;
}
