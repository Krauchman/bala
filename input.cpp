#include "input.h"


std::string Input::nxt() {
    printf("-->> ");
    std::string s;
    std::getline(std::cin, s);
    return s;
}
