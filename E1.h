//
// Created by Louis on 18/02/2020.
//

#ifndef TP_E1_H
#define TP_E1_H

#include "automate.h"
using namespace std;

class E1 : public State {
    bool transition(Automate &automate, Symbole *s);
};


#endif //TP_E1_H
