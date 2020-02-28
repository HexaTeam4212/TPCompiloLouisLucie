//
// Created by Louis on 18/02/2020.
//

#ifndef TP_EXPRPLUS_H
#define TP_EXPRPLUS_H

#include "Symbol.h"
#include "Expression.h"

class ExprPlus : public Expression{
public:

    explicit ExprPlus(Expression* eg,Expression* ed) : expr_gauche(eg), expr_droit(ed) {}
    ~ExprPlus();

    void display();
    int getValue() override;
    Expression* geteg();
    Expression* geted();

private:
    Expression* expr_gauche;
    Expression* expr_droit;
};


#endif //TP_EXPRPLUS_H
