//
// Created by Louis on 18/02/2020.
//

#ifndef TP_STATE_H
#define TP_STATE_H

#include <string>
#include "symbole.h"
using namespace std;

class Automate;

class State {
public:
    State();
    State(string name);
    virtual ~State();
    void print() const;
    virtual bool transition(Automate & automate,
                            Symbole * s);
protected:
    string name;
};


#endif //TP_STATE_H
