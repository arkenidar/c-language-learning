#include <stdio.h>

int main( int argc, char** argv )
{
    for(int i=0; i<argc; i++)
    {
        printf(" i:{%d} arg:{%s} \n", i, argv[i]);
    }
}
