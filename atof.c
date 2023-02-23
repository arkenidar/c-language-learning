#include <stdio.h>
#include <string.h>
#include <math.h>

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

int parse_number(double* parsed, char* line){
    int string_length = strlen(line);
    ///printf("string_length: {%d}\n", string_length);
    if(string_length < 1) return 2;

    double out = 0;
    int parsable = 1;
    int minus = 0;
    int dot_index = -1;
    int index;
    for( index = 0; index < string_length; index++ ){
        char character = line[index];

        if(index==0 && character=='-') minus = 1;
        else
        if(character>='0' && character<='9'){
            int digit = character - '0';
            out = out * 10;
            out = out + digit;
        }
        else
        if(character=='.' && dot_index == -1 && index>0){
            dot_index = index;
        }
        else{
            printf("invalid character: {%c}\n", character);
            puts("exiting...");
            parsable = 0;
            break;
        }
    }
    if(minus) out = -out;
    if( dot_index != -1 ){
        int places = index - 1 - dot_index;
        ///printf("places: {%d}\n", places);
        out = out / pow(10, places);
    }
    if(!parsable){ puts("not parsable"); return 1; }

    *parsed = out;

    ///printf("out: {%f}\n", out);
    ///printf("out: {"); print_double(out); printf("}\n");

    return 0;
}

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
