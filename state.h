//
// Created by Louis on 18/02/2020.
//

#ifndef TP_STATE_H
#define TP_STATE_H

using namespace std;

class Automate;

class State {
public:
    State();
    State(string name);
    virtual ~State();
    void print() const;
    virtual bool transition(Automate & automate,
                            Symbole * s) = 0;
protected:
    string name;
};


#endif //TP_STATE_H
