//
// Created by Louis on 18/02/2020.
//

#ifndef TP_E6_H
#define TP_E6_H
#include "Automate.h"
using namespace std;

class E6 : public State {

public:
    void print() const override;
    bool transition(Automate &automate, Symbole *s) override ;
};


#endif //TP_E6_H
