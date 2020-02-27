//
// Created by Louis on 18/02/2020.
//

#ifndef TP_E2_H
#define TP_E2_H
#include "Automate.h"
using namespace std;

class E2 : public State {
public:
    void print() const override;
    bool transition(Automate &automate, Symbole *s) override ;
};


#endif //TP_E2_H
