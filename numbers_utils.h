#include <stdio.h>
#include <string.h>
#include <math.h> // use -lm : gcc -Wall -o "%e" "%f" -lm

#ifndef NUMBERS_UTILS_H
#define NUMBERS_UTILS_H

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

#endif
