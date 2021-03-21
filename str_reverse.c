/*
char str[]; Mutable string operations are well performed on char str[]; 
char *str; is used to declare string constants.
*/

#include<stdio.h>
#include<stdlib.h>

#define exchange(s,i,j) c=s[i],s[i]=s[j],s[j]=c;

main(){
    char s[]="mississippi";
    int i,j,c;
    
    printf("str: %s\n",s);
    for(i=0,j=strlen(s)-1;i<j;i++,j--)
        exchange(s,i,j);
    printf("rev_str: %s\n",s);
    return 0;
}
