//
// Created by Louis on 18/02/2020.
//

#include "E0.h"
#include "E1.h"
#include "E2.h"
#include "E3.h"

bool E0::transition(Automate &automate, Symbole *s){
    switch(*s){
        case EXPR:
            automate.decalage(s, new E1);
            break;
        case  OPENPAR:
            automate.decalage(s, new E2);
            break;
        case INT:
            automate.decalage(s, new E3);
            break;
    }
    return false;
}
