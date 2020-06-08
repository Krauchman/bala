#ifndef LEXER_H
#define LEXER_H

#include <bits/stdc++.h>


namespace Lexer {

    class Token {
      public:
        enum class Type {CONST, OBJ};
        Type type;
        std::string value;

        Token(Type _type, std::string _value);
    };

    std::vector <Token> processString(std::string s);

}

#endif