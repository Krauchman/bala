#include <bits/stdc++.h>

#include "input.h"
#include "lexer.h"
// #include "parser.h"


int main() {
    while (true) {
        std::string s;
        try {
            s = Input::nxt();
        }
        catch (...) {
            printf("Input has failed.\n");
            continue;
        }

        std::vector <Lexer::Token> tokens;
        try {
            tokens = Lexer::processString(s);
        }
        catch (...) {
            printf("Input proccessing has failed.\n");
            continue;
        }

        for (auto token : tokens) {
            std::cout << "<" << int(token.type) << ", " << token.value << "> ";
        }
        printf("\n");
        
        // Parser::Node* root = nullptr;
        // try {
        //     root = Parser::buildFromTokens(tokens);
        // }
        // catch (...) {
        //     printf("Parsing has failed.\n");
        //     continue;
        // }

        // try {
        //     root.execute();
        // }
        // catch (...) {
        //     printf("Command execution failed.\n");
        //     continue;
        // }
    }
}