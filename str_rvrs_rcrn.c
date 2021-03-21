/*
Exercise 4-13. Write a recursive version of the function reverse(s), which reverses the
string s in place.
*/

#include <stdio.h>

void reverse(char *s){
    if(*s=='\0') return;
    reverse(s+1);
    putchar(*s);
}

main()
{
    char s[]="jumping fox";
    reverse(s);
}

