//
// Created by Louis on 18/02/2020.
//

#ifndef TP_E4_H
#define TP_E4_H
#include "automate.h"
using namespace std;

class E4 : public State {

public:
    void print() const override;
    bool transition(Automate &automate, Symbole *s) override;

};


#endif //TP_E4_H
