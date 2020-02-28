//
// Created by Louis on 18/02/2020.
//

#include "E6.h"
#include "E4.h"
#include "E5.h"
#include "E9.h"

bool E6::transition(Controller &automate, Symbol *s){
    switch(*s){
        case PLUS:
            automate.shift(s, new E4);
            break;
        case MULT:
            automate.shift(s, new E5);
            break;
        case CLOSEPAR:
            automate.shift(s, new E9);
            break;
        default:
            automate.shift(new Symbol(ERREUR), nullptr);
    }
    return false;
}

void E6::print() const {
    cout << 6 << endl;
}
