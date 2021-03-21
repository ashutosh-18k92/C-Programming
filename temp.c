#include<stdio.h>
#include<stdlib.h>
/*
ASCII: conversions
*/


int myatoi(char *s);
int isNumber(char c);
void errorbeep();
main()
{
    printf("\n%d",myatoi("12304"));
    return 0;
}

int myatoi(char *s){
    long num=0;
    int i=0;
    while(s[i]) {
        if(!isNumber(s[i])) {
            printf("\n%s returned: nan\a",__FUNCTION__);
            exit(1);
        }
    num=num*10+(s[i++]-'0');
}
    return num;
}

int isNumber(char c){
    if(c>='0' && c<='9') return 1;
    return 0;
}

