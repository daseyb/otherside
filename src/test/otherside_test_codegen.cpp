#include "parser_definitions.h"
#include "parser.h"
#include "codegen.h"

int main(int argc, char** argv) {
    Parser parser(argv[1]);

    Program prog;
    if(!parser.Parse(&prog)) {
        return -1;
    }
    
    if (!genCode(argv[2], prog)) {
        return -1;
    }

    return 0;
}