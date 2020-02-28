//
// Created by Louis on 18/02/2020.
//

#ifndef TP_E3_H
#define TP_E3_H
#include "Automata.h"
using namespace std;

class E3 : public State {
public:
    void print() const override;
    bool transition(Automata &automate, Symbole *s) override;

};


#endif //TP_E3_H
