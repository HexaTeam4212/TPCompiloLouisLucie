//
// Created by Louis on 18/02/2020.
//

#ifndef TP_EXPRPLUS_H
#define TP_EXPRPLUS_H

#include "symbole.h"

class ExprPlus {
public:

    ExprPlus(const Symbole &s1, const Symbole &s2);
    int eval();

private:
    Symbole s1;
    Symbole s2;
};


#endif //TP_EXPRPLUS_H
