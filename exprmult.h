//
// Created by Louis on 18/02/2020.
//

#ifndef TP_EXPRMULT_H
#define TP_EXPRMULT_H

#include "expr.h"
#include "symbole.h"

class ExprMult : public Expr{
public:

    ExprMult(const Symbole &s1, const Symbole &s2);

private:
    Symbole s1;
    Symbole s2;
};


#endif //TP_EXPRMULT_H
