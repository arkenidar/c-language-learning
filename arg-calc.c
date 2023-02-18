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

int main( int argc, char** argv )
{
    if(argc != 4) print_usage();
    
    ///for(int i=0; i<argc; i++) printf(" i:{%d} arg:{%s} \n", i, argv[i]);
    
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
