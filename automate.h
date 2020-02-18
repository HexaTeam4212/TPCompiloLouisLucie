//
// Created by Louis on 18/02/2020.
//

#ifndef TP_AUTOMATE_H
#define TP_AUTOMATE_H

#include "symbole.h"
#include "state.h"
#include "lexer.h"
#include <vector>
#include <iostream>
#include "exprplus.h"
#include "exprmult.h"

using namespace std;

class Automate {
public:
    Automate(string s);
    void decalage(Symbole* s, State* e);
    void reduction(int n, Symbole* s);
    void reduction(int n, bool addOrMult);
    Symbole popSymbol();
    void popAndDestroySymbol();
    State* getTopState();
    void printSymbolStack();
    void printStateStack();

    const Lexer &getLexer() const;

private:
    vector<Symbole> symbolstack;
    vector<State*> statestack;
    Lexer lexer;
};


#endif //TP_AUTOMATE_H
