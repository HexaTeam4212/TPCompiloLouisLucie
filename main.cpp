#include <iostream>
#include "lexer.h"
#include "automate.h"

class Lexer;

int main(void) {
   string chaine("(1+34)*123");

   Automate automate;
   //Lexer l = automate.getLexer();
   Lexer l(chaine);

   Symbole * s = l.Consulter();
   s->Affiche();
//   while(int(*s) != FIN) {
//      s->Affiche();
//      cout<<endl;
//      l.Avancer();
//   }
   return 0;
}

