#include "numbers_utils.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){
    puts("insert a number (in a line)");
    char line[101];
    int successfully = scanf("%100[^\n]", line);
    ///if(successfully != 1) { puts("error: insert a number in a line."); return EXIT_FAILURE; }
    if(successfully != 1) strcpy(line,"");
    printf("line: {%s}\n", line);

    double number = 0;
    // int parse_number(double* parsed, char* line)

    int code = parse_number(&number, line);
    if(code != PARSE_NUMBER_SUCCESS) { printf("parse_number() error code: {%d}\n", code);
        if(code >= 0){ printf("parse number error, invalid character: {%c}\n", line[code]); }
        else if(code == PARSE_NUMBER_EMPTY_STRING) puts("parse number error: empty string.");
        return EXIT_FAILURE; }

    ///printf("out: {%f}\n", number);
    printf("out: {"); print_double(number); printf("}\n");

    ///double number2=0; parse_number(&number2, "3.14"); print_double(number2);

    return EXIT_SUCCESS;
}
