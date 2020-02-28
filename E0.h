//
// Created by Louis on 18/02/2020.
//

#ifndef TP_E0_H
#define TP_E0_H

#include "Controller.h"
#include "State.h"
using namespace std;

class E0: public State {
public:
    void print() const override;
    bool transition(Controller &automate, Symbol *s) override ;
};


#endif //TP_E0_H
