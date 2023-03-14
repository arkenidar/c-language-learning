
typedef struct _pair{ int x,y; } pair;
pair swap(pair from){ return (pair){ .x=from.y, .y=from.x }; }

#include <stdio.h>
int main(){

    pair to = swap((pair){ .x=1, .y=2 });
    printf(" to: x=%d; y=%d \n", to.x, to.y);

    return 0;
}
