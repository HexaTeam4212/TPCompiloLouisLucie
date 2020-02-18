//
// Created by Louis on 18/02/2020.
//

#ifndef TP_EXPR_H
#define TP_EXPR_H
#include "symbole.h"
#include <iostream>

using namespace std;

class Expr : public Symbole {
public:
    explicit Expr(int val):Symbole(EXPR), val(val) {}
    ~Expr() override = default;

    void Affiche() override;

    int getVal() const;

    void setVal(int val);
//    virtual int eval();
protected:
    int val;
};


#endif //TP_EXPR_H
