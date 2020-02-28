//
// Created by Louis on 18/02/2020.
//

#ifndef TP_EXPRMULT_H
#define TP_EXPRMULT_H


#include "Expression.h"

class ExprMult : public Expression{
public:

    explicit ExprMult(Expression* eleft,Expression* eright) : expr_left(eleft), expr_right(eright) {}
    int getval() override;
    void Display() ;

private:
    Expression* expr_left;
    Expression* expr_right;

};


#endif //TP_EXPRMULT_H
