#include<stdio.h>

/*
Program to print char representation of an integer 
*/

void printd(int n){
    if(n<0){
        n=-n;
        putchar('-');
        putchar(' ');
    }
    if(n/10) printd(n/10);
    putchar(n%10+'0');
    putchar(' ');
}

main()
{
    printd(-1213);
    return 0;
}
