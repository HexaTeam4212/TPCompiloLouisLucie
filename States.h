//
// Created by Louis on 18/02/2020.
//

#ifndef TP_STATES_H
#define TP_STATES_H

#include <string>
#include <iostream>
#include "Symbol.h"
#include "Automata.h"
using namespace std;

class Automata;
class Symbol;
class State;
class E0;
class E1;
class E2;
class E3;
class E4;
class E5;
class E6;
class E7;
class E8;
class E9;

class State {
public:
    State();
    explicit State(const string& name);
    virtual ~State();
    virtual void print() const;
    virtual bool transition(Automata & automate,
                            Symbol * s) = 0;
};

class E0: public State {
public:
    void print() const override;
    bool transition(Automata &automate, Symbol *s) override ;
};

class E1 : public State {
public:
    void print() const override;
    bool transition(Automata &automate, Symbol *s) override;
};

class E2 : public State {
public:
    void print() const override;
    bool transition(Automata &automate, Symbol *s) override ;
};

class E3 : public State {
public:
    void print() const override;
    bool transition(Automata &automate, Symbol *s) override;

};

class E4 : public State {

public:
    void print() const override;
    bool transition(Automata &automate, Symbol *s) override;

};

class E5 : public State {

public:
    void print() const override;
    bool transition(Automata &automate, Symbol *s) override ;
};

class E6 : public State {

public:
    void print() const override;
    bool transition(Automata &automate, Symbol *s) override ;
};

class E7 : public State {

public:
    void print() const override;
    bool transition(Automata &automate, Symbol *s) override ;
};

class E8 : public State {
public:
    void print() const override;
    bool transition(Automata &automate, Symbol *s) override ;

};

class E9 : public State {

public:
    void print() const override;
    bool transition(Automata &automate, Symbol *s) override;
};

#endif //TP_STATES_H
