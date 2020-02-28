//
// Created by Louis on 18/02/2020.
//

#ifndef TP_EXPRMULT_H
#define TP_EXPRMULT_H

#include "Symbol.h"
#include "Expression.h"

class ExprMult : public Expression{
public:

    explicit ExprMult(Expression* eg,Expression* ed) : expr_gauche(eg), expr_droit(ed) {}
    ~ExprMult();

    int getValue() override;
    void display() override ;
    Expression* geteg();
    Expression* geted();

private:
    Expression* expr_gauche;
    Expression* expr_droit;

};


#endif //TP_EXPRMULT_H
