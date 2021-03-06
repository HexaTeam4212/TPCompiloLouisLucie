//
// Created by Louis on 18/02/2020.
//

#ifndef TP_AUTOMATA_H
#define TP_AUTOMATA_H

#include "Symbol.h"
#include "States.h"
#include "Lexer.h"
#include <vector>
#include <iostream>
#include "ExprPlus.h"
#include "ExprMult.h"
#include "ExprPar.h"
#include "ExprVal.h"

using namespace std;

class State;

class Automata {
public:
    Automata(string s);
    virtual ~Automata();
    void shift(Symbol* s, State* e);
    void reduction(int n, int reductionNum);
    Symbol* popSymbol();
    void popAndDestroySymbol();
    void pushState(State* s);
    State* getTopState();
    Symbol* getTopSymbol();
//    void printSymbolStack();
//    void printStateStack();

    bool isAccept() const;

    void setAccept(bool newAccept);


    const Lexer &getLexer() const;

private:
    vector<Symbol*> symbolstack;
    vector<State*> statestack;
    Lexer lexer;
    bool accept;
};


#endif //TP_AUTOMATA_H
