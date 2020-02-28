#include <iostream>
#include "Lexer.h"
#include "Automata.h"

class Lexer;

int main() {
    string chaine;

    cout << "Please enter an expresssion to evaluate" << endl;
    cin >> chaine;

    Automata automate(chaine);
    Lexer l = automate.getLexer();
    Symbol *s = l.Consult();
    State *e = new E0();
    automate.pushState(e);

    cout << "top state ";
    automate.getTopState()->print();
    cout << endl;

    while (!automate.isAccept()) {
        cout << endl;
       if (!e->transition(automate, s))
           l.Advance();
        e = automate.getTopState();
        cout << "top symbol ";
        automate.getTopSymbole()->display();
        cout << endl;
        cout << "top state ";
        automate.getTopState()->print();
        cout << endl;
        s = l.Consult();
    }

   cout << ((Expression*)automate.getTopSymbole())->getval() << endl;
    return 0;
}

