//
// Created by Louis on 18/02/2020.
//

#include "States.h"

State::State() = default;
State::~State() = default;
void State::print() const {}

State::State(const string &name) {}

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

bool E1::transition(Automate &automate, Symbole *s){
    switch(*s){
        case PLUS:
            automate.decalage(s, new E4);
            break;
        case MULT:
            automate.decalage(s, new E5);
            break;
        case FIN:
            automate.setAccepter(true);
            break;
        default:
            automate.decalage(new Symbole(ERREUR), nullptr);
    }
    return false;
}
void E1::print() const {
    cout << 1 << endl;
}

bool E2::transition(Automate &automate, Symbole *s){
    switch(*s){
        case INT:
            automate.decalage(s, new E3);
            break;
        case OPENPAR:
            automate.decalage(s, new E2);
            break;
        case EXPR:
            automate.decalage(s, new E6);
            break;
        default:
            automate.decalage(new Symbole(ERREUR), nullptr);
    }
    return false;
}

void E2::print() const {
    cout << 2 << endl;
}

bool E3::transition(Automate &automate, Symbole *s){
    switch(*s){
        case PLUS:
            automate.reduction(1, 5);
            break;
        case MULT:
            automate.reduction(1, 5);
            break;
        case CLOSEPAR:
            automate.reduction(1, 5);
            break;
        case FIN:
            automate.reduction(1, 5);
            break;
        default:
            automate.decalage(new Symbole(ERREUR), nullptr);
    }
    return true;
}

void E3::print() const {
    cout << 3 << endl;
}

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
        default:
            automate.decalage(new Symbole(ERREUR), nullptr);
    }
    return false;
}

void E4::print() const {
    cout << 4 << endl;
}

bool E5::transition(Automate &automate, Symbole *s){
    switch(*s){
        case INT:
            automate.decalage(s, new E3);
            break;
        case OPENPAR:
            automate.decalage(s, new E2);
            break;
        case EXPR:
            automate.decalage(s, new E8);
            break;
        default:
            automate.decalage(new Symbole(ERREUR), nullptr);
    }
    return false;
}

void E5::print() const {
    cout << 5 << endl;
}

bool E6::transition(Automate &automate, Symbole *s){
    switch(*s){
        case PLUS:
            automate.decalage(s, new E4);
            break;
        case MULT:
            automate.decalage(s, new E5);
            break;
        case CLOSEPAR:
            automate.decalage(s, new E9);
            break;
        default:
            automate.decalage(new Symbole(ERREUR), nullptr);
    }
    return false;
}

void E6::print() const {
    cout << 6 << endl;
}

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
        default:
            automate.decalage(new Symbole(ERREUR), nullptr);
            return false;
    }
    return true;
}

void E7::print() const {
    cout << 7 << endl;
}

bool E8::transition(Automate &automate, Symbole *s){
    switch(*s){
        case PLUS:
        {
            automate.reduction(3, 3);
            break;
        }
        case MULT:
            automate.reduction(3, 3);
            break;
        case CLOSEPAR: {
            automate.reduction(3, 3);
            break;
        }
        case FIN: {
            automate.reduction(3, 3);
            break;
        }
        default:
            automate.decalage(new Symbole(ERREUR), nullptr);
            return false;
    }
    return true;
}

void E8::print() const {
    cout << 8 << endl;
}

bool E9::transition(Automate &automate, Symbole *s){
    switch(*s){
        case PLUS:
        {
            automate.reduction(3, 4);
            break;
        }
        case MULT:
            automate.reduction(3, 4);
            break;
        case CLOSEPAR: {
            automate.reduction(3, 4);
            break;
        }
        case FIN: {
            automate.reduction(3, 4);
            break;
        }
        default:
            automate.decalage(new Symbole(ERREUR), nullptr);
            return false;
    }
    return true;
}

void E9::print() const {
    cout << 9 << endl;
}