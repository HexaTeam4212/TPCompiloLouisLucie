//
// Created by Louis on 18/02/2020.
//

#ifndef TP_EXPRPLUS_H
#define TP_EXPRPLUS_H

#include "symbole.h"
#include "Expression.h"

class ExprPlus : public Expression{
public:

    //ExprPlus(const Entier &s1, const Entier &s2); //double addition ça marche ?
    explicit ExprPlus(Expression* eg,Expression* ed) : Expression(eg,ed) {}

    void Affiche();

    int getval() override;

private:
};


#endif //TP_EXPRPLUS_H
