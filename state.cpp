//
// Created by Louis on 18/02/2020.
//

#include "State.h"
#include <iostream>

State::State() {}
State::State(string name) {}
State::~State() {}
void State::print() const {
    cout << "not a state" << endl;
}

bool E0::transition(Automate &automate, Symbole *s){
    switch(*s){
        case EXPR:
            automate.decalage(s, new E1);
            break;
        case OPENPAR:
            automate.decalage(s, new E2);
            break;
        case INT:
            automate.decalage(s, new E3);
            break;
        default:
            automate.decalage(new Symbole(ERREUR), nullptr);
    }
    return false;
}
void E0::print() const {
    cout << 0 << endl;
}
