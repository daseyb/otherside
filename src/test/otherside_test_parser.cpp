#include "parser_definitions.h"
#include "parser.h"

int main(int argc, char** argv) {
    Parser parser(argv[1]);

    Program prog;
    if(!parser.ParseProgram(&prog)) {
        return -1;
    }

    return 0;
}