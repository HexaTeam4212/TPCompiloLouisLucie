//
// Created by Louis on 18/02/2020.
//

#ifndef TP_CONTROLLER_H
#define TP_CONTROLLER_H

#include "Symbol.h"
#include "State.h"
#include "Lexer.h"
#include <vector>
#include <iostream>
#include "ExprPlus.h"
#include "ExprMult.h"
#include "ExprPar.h"
#include "ExprVal.h"

using namespace std;

class Controller {
public:
    Controller(string s);
    void shift(Symbol* s, State* e);
    void reduction(int n, int reductionNum);
    Symbol* popSymbol();
    void popAndDestroySymbol();
    void pushState(State* s);
    State* getTopState();
    Symbol* getTopSymbol();
    bool isAccepted() const;
    void setAccepted(bool accepted);


    const Lexer &getLexer() const;

private:
    vector<Symbol*> symbolstack;
    vector<State*> statestack;
    Lexer lexer;
    bool accepted;
};


#endif //TP_CONTROLLER_H
