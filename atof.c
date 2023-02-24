#include "numbers_utils.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
    puts("insert a number (in a line)");
    char line[101];
    int successfully = scanf("%100[^\n]", line);
    if(successfully != 1) { puts("error: insert a number in a line."); return 1; }

    double number = 0;
    // int parse_number(double* parsed, char* line)

    int code = parse_number(&number, line);
    if(code!=0) { printf("parse_number() error code: {%d}", code); return code; }

    ///printf("out: {%f}\n", number);
    printf("out: {"); print_double(number); printf("}\n");

    ///double number2=0; parse_number(&number2, "3.14"); print_double(number2);
}
