//
// Created by Louis on 18/02/2020.
//
#include "Automata.h"



Automata::Automata(string s) {
    this->lexer.setStream(s);
    this->lexer.setBuffer(0);
    this->lexer.setHead(0);
    this->accept = false;
}

void Automata::shift(Symbol* s, State* e){
    this->symbolstack.push_back(s);
    this->statestack.push_back(e);
}
void Automata::reduction(int n, int reductionNum){
    if (reductionNum == 2 || reductionNum == 3){
        Symbol* e1 = this->popSymbol();
        this->popAndDestroySymbol();
        Symbol* e2 = this->popSymbol();
        for (int i=0;i<n;i++)
        {
            delete(statestack.back());
            statestack.pop_back();
        }
        if (reductionNum == 2){
            statestack.back()->transition(*this, new ExprPlus((Expression*)e1,(Expression*)e2));
        }
        else if (reductionNum == 3) {
            statestack.back()->transition(*this, new ExprMult((Expression*)e1,(Expression*)e2));
        }
    }
    else if (reductionNum == 5){
        int val = symbolstack.back()->getValue();
        delete(this->symbolstack.back());
        symbolstack.pop_back();
        delete(this->statestack.back());
        statestack.pop_back();
        statestack.back()->transition(*this, new ExprVal(val));
    }
    else if (reductionNum == 4) {
        Symbol* expr = 0;
        for (int i = 0; i < n-1; i++) {
            if (i == 1) {
                expr =  this -> symbolstack.back();
                symbolstack.pop_back();
            }
            delete (this->symbolstack.back());
            symbolstack.pop_back();
            delete (this->statestack.back());
            statestack.pop_back();
        }
        delete (this->statestack.back());
        statestack.pop_back();
        statestack.back()->transition(*this,new ExprPar((Expression*) expr));
    }
}

Symbol* Automata::popSymbol() {
    Symbol* lastSymbol = symbolstack.back();
    symbolstack.pop_back();
    return lastSymbol;
}

void Automata::popAndDestroySymbol() {
    delete(this->symbolstack.back());
    symbolstack.pop_back();
}

void Automata::pushState(State *s) {
    this->statestack.push_back(s);
}

State* Automata::getTopState() {
    return this->statestack.back();
}

Symbol* Automata::getTopSymbol() {
    return this->symbolstack.back();
}

const Lexer &Automata::getLexer() const {
    return lexer;
}
//
//void Automata::printSymbolStack() {
//    for (auto it = symbolstack.begin(); it != symbolstack.end(); ++it){
//        (*it)->display();
//        cout << endl;
//    }
//}
//
//void Automata::printStateStack() {
//    for (auto it = statestack.begin(); it != statestack.end(); ++it){
//        (*it)->print();
//        cout << endl;
//    }
//}

bool Automata::isAccept() const {
    return accept;
}

void Automata::setAccept(bool newAccept) {
    Automata::accept = newAccept;
}

Automata::~Automata() {
    while (!symbolstack.empty()){
        popAndDestroySymbol();
    }
    while (!statestack.empty()){
        delete(statestack.back());
        statestack.pop_back();
    }
}
