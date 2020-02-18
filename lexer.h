#ifndef TP_LEXER_H
#define TP_LEXER_H

#include <string>
#include <iostream>

#include "symbole.h"
using namespace std;

class Lexer {
public:

    Lexer();
    Lexer(string s) : flux(s), tete(0), tampon(nullptr) { }
      ~Lexer() { }

      Symbole * Consulter();
      void Avancer();

    void setFlux(const string &flux);

    void setTete(int tete);

    void setTampon(Symbole *tampon);

    const string &getFlux() const;

    int getTete() const;

    Symbole *getTampon() const;

protected:
      string flux;
      int tete;
      Symbole * tampon;
};

#endif
