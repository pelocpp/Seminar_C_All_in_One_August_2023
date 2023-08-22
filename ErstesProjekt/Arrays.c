#include <stdio.h>  

void array_zum_ersten ()
{
    int zahlen [10];

    zahlen[0] = 123;

    zahlen[3] = 456;

    //VORSICHT

    // [0],  [1], .......  [ 9 ]    

    for (int i = 0; i < 10; ++i) {

        zahlen[i] = 123 + i;
    }

    // oder 

    for (int i = 0; i <= 9; ++i) {

        zahlen[i] = 456 + i;
    }
}

// Nach der Pause: Was ist mit 11 ????????????

