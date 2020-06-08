#include "lexer.h"


Lexer::Token::Token(Type _type, std::string _value) : type(_type), value(_value) {}

enum class CharType {DIGIT, LETTER, SPACE, OTHER};

CharType getTypeOf(char c) {
    if ('0' <= c && c <= '9') return CharType::DIGIT;
    if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) return CharType::LETTER;
    if (std::isspace(c)) return CharType::SPACE;
    return CharType::OTHER;
}

std::string readSequence(const std::string& s, size_t& i, std::set <CharType> good) {
    std::string res = "";
    while (i < s.size() && good.find(getTypeOf(s[i])) != good.end()) {
        res += s[i];
        ++i;
    }
    
    return res;
}

std::vector <Lexer::Token> Lexer::processString(std::string s) {
    std::vector <Lexer::Token> res;
    
    size_t i = 0;
    while (i < s.size()) {
        char ch = s[i];
        switch (getTypeOf(ch)) {
            case CharType::DIGIT:
                res.emplace_back(Lexer::Token::Type::CONST, readSequence(s, i, {CharType::DIGIT}));
                break;
            case CharType::LETTER:
                res.emplace_back(Lexer::Token::Type::OBJ, readSequence(s, i, {CharType::LETTER, CharType::DIGIT}));
                break;
            case CharType::SPACE:
                ++i;
                break;
            default: // CharType::OTHER
                printf("Syntax error: invalid symbol.\n");
                throw std::exception();
        }
    }

    return res;
}
