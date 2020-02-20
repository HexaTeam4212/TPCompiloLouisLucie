//
// Created by Louis on 18/02/2020.
//

#include "automate.h"

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

void Automate::reduction(int n,Symbole * s) {
    for (int i=0;i<n;i++)
    {
        delete(this->symbolstack.back());
        symbolstack.pop_back();
        delete(this->statestack.back());
        statestack.pop_back();
    }
    statestack.back()->transition(*this, new Symbole(EXPR));
}


void Automate::reduction(int n, bool addOrMult) {
    Symbole* s1 = this->popSymbol();
    this->popAndDestroySymbol();
    Symbole* s2 = this->popSymbol();


    for (int i=0;i<n;i++)
    {
        delete(statestack.back());
        statestack.pop_back();
    }
    if (addOrMult){
        //stocker dans l'arbre
        int s1val = (s1)->getValeur();
        int s2val = (s2)->getValeur();
        int sum = s1val + s2val;

        statestack.back()->transition(*this, new Expr(sum));
    }
    else {
        //stocker dans l'arbre
        int product = (s1)->getValeur() * (s2)->getValeur();
        statestack.back()->transition(*this, new Expr(product));
    }
}

Symbole* Automate::popSymbol() {
    Symbole* lastSymbol = symbolstack.back();
    symbolstack.pop_back();
    return lastSymbol;
}

void Automate::popAndDestroySymbol() {
    //delete ?
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
    cout << "symbol stack size : " << this->symbolstack.size() << endl;
    for (auto & it : this->symbolstack){
        it->Affiche();
        cout << endl;
    }
}

void Automate::printStateStack() {
    cout << "state stack size : " << this->statestack.size() << endl;
    for (auto & it : this->statestack){
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
