#include <iostream>
#include "lexer.h"
#include "Automata.h"
#include "E0.h"

class Lexer;

int main(void) {
    string chaine;

    cout << "Please enter an expresssion to evaluate" << endl;
    cin >> chaine;

    Automata automate(chaine);
    Lexer l = automate.getLexer();
    Symbole *s = l.Consulter();
    State *e = new E0();
    automate.pushState(e);

    cout << "top state ";
    automate.getTopState()->print();
    cout << endl;

    while (!automate.isAccept()) {
        cout << endl;
       if (!e->transition(automate, s))
           l.Avancer();
        e = automate.getTopState();
        cout << "top symbol ";
        automate.getTopSymbole()->Affiche();
        cout << endl;
        cout << "top state ";
        automate.getTopState()->print();
        cout << endl;
        s = l.Consulter();
    }

   cout << ((Expression*)automate.getTopSymbole())->getval() << endl;
    return 0;
}

