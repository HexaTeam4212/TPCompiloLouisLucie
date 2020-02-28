//
// Created by Louis on 18/02/2020.
//

#include "E8.h"
#include "E5.h"

bool E8::transition(Controller &automate, Symbol *s){
    switch(*s){
        case PLUS:
        {
            automate.reduction(3, 3);
            break;
        }
        case MULT:
            automate.reduction(3, 3);
            break;
        case CLOSEPAR: {
            automate.reduction(3, 3);
            break;
        }
        case FIN: {
            automate.reduction(3, 3);
            break;
        }
        default:
            automate.shift(new Symbol(ERREUR), nullptr);
            return false;
    }
    return true;
}

void E8::print() const {
    cout << 8 << endl;
}
