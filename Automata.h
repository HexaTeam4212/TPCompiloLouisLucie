//
// Created by Louis on 18/02/2020.
//

#ifndef TP_AUTOMATA_H
#define TP_AUTOMATA_H

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

class Automata {
public:
    Automata(string s);
    void decalage(Symbole* s, State* e);
    void reduction(int n, int reductionNum);
    Symbole* popSymbol();
    void popAndDestroySymbol();
    void pushState(State* s);
    State* getTopState();
    Symbole* getTopSymbole();
    void printSymbolStack();
    void printStateStack();

    bool isAccept() const;

    void setAccept(bool newAccept);


    const Lexer &getLexer() const;

private:
    vector<Symbole*> symbolstack;
    vector<State*> statestack;
    Lexer lexer;
    bool accept;
};


#endif //TP_AUTOMATA_H
