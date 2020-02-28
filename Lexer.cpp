#include "Lexer.h"

Lexer::Lexer() = default;

Symbol * Lexer::Consult() {
   if (!buffer) {
      if (head == stream.length())
          buffer = new Symbol(END);
      else
      {
         switch (stream[head]) {
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
               if (stream[head] <= '9' && stream[head] >= '0') {
                  int result = stream[head] - '0';
                  int i=1;
                  while (stream[head + i] <= '9' && stream[head + i] >= '0') {
                      result = result * 10 + (stream[head + i] - '0');
                     i++;
                  }
                   head = head + i;
                   buffer = new Integer(result);
               }
               else {
                   buffer = new Symbol(ERROR);
               }
         }
      }
   }
   return buffer;
}

void Lexer::Advance() {
    buffer = nullptr;
}

const string &Lexer::getStream() const {
    return stream;
}

int Lexer::getHead() const {
    return head;
}

Symbol *Lexer::getBuffer() const {
    return buffer;
}

void Lexer::setStream(const string &newStream) {
    Lexer::stream = newStream;
}

void Lexer::setHead(int newHead) {
    Lexer::head = newHead;
}

void Lexer::setTampon(Symbol *newBuffer) {
    Lexer::buffer = newBuffer;
}
