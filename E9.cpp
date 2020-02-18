//
// Created by Louis on 18/02/2020.
//

#include "E9.h"

bool E9::transition(Automate &automate, Symbole *s){
    switch(*s){
        case PLUS:
        {
            automate.reduction(3, new Symbole(EXPR));
            break;
        }
        case MULT:
            automate.reduction(3, new Symbole(EXPR));
            break;
        case CLOSEPAR: {
            automate.reduction(3, new Symbole(EXPR));
            break;
        }
        case FIN: {
            automate.reduction(3, new Symbole(EXPR));
            break;
        }
    }
    return false;
}

void E9::print() const {
    cout << 9 << endl;
}
