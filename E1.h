//
// Created by Louis on 18/02/2020.
//

#ifndef TP_E1_H
#define TP_E1_H

#include "Automata.h"
using namespace std;

class E1 : public State {

public:
    void print() const override;
    bool transition(Automata &automate, Symbol *s) override;
};


#endif //TP_E1_H
