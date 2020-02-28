//
// Created by Louis on 18/02/2020.
//

#ifndef TP_STATE_H
#define TP_STATE_H

#include <string>
#include <iostream>
#include "Symbol.h"
using namespace std;

class Controller;

class State {
public:
    State();
    explicit State(string name);
    virtual ~State();
    virtual void print() const;
    virtual bool transition(Controller & automate,
                            Symbol * s) = 0;
protected:
    string name;
};


#endif //TP_STATE_H
