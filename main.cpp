#include <iostream>
#include "lexer.h"
#include "automate.h"

class Lexer;

int main(void) {
   string chaine("(1+34)*123"); // TODO: remplacer par user input

   Automate automate(chaine);
   Lexer l = automate.getLexer();
   Symbole * s = l.Consulter();

   while(*s != FIN) {
      s->Affiche();
      cout << endl;
      l.Avancer();
      s = l.Consulter();
   }

   cout << "state stack" << endl;
   automate.printStateStack();
   cout << "symbol stack" << endl;
   automate.printSymbolStack();

   return 0;
}

