#pragma once


#include <string>
using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPR };

const string Tags[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR", "EXPR" };

class Symbol {
   public:
      Symbol(int i) : ident(i) {  }
      virtual ~Symbol() { }
      operator int() const { return ident; }
      virtual void Display();
      virtual int getValue();
      bool isTerminal();

   protected:
      int ident;
};

class IntValue : public Symbol {
   public:
      IntValue(int v) : Symbol(INT), value(v) { }

      int getValue() override;

      ~IntValue() { }
      void Display() override;
   protected:
      int value;
};

