//
// Created by Louis on 18/02/2020.
//
#include "Automate.h"

Automate::Automate(string s) {
    this->lexer.setFlux(s);
    this->lexer.setTampon(nullptr);
    this->lexer.setTete(0);
    this->accepter = false;
}

void Automate::decalage(Symbole* s, State* e){
    this->symbolstack.push_back(s);
    this->statestack.push_back(e);
}
void Automate::reduction(int n, int reductionNum){
    if (reductionNum == 2 || reductionNum == 3){
        Symbole* e1 = this->popSymbol();
        this->popAndDestroySymbol();
        Symbole* e2 = this->popSymbol();
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
        int val = symbolstack.back()->getValeur();
        delete(this->symbolstack.back());
        symbolstack.pop_back();
        delete(this->statestack.back());
        statestack.pop_back();
        statestack.back()->transition(*this, new ExprVal(val));
    }
    else if (reductionNum == 4) {
        int val = -1;
        Symbole* expr;
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

Symbole* Automate::popSymbol() {
    Symbole* lastSymbol = symbolstack.back();
    symbolstack.pop_back();
    return lastSymbol;
}

void Automate::popAndDestroySymbol() {
    delete(this->symbolstack.back());
    symbolstack.pop_back();
}

void Automate::pushState(State *s) {
    this->statestack.push_back(s);
}

State* Automate::getTopState() {
    return this->statestack.back();
}

Symbole* Automate::getTopSymbole() {
    return this->symbolstack.back();
}

const Lexer &Automate::getLexer() const {
    return lexer;
}

void Automate::printSymbolStack() {
    for (Symbole* it : this->symbolstack){
        it->Affiche();
        cout << endl;
    }
}

void Automate::printStateStack() {
    for (State* it : this->statestack){
        it->print();
        cout << endl;
    }
}

bool Automate::isAccepter() const {
    return accepter;
}

void Automate::setAccepter(bool accepter) {
    Automate::accepter = accepter;
}
