//
// Created by LUCIE BOVO on 27/02/2020.
//

#ifndef TP_EXPRPAR_H
#define TP_EXPRPAR_H

#include "Symbole.h"
#include "Expression.h"
class ExprPar : public Expression {

public:
    explicit ExprPar(Expression* e) : expr(e) {    }
    void Affiche() override;
    int getval() override;

protected :
    Expression* expr;
};


#endif //TP_EXPRPAR_H
