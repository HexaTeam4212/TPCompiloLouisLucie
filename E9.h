//
// Created by Louis on 18/02/2020.
//

#ifndef TP_E9_H
#define TP_E9_H
#include "Controller.h"
using namespace std;

class E9 : public State {

public:
    void print() const override;
    bool transition(Controller &automate, Symbol *s) override;
};


#endif //TP_E9_H
