//
// Created by Louis on 18/02/2020.
//


#include "E3.h"
#include "E2.h"
#include "E6.h"


bool E2::transition(Automate &automate, Symbole *s){
    switch(*s){
        case INT:
            automate.decalage(s, new E3());
            break;
        case OPENPAR:
            automate.decalage(s, new E2);
        case EXPR:
            automate.decalage(s, new E6);
            break;
    }
    return false;
}

void E2::print() const {
    cout << 2 << endl;
}
