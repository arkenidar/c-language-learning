#include <stdio.h>
typedef struct _pair{ int x,y; } pair; // define "pair"
pair swap(pair from){ // not necessarily defined (one life suffices)
    pair to={ .x=from.y, .y=from.x }; // init "to" pair
    return to;
}
int main(){
    pair to = swap((pair){ .x=1, .y=2 }); // swap and assign
    printf(" to: x=%d; y=%d \n", to.x, to.y); // print results
    return 0;
}
