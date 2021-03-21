/*
The ungetch() function pushes the character specified by c back onto the input stream for the console. 
This character will be returned by the next read from the console (with getch() or getche() functions 
and will be detected by the function kbhit(). Only the last character returned in this way is remembered.
The ungetch() function clears the end-of-file indicator, unless the value of c is EOF.

ungetch puts the pushed-back characters into a shared
buffer -- a character array. getch reads from the buffer if there is anything else, and calls
getchar if the buffer is empty.
*/
#include <stdio.h>
#include <ctype.h>

void main()
  {
    int c;
    long value;

    value = 0;
    c = getche();
    while( isdigit( c ) ) {
      value = value*10 + c - '0';
      c = getche();
    }
    ungetch( c ); // the last character will be fed to the below statement; 
    c = getche(); //will not prompt for user data
    printf("\n%c",c);
    printf( "\nValue=%ld", value );
  }
