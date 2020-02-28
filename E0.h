//
// Created by Louis on 18/02/2020.
//

#ifndef TP_E0_H
#define TP_E0_H

#include "Automata.h"
#include "States.h"
using namespace std;

class E0: public State {
public:
    void print() const override;
    bool transition(Automata &automate, Symbole *s) override ;
};


#endif //TP_E0_H
