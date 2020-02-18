//
// Created by Louis on 18/02/2020.
//

#include "E3.h"


bool E3::transition(Automate &automate, Symbole *s){
    switch(*s){
        case PLUS:
            automate.reduction(1, new Symbole(EXPR));
            break;
        case MULT:
            automate.reduction(1, new Symbole(EXPR));
            break;
        case CLOSEPAR:
            automate.reduction(1, new Symbole(EXPR));
            break;
        case FIN:
            automate.reduction(1, new Symbole(EXPR));
            break;
    }
    return false;
}

void E3::print() const {
    cout << 3 << endl;
}
