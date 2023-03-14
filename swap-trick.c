#include <stdio.h>

struct pair{ int x,y; }; // define "pair"
struct pair swap(struct pair from){ // not necessarily defined (one life suffices)
    struct pair to={ .x=from.y, .y=from.x }; // init "to" pair
    return to;
}

int main(){

    struct pair from={ .x=1, .y=2 }; // init "from" pair
    struct pair to = swap(from); // swap and assign
    printf(" to: x=%d; y=%d \n", to.x, to.y); // print results
    return 0;
}

/*
$ ./swap-trick 
 to: x=2; y=1 
*/
