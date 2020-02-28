
#include "Symbol.h"
#include <iostream>

void Symbol::display() {
   cout << Labels[ident];
}

bool Symbol::isTerminal() {
    if (Labels[this->ident] == "EXPR")
        return false;
    else if (Labels[this->ident] == "ERROR") {
        cout << "erreur symbole" << endl;
        return false;
    }
    else
        return true;
}

int Symbol::getValue() {
    return -1;
}

void Integer::display() {
    Symbol::display();
   cout << "(" << value << ")";
}

int Integer::getValue() {
    return value;
}

