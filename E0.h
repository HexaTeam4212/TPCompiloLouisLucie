//
// Created by Louis on 18/02/2020.
//

#ifndef TP_E0_H
#define TP_E0_H

#include "automate.h"
#include "state.h"
using namespace std;

class E0: public State {
    bool transition(Automate &automate, Symbole *s);
};


#endif //TP_E0_H
