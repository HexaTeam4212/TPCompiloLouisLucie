//
// Created by Louis on 18/02/2020.
//

#ifndef TP_EXPR_H
#define TP_EXPR_H
#include "symbole.h"

using namespace std;

class Expr : public Symbole {
public:
    Expr():Symbole(EXPR) {}
    virtual ~Expr() {}
//    virtual int eval();
};


#endif //TP_EXPR_H
