//
// Created by Louis on 18/02/2020.
//

#ifndef TP_EXPRPLUS_H
#define TP_EXPRPLUS_H

#include "Expression.h"

class ExprPlus : public Expression{
public:

    explicit ExprPlus(Expression* eleft,Expression* eright) : expr_left(eleft), expr_right(eright) {}
    void Display();
    int getval() override;
    Expression* geteleft();
    Expression* geteright();

private:
    Expression* expr_left;
    Expression* expr_right;
};


#endif //TP_EXPRPLUS_H
