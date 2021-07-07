#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <conio.h>
#include <math.h>

int fonk1(int *a)
{
    *a=200;
    return 0;
}


int main()
{

    int x;
    x=60;
    fonk1(&x);
    printf("%d", x);
}
