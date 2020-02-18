//
// Created by Louis on 18/02/2020.
//

#include "E4.h"
#include "E3.h"
#include "E7.h"
#include "E2.h"

bool E4::transition(Automate &automate, Symbole *s){
    switch(*s){
        case INT:
            automate.decalage(s, new E3);
            break;
        case OPENPAR:
            automate.decalage(s, new E2);
            break;
        case EXPR:
            automate.decalage(s, new E7);
            break;
    }
    return false;
}

void E4::print() const {
    cout << 4 << endl;
}
