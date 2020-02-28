
#include "Symbol.h"
#include <iostream>

void Symbol::Display() {
    cout << Tags[ident];
}

bool Symbol::isTerminal() {
    if (Tags[this->ident] == "EXPR")
        return false;
    else if (Tags[this->ident] == "ERREUR") {
        cout << "erreur symbole" << endl;
        return false;
    } else
        return true;
}

int Symbol::getValue() {
    return -1;
}

void IntValue::Display() {
    Symbol::Display();
    cout << "(" << value << ")";
}

int IntValue::getValue() {
    return value;
}

