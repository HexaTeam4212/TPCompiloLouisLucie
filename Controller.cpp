//
// Created by Louis on 18/02/2020.
//
#include "Controller.h"

Controller::Controller(string s) {
    this->lexer.setFlux(s);
    this->lexer.setBuffer(nullptr);
    this->lexer.setHead(0);
    this->accepted = false;
}

void Controller::shift(Symbol* s, State* e){
    this->symbolstack.push_back(s);
    this->statestack.push_back(e);
}
void Controller::reduction(int n, int reductionNumber){
    if (reductionNumber == 2 || reductionNumber == 3){
        Symbol* e1 = this->popSymbol();
        this->popAndDestroySymbol();
        Symbol* e2 = this->popSymbol();
        for (int i=0;i<n;i++)
        {
            delete(statestack.back());
            statestack.pop_back();
        }
        if (reductionNumber == 2){
            statestack.back()->transition(*this, new ExprPlus((Expression*)e1,(Expression*)e2));
        }
        else if (reductionNumber == 3) {
            statestack.back()->transition(*this, new ExprMult((Expression*)e1,(Expression*)e2));
        }
    }
    else if (reductionNumber == 5){
        int val = symbolstack.back()->getValue();
        delete(this->symbolstack.back());
        symbolstack.pop_back();
        delete(this->statestack.back());
        statestack.pop_back();
        statestack.back()->transition(*this, new ExprVal(val));
    }
    else if (reductionNumber == 4) {
        Symbol* expr;
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

Symbol* Controller::popSymbol() {
    Symbol* lastSymbol = symbolstack.back();
    symbolstack.pop_back();
    return lastSymbol;
}

void Controller::popAndDestroySymbol() {
    delete(this->symbolstack.back());
    symbolstack.pop_back();
}

void Controller::pushState(State *s) {
    this->statestack.push_back(s);
}

State* Controller::getTopState() {
    return this->statestack.back();
}

Symbol* Controller::getTopSymbol() {
    return this->symbolstack.back();
}

const Lexer &Controller::getLexer() const {
    return lexer;
}

bool Controller::isAccepted() const {
    return accepted;
}

void Controller::setAccepted(bool accepted) {
    Controller::accepted = accepted;
}
