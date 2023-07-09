
// source: https://github.com/arkenidar/sdl2-gl/blob/main/parse.h
char* next_int(const char* next,int* out){
    int number=0;
    int sign=1; if(*next=='-'){ sign=-1; next++; }
    for(; *next>='0' && *next<='9'; next++){
        int digit=*next-'0';
        number*=10; number+=digit;
    }
    number*=sign;
    *out=number; return (char*)next;
}
// source: https://github.com/arkenidar/sdl2-gl/blob/main/parse.h
char* next_float(const char* next,float* out){
    float number=0; int dot=-1;
    int sign=1; if(*next=='-'){ sign=-1; next++; }
    for(; *next=='.' || (*next>='0' && *next<='9'); next++){
        if(*next=='.'){ dot=0; continue; } if(dot>=0) dot++;
        int digit=*next-'0';
        number*=10; number+=digit;
    }
    while(0<dot--)number/=10;
    number*=sign;
    *out=number; return (char*)next;
}
//=======================

#include <string.h>

// source: https://github.com/arkenidar/c-language-learning/blob/master/numbers_utils.h
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

#include <stdio.h>

// source: https://github.com/arkenidar/c-language-learning/blob/master/numbers_utils.h
void print_double(double number){
    char buffer[100];
    sprintf(buffer,"%f",number);
    remove_excess_zeroes(buffer);
    printf("%s",buffer);
}

//=======================
// source: added, derived from print_double() in numbers_utils.h
// source: https://github.com/arkenidar/sdl2-gl/blob/main/numbers.c
char* print_double_to_string(double number){
    static char buffer[100];
    sprintf(buffer,"%f",number);
    remove_excess_zeroes(buffer);
    //printf("%s",buffer);
    return buffer;
}

//=======================
// source: https://github.com/arkenidar/sdl2-gl/blob/main/parse.h
void test_numbers(){
    puts("test_numbers()\n");

    int out_int;
    next_int("-1234",&out_int);
    printf("out_int: [[%d]]\n",out_int);

    float out_float;
    next_float("-12.34",&out_float);
    printf("out_float: [[%f]]\n",out_float);

    // source: added to https://github.com/arkenidar/sdl2-gl/blob/main/numbers.c
    printf("out_float: [[%s]]\n",print_double_to_string(out_float));

    puts("");
}

//=======================

int main(){
    test_numbers();
}
