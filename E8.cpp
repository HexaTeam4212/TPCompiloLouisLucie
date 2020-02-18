//
// Created by Louis on 18/02/2020.
//

#include "E8.h"
#include "E5.h"

bool E8::transition(Automate &automate, Symbole *s){
    switch(*s){
        case PLUS:
        {
            automate.reduction(3, false);
            break;
        }
        case MULT:
            automate.reduction(3, false);
            break;
        case CLOSEPAR: {
            automate.reduction(3, false);
            break;
        }
        case FIN: {
            automate.reduction(3, false);
            break;
        }
    }
    return false;
}