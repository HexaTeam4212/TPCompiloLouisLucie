//
// Created by Louis on 18/02/2020.
//

#include "automate.h"

#include <iostream>

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
        //int s1val = ((Expression *)s1)->getval();
        //cout<< "s1 get = " << s1val << endl;
        //s1->Affiche();
        //Expression* e1=new ExprPar((Expression*) s1);
        this->popAndDestroySymbol();
        Symbole* e2 = this->popSymbol();
        //int s2val = ((Expression *)s2)->getval();
        //cout<< "s2 get = " << s2val;
        //s2->Affiche();
        //Expression* e2=new ExprPar((Expression*)s2);

        for (int i=0;i<n;i++)
        {
            delete(statestack.back());
            statestack.pop_back();
        }
        if (reductionNum == 2){
            //stocker dans l'arbre
            cout << "r2 : " << endl;
            //int s1val = (s1)->getValeur();
            //int s2val = (s2)->getValeur();
            //int sum = s1val + s2val;
            statestack.back()->transition(*this, new ExprPlus((Expression*)e1,(Expression*)e2));
            //ExprPlus* E=new ExprPlus((Expression*) expr_arbre,(Expression*) s2);
            //expr_arbre=E;
            cout << "r2 fin: " << endl;
        }
        else if (reductionNum == 3) {
            cout << "r3 : " << endl;
            //stocker dans l'arbre
            //int product = (s1)->getValeur() * (s2)->getValeur();
            statestack.back()->transition(*this, new ExprMult((Expression*)e1,(Expression*)e2));
            //ExprMult* E=new ExprMult((Expression*) expr_arbre,(Expression*) s2);
           // expr_arbre=E;
            cout << "r3 fin : " << endl;
        }
    }
    else if (reductionNum == 5){
        int val = symbolstack.back()->getValeur();
        delete(this->symbolstack.back());
        symbolstack.pop_back();
        delete(this->statestack.back());
        statestack.pop_back();
        cout << "r5 : " << val << endl;
        statestack.back()->transition(*this, new ExprVal(val));
        cout <<"r5 fin" <<endl ;
    }
    else if (reductionNum == 4) {
        cout <<"je suis dans 4"<< endl ;
        int val = -1;
        Symbole* expr;
        for (int i = 0; i < n-1; i++) {
            cout<<"i = " << i <<endl;
            if (i == 1) {
                cout<<"i iciii= " << i <<endl;
                expr =  this -> symbolstack.back();
                symbolstack.pop_back();
               // expr = (Expression*)symbolstack.back();
            }
            cout<<"ou  ici= " <<endl;
            symbolstack.back()->Affiche();
            delete (this->symbolstack.back()); // core dumped ici
            cout<<"ou  ici2 " <<endl;
            symbolstack.pop_back();
            cout<<"laa= " <<endl;
            delete (this->statestack.back());
            cout<<"ou  la= " <<endl;
            statestack.pop_back();
        }
        delete (this->statestack.back());
        cout<<"ou  la= " <<endl;
        statestack.pop_back();
        statestack.back()->transition(*this,new ExprPar((Expression*) expr));
    }
}


int Automate::parcours(Expression* e) {

    if (e!= nullptr) {
        // si Expression empiler type sinon
        if (e->getval()==-1)
        {


        }
        else
        {
            return(e->getval());
        }

    }
    else {
        cout << "pointeur nul" << endl;
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
