#include <iostream>
#include "Lexer.h"
#include "Controller.h"
#include "E0.h"

class Lexer;

int main(void) {

    string chaine;

    cout << "Please enter an expresssion to evaluate" << endl;
    cin >> chaine;

    Controller controller(chaine);
    Lexer l = controller.getLexer();
    Symbol *s = l.Read();
    State *e = new E0();
    controller.pushState(e);

    cout << "top state ";
    controller.getTopState()->print();
    cout << endl;

    while (!controller.isAccepted()) {
        cout << endl;
       if (!e->transition(controller, s))
           l.Progress();
        e = controller.getTopState();
        cout << "top symbol ";
        controller.getTopSymbol()->Display();
        cout << endl;
        cout << "top state ";
        controller.getTopState()->print();
        cout << endl;
        s = l.Read();
    }

   cout << ((Expression*)controller.getTopSymbol())->getval() << endl;
    return 0;
}

