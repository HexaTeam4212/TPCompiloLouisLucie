//
// Created by Louis on 18/02/2020.
//

#include "E9.h"

bool E9::transition(Controller &automate, Symbol *s){
    switch(*s){
        case PLUS:
        {
            automate.reduction(3, 4);
            break;
        }
        case MULT:
            automate.reduction(3, 4);
            break;
        case CLOSEPAR: {
            automate.reduction(3, 4);
            break;
        }
        case FIN: {
            automate.reduction(3, 4);
            break;
        }
        default:
            automate.shift(new Symbol(ERREUR), nullptr);
            return false;
    }
    return true;
}

void E9::print() const {
    cout << 9 << endl;
}
