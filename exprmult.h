//
// Created by Louis on 18/02/2020.
//

#ifndef TP_EXPRMULT_H
#define TP_EXPRMULT_H

#include "symbole.h"
#include "Expression.h"

class ExprMult : public Expression{
public:

    explicit ExprMult(Expression* eg,Expression* ed) : Expression(eg,ed) {}

    int getval() override;

    void Affiche() ;

    // ExprMult(const Symbole &s1, const Symbole &s2);

private:
};


#endif //TP_EXPRMULT_H
