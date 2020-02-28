#pragma once


#include <string>
using namespace std;

enum Identificators { OPENPAR, CLOSEPAR, PLUS, MULT, INT, END, ERROR, EXPR };

const string Labels[] = {"OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "END", "ERROR", "EXPR" };

class Symbol {
   public:
      explicit Symbol(int i) : ident(i) {  }
      virtual ~Symbol() = default;
      operator int() const { return ident; }
      virtual void display();
      virtual int getValue();
      bool isTerminal();

   protected:
      int ident;
};

class Integer : public Symbol {
   public:
      explicit Integer(int v) : Symbol(INT), value(v) { }
      int getValue() override;

      void display() override;
   protected:
      int value;
};

