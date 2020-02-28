#ifndef TP_LEXER_H
#define TP_LEXER_H

//#define nullptr NULL

#include <string>
#include <iostream>
#include "Symbol.h"
using namespace std;

class Lexer {
public:

    Lexer();
    Lexer(string s) : flux(s), tete(0), tampon(nullptr) { } //non utilisé
      ~Lexer() { }

      Symbol * Consulter();
      void Avancer();

    void setFlux(const string &flux);

    void setTete(int tete);

    void setTampon(Symbol *tampon);

    const string &getFlux() const;

    int getTete() const;

    Symbol *getTampon() const;

protected:
      string flux;
      int tete;
      Symbol * tampon;
};

#endif
