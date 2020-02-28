#include "lexer.h"

Lexer::Lexer() {}

Symbol * Lexer::Consulter() {
   if (!tampon) {
      if (tete==flux.length())
         tampon = new Symbol(END);
      else
      {
         switch (flux[tete]) {
            case '(':
               tampon = new Symbol(OPENPAR);
               tete++;
               break;
            case ')':
               tampon = new Symbol(CLOSEPAR);
               tete++;
               break;
            case '*':
               tampon = new Symbol(MULT);
               tete++;
               break;
            case '+':
               tampon = new Symbol(PLUS);
               tete++;
               break;
            default:
               if (flux[tete]<='9' && flux[tete]>='0') {
                  int resultat = flux[tete]-'0';
                  int i=1;
                  while (flux[tete+i]<='9' && flux[tete+i]>='0') {
                     resultat = resultat*10+(flux[tete+i]-'0');
                     i++;
                  }
                  tete = tete+i;
                  tampon = new Integer(resultat);
               }
               else {
                  tampon = new Symbol(ERROR);
               }
         }
      }
   }
//   else
//       cout << "tampon null" << endl;
   return tampon;
}

void Lexer::Avancer() {
   tampon = nullptr;
}

const string &Lexer::getFlux() const {
    return flux;
}

int Lexer::getTete() const {
    return tete;
}

Symbol *Lexer::getTampon() const {
    return tampon;
}

void Lexer::setFlux(const string &flux) {
    Lexer::flux = flux;
}

void Lexer::setTete(int tete) {
    Lexer::tete = tete;
}

void Lexer::setTampon(Symbol *tampon) {
    Lexer::tampon = tampon;
}
