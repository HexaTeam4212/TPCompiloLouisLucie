//
// Created by Louis on 18/02/2020.
//

#include "E1.h"
#include "E4.h"
#include "E5.h"


bool E1::transition(Controller &automate, Symbol *s){
    switch(*s){
        case PLUS:
            automate.shift(s, new E4);
            break;
        case MULT:
            automate.shift(s, new E5);
            break;
        case FIN:
            automate.setAccepted(true);
            break;
        default:
            automate.shift(new Symbol(ERREUR), nullptr);
    }
    return false;
}

void E1::print() const {
    cout << 1 << endl;
}
