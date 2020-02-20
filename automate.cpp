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
void Automate::reduction(int n, int reductionNum){
    if (reductionNum == 2 || reductionNum == 3){
        Symbole* s1 = this->popSymbol();
        this->popAndDestroySymbol();
        Symbole* s2 = this->popSymbol();
        for (int i=0;i<n;i++)
        {
            delete(statestack.back());
            statestack.pop_back();
        }
        if (reductionNum == 2){
            //stocker dans l'arbre
            int s1val = (s1)->getValeur();
            int s2val = (s2)->getValeur();
            int sum = s1val + s2val;
            statestack.back()->transition(*this, new Expr(sum));
        }
        else if (reductionNum == 3) {
            //stocker dans l'arbre
            int product = (s1)->getValeur() * (s2)->getValeur();
            statestack.back()->transition(*this, new Expr(product));
        }
    }
    else if (reductionNum == 5){
        int val = symbolstack.back()->getValeur();
        delete(this->symbolstack.back());
        symbolstack.pop_back();
        delete(this->statestack.back());
        statestack.pop_back();
        statestack.back()->transition(*this, new Expr(val));
    }
    else if (reductionNum == 4) {
        int val = -1;
        for (int i = 0; i < n; i++) {
            if (i == 1)
                val = symbolstack.back()->getValeur();
            delete (this->symbolstack.back());
            symbolstack.pop_back();
            delete (this->statestack.back());
            statestack.pop_back();
        }
        statestack.back()->transition(*this, new Expr(val));
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
