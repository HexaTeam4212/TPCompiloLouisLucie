//
// Created by LUCIE BOVO on 20/02/2020.
//

#ifndef TP_EXPRVAL_H
#define TP_EXPRVAL_H


#include "Expression.h"

class ExprVal : public Expression {

public:
    explicit ExprVal(int val) : val(val), Expression() {}

    void display() override;

    int getValue() override;

protected :
    int val;
};


#endif //TP_EXPRVAL_H
