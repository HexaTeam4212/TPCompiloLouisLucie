#include "Lexer.h"

Lexer::Lexer() {}

Symbol * Lexer::Read() {
   if (!buffer) {
      if (head==flux.length())
         buffer = new Symbol(FIN);
      else
      {
         switch (flux[head]) {
            case '(':
               buffer = new Symbol(OPENPAR);
               head++;
               break;
            case ')':
               buffer = new Symbol(CLOSEPAR);
               head++;
               break;
            case '*':
               buffer = new Symbol(MULT);
               head++;
               break;
            case '+':
               buffer = new Symbol(PLUS);
               head++;
               break;
            default:
               if (flux[head]<='9' && flux[head]>='0') {
                  int resultat = flux[head]-'0';
                  int i=1;
                  while (flux[head+i]<='9' && flux[head+i]>='0') {
                     resultat = resultat*10+(flux[head+i]-'0');
                     i++;
                  }
                  head = head+i;
                  buffer = new IntValue(resultat);
               }
               else {
                  buffer = new Symbol(ERREUR);
               }
         }
      }
   }
   return buffer;
}

void Lexer::Progress() {
   buffer = nullptr;
}

const string &Lexer::getFlux() const {
    return flux;
}

int Lexer::getHead() const {
    return head;
}

Symbol *Lexer::getTampon() const {
    return buffer;
}

void Lexer::setFlux(const string &flux) {
    Lexer::flux = flux;
}

void Lexer::setHead(int head) {
    Lexer::head = head;
}

void Lexer::setBuffer(Symbol *buffer) {
    Lexer::buffer = buffer;
}
