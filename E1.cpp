//
// Created by Louis on 18/02/2020.
//

#include "E1.h"
#include "E4.h"
#include "E5.h"


bool E1::transition(Automate &automate, Symbole *s){
    switch(*s){
        case PLUS:
            automate.decalage(s, new E4);
            break;
        case MULT:
            automate.decalage(s, new E5);
            break;
        case FIN:
            return true;
    }
    return false;
}

void E1::print() const {
    cout << 1 << endl;
}
