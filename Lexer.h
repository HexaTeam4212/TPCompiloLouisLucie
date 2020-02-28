#ifndef TP_LEXER_H
#define TP_LEXER_H

#include <string>
#include <iostream>
#include "Symbol.h"
using namespace std;

class Lexer {
public:

    Lexer();
    ~Lexer() = default;

      Symbol * Consult();
      void Advance();

    void setStream(const string &newStream);

    void setHead(int newHead);

    void setTampon(Symbol *newBuffer);

    const string &getStream() const;

    int getHead() const;

    Symbol *getBuffer() const;

protected:
      string stream;
      int head{};
      Symbol * buffer{};
};

#endif
