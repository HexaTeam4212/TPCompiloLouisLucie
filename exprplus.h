//
// Created by Louis on 18/02/2020.
//

#ifndef TP_EXPRPLUS_H
#define TP_EXPRPLUS_H

#include "symbole.h"
#include "expr.h"

class ExprPlus : Expr{
public:

    //ExprPlus(const Entier &s1, const Entier &s2); //double addition ça marche ?
    int eval();

private:
    Entier s1;
    Entier s2;
};


#endif //TP_EXPRPLUS_H
