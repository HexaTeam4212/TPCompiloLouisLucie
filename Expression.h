//
// Created by LUCIE BOVO on 20/02/2020.
//

#ifndef TP_EXPRESSION_H
#define TP_EXPRESSION_H


#include <iostream>
#include "Symbole.h"

using namespace std;

class Expression : public Symbole {
public:
    explicit Expression() : Symbole(EXPR) {}

    ~Expression() override = default;

    virtual int getval();

    virtual void Affiche() override;

protected:

};




#endif //TP_EXPRESSION_H
