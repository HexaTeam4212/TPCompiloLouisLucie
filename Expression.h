//
// Created by LUCIE BOVO on 20/02/2020.
//

#ifndef TP_EXPRESSION_H
#define TP_EXPRESSION_H


#include <iostream>
#include "symbole.h"

using namespace std;

class Expression : public Symbole {
public:
    explicit Expression(Expression* eg,Expression* ed) : Symbole(EXPR), expr_gauche(eg), expr_droit(ed) {
        cout << "ici"<<endl;
    }
    explicit Expression() : Symbole(EXPR) {}

    ~Expression() override = default;

    Expression* geteg();
    Expression* geted();
    virtual int getval();

    virtual void Affiche() override;

protected:
    Expression* expr_gauche;
    Expression* expr_droit;
    int val;
};




#endif //TP_EXPRESSION_H
