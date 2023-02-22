#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> // use -lm : gcc -Wall -o "%e" "%f" -lm

void remove_excess_zeroes(char* buffer){
    for(int index = strlen(buffer)-1; 1 ; index -= 1){
        if(buffer[index]=='.'){
            buffer[index] = '\0';
            break;
        }else if(buffer[index]=='0'){
            buffer[index] = '\0';
        }else break;
    }
}

void print_double(double number){
    char buffer[100];
    sprintf(buffer,"%f",number);
    remove_excess_zeroes(buffer);
    printf("%s",buffer);
}

void print_usage(){
    char * usage = "use with: arg-calc {number} {+|-|.|/|//|^} {number}";
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
        char* vector[4]={0};
        
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
                if(is_terminated || count>=4) break;
            }
            cursor++;
        }
        argc = count;
        argv = vector;
    }

    printf("argc: %d\n", argc);
    for(int i=1; i<argc; i++) printf(" i:{%d} arg:{%s} \n", i, argv[i]);

    if(argc != 4) print_usage();

    char* operator = argv[2];
    double x=atof(argv[1]),y=atof(argv[3]);

    ///printf("%f %s %f\n", x, operator, y);
    print_double(x); printf(" %s ",operator); print_double(y); puts("");

    double result=0;

    if(strcmp(operator,"+")==0) result = x + y;
    else if(strcmp(operator,"-")==0) result = x - y;
    else if(strcmp(operator,".")==0) result = x * y;
    else if(strcmp(operator,"/")==0) result = x / y;
    else if(strcmp(operator,"//")==0) result = trunc(x / y);
    else if(strcmp(operator,"^")==0) result = pow(x , y);
    else { printf("unrecognized operator: {%s}\n", operator);
        print_usage(); }

    printf("result: "); print_double(result); puts("");

    return 0;
}
