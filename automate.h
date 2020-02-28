//
// Created by Louis on 18/02/2020.
//

#ifndef TP_AUTOMATE_H
#define TP_AUTOMATE_H

#include "Symbole.h"
#include "States.h"
#include "lexer.h"
#include <vector>
#include <iostream>
#include "ExprPlus.h"
#include "ExprMult.h"
#include "ExprPar.h"
#include "ExprVal.h"

using namespace std;

class Automate {
public:
    Automate(string s);
    void decalage(Symbole* s, State* e);
    void reduction(int n, int reductionNum);
    Symbole* popSymbol();
    void popAndDestroySymbol();
    void pushState(State* s);
    State* getTopState();
    Symbole* getTopSymbole();
    void printSymbolStack();
    void printStateStack();

    bool isAccepter() const;

    void setAccepter(bool accepter);


    const Lexer &getLexer() const;

private:
    vector<Symbole*> symbolstack;
    vector<State*> statestack;
    Expression* expr_arbre;
    Lexer lexer;
    bool accepter;
};


#endif //TP_AUTOMATE_H
