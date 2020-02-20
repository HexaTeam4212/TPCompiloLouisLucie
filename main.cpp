#include <iostream>
#include "lexer.h"
#include "automate.h"
#include "E0.h"

class Lexer;

int main(void) {
//    string chaine("(1+34)*123"); // TODO: remplacer par user input
    string chaine("1+2"); // TODO: remplacer par user input

    Automate automate(chaine);
    Lexer l = automate.getLexer();
    Symbole *s = l.Consulter();
    State *e = new E0();
    automate.pushState(e);

    cout << "top state ";
    automate.getTopState()->print();
    cout << endl;

    while (!automate.isAccepter()) {

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

    cout << "state stack" << endl;
    automate.printStateStack();
    cout << "symbol stack" << endl;
    automate.printSymbolStack();

    return 0;
}

