#include "numbers_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> // use -lm : gcc -Wall -o "%e" "%f" -lm

void print_usage(){
    char * usage = "use with: arg-calc {number} {+|-|*|/|//|%|^} {number}";
    puts(usage);
    exit(1);
}

char* skip_spaces(char* cursor){
    while(1){
        if(cursor[0]== '\0' ) break;
        if(cursor[0]!= ' ' ) break;
        cursor++;
    }
    return cursor;
}

int line_main( int argc, char** argv );

int main( int argc, char** argv )
{
    if(argc<=1)
    {
        while(1)
        {
            line_main( argc, argv );
        }
    }
    else
    {
        return line_main( argc, argv );
    }
    return 0;
}

int line_main( int argc, char** argv )
{
    if(argc<=1){
        char line[101];
        int count=1;
        char* vector[100]={0};

        puts("insert a line to calculate"); int successfully = scanf("%100[^\n]", line);
        // flushes the standard input
        // (clears the input buffer)
        while ((getchar()) != '\n');
        if(successfully != 1) print_usage();

        puts(line);
        char* cursor = line;
        cursor = skip_spaces(cursor);
        char* previous = cursor;
        while(1){
            if(cursor[0] == ' ' || cursor[0] == '\0' ){
                vector[count] = previous;
                count++;
                char* end = cursor;
                cursor = skip_spaces(cursor);
                previous = cursor;
                int is_terminated = end[0]== '\0' ? 1 : 0;
                end[0]='\0';
                if(is_terminated || count >= (sizeof(vector)/sizeof(char*)) ) break;
            }
            cursor++;
        }
        argc = count;
        argv = vector;
    }

    printf("argc: %d\n", argc);
    for(int i=1; i<argc; i++) printf(" i:{%d} arg:{%s} \n", i, argv[i]);

    if(argc %2==1 ) print_usage();

    ///double x=atof(argv[1]);
    double x=0; parse_number(&x, argv[1]);
    for(int i=2; (i+1)<argc; i+=2){

        char* operator = argv[i];
        ///double y=atof(argv[i+1]);
        double y=0; parse_number(&y, argv[i+1]);

        print_double(x); printf(" %s ",operator); print_double(y); puts("");

             if(0==strcmp(operator, "+" )) x = x + y;
        else if(0==strcmp(operator, "-" )) x = x - y;
        else if(0==strcmp(operator, "*" )) x = x * y;
        else if(0==strcmp(operator, "/" )) x = x / y;
        else if(0==strcmp(operator, "//")) x = trunc(x / y);
        else if(0==strcmp(operator, "%" )) x = (long)trunc(x) % (long)trunc(y);
        else if(0==strcmp(operator, "^" )) x = pow(x , y);
        else { printf("unrecognized operator: {%s}\n", operator); print_usage(); }
    }

    printf("result: "); print_double(x); puts("");

    return 0;
}
