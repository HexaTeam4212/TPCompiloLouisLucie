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
    Lexer(string s) : flux(s), head(0), buffer(nullptr) { } //non utilisé
      ~Lexer() { }

      Symbol * Read();
      void Progress();

    void setFlux(const string &flux);

    void setHead(int head);

    void setBuffer(Symbol *tampon);

    const string &getFlux() const;

    int getHead() const;

    Symbol *getTampon() const;

protected:
      string flux;
      int head;
      Symbol * buffer;
};

#endif
