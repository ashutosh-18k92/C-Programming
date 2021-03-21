#include<stdio.h>
#include <ctype.h>
#define NUMBER '0'

int getch(void);
void ungetch(int);
/* getop: get next character or numeric operand */

main(){
    char  s[100];
    int type;
    while((type=getop(s))!='~'){
       switch (type) {
case NUMBER:
printf("\nNumber");
break;
case '+':
printf("\nadd");
break;
case '*':
printf("\nprod");
break;
case '-':
printf("\nsub");
break;
case '/':
printf("\ndivide");
break;
//case '\n':
//printf("\t%.8g\n", pop());
//break;
default:
printf("\nerror: unknown command %s", s);
break;
}
    }
    return 0;
}

int getop(char *s)
{
int i, c;
while ((s[0] = c = getche()) == ' ' || c == '\t')
printf("space\n");

s[1] = '\0';
if (!isdigit(c) && c != '.')
return c; /* not a number */
i = 0;
if (isdigit(c)) /* collect integer part */
while (isdigit(s[++i] = c = getche()))
;
if (c == '.') /* collect fraction part */
while (isdigit(s[++i] = c = getche()))
;
s[i] = '\0';
if (c != '~')
ungetch(c);
return NUMBER;
}
