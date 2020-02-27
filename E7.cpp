//
// Created by Louis on 18/02/2020.
//

#include "E7.h"
#include "E5.h"
#include "ExprPlus.h"

bool E7::transition(Automate &automate, Symbole *s){
    switch(*s){
        case PLUS:
        {
            automate.reduction(3, 2);
            break;
        }
        case MULT:
            automate.decalage(s, new E5);
            return false;
        case CLOSEPAR: {
            automate.reduction(3, 2);
            break;
        }
        case FIN: {
            automate.reduction(3, 2);
            break;
        }
    }
    return true;
}

void E7::print() const {
    cout << 7 << endl;
}
