//
// Created by Louis on 18/02/2020.
//

#include "automate.h"

Automate::Automate(string s) {
    this->lexer.setFlux(s);
    this->lexer.setTampon(nullptr);
    this->lexer.setTete(0);
}

void Automate::decalage(Symbole* s, State* e){
    this->symbolstack.push_back(*s);
    this->statestack.push_back(e);
}

void Automate::reduction(int n,Symbole * s) {
    //this->printStateStack();
    for (int i=0;i<n;i++)
    {
        //delete avant de pop si on travaille avec des pointeurs
        delete(this->statestack.back());
        symbolstack.pop_back();
        statestack.pop_back();
    }
    statestack.back()->transition(*this,s);
}


void Automate::reduction(int n, bool addOrMult) {
    Symbole s1 = this->popSymbol();
    this->popAndDestroySymbol();
    Symbole s2 = this->popSymbol();
    if (addOrMult){
        ExprPlus exprPlus (s2, s1);
        //stocker dans l'arbre
    }
    else {
        ExprMult exprMult (s2, s1);
        //stocker dans l'arbre
    }

    for (int i=0;i<n;i++)
    {
        //delete avant de pop si on travaille avec des pointeurs
        delete(statestack.back());
        statestack.pop_back();
    }

    statestack.back()->transition(*this, new Symbole(EXPR));
}

Symbole Automate::popSymbol() {
    Symbole lastSymbol = symbolstack.back();
    symbolstack.pop_back();
    return lastSymbol;
}

void Automate::popAndDestroySymbol() {
    symbolstack.pop_back();
}

void Automate::pushState(State *s) {
    this->statestack.push_back(s);
}

State* Automate::getTopState() {
    return this->statestack.back();
}

const Lexer &Automate::getLexer() const {
    return lexer;
}

void Automate::printSymbolStack() {
    cout << "symbol stack size : " << this->symbolstack.size() << endl;
    for (auto it=this->symbolstack.begin(); it != this->symbolstack.end(); ++it){
        it->Affiche();
        cout << endl;
    }

}

void Automate::printStateStack() {
    cout << "state stack size : " << this->statestack.size() << endl;
    for (auto it=this->statestack.begin(); it != this->statestack.end(); ++it){
        (*it)->print();
        cout << endl;
    }
}
