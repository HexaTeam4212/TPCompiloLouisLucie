//
// Created by LUCIE BOVO on 20/02/2020.
//

#ifndef TP_EXPRESSION_H
#define TP_EXPRESSION_H

#include <iostream>
#include "Symbol.h"
using namespace std;

class Expression : public Symbol {
public:
    explicit Expression() : Symbol(EXPR) {}

    virtual int getval();

    virtual void display() override;

protected:

};




#endif //TP_EXPRESSION_H
