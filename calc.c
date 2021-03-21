#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define print(op) printf(#op" = %d\n",op);
#define cprint(op) printf(#op" = %c\n",op);
#define sprint(op) printf(#op" = %s\n",op);
#define fprint(op) printf(#op" = %g\n",op);
#define NUMBER '0'
#define MAXOP 100

enum err{
    STK_UDR_FLOW,
    STK_OVR_FLOW,
    ZERO_DIV_ERR
};

void err_msg(int n){
    char *err[]={
    "Stack Underflow !!!\n",
    "Stack Overflow !!!\n",
    "Zero Division Error !!!\n"
    };
    printf("%s",err[n]);
}

double pop();
void push(double);

double stack[MAXOP];
int TOS=-1;

int getop(FILE *fp,char s[]);


main(){
    char s[MAXOP];
    int c;
    double res,op2;
    FILE *fp = fopen("sample.dat","rb+");
    while((c=getop(fp,s))!=EOF){ 
    //since s is passed as reference, getop can just manipulate in the function body 
    sprint(s);
        switch(c){
            case NUMBER: 
                push(atof(s));
                break;
            case '+':
                res = pop()+pop();
                fprint(res);
                push(res);
                break;
            case '-':
                op2 = pop();
                res = pop()-op2;
                fprint(res);
                push(res);
                break;
            case '*':
                res = pop()*pop();
                fprint(res);
                push(res);
                break;
            case '/':
                op2 = pop();
                if(op2==0) {
                    err_msg(ZERO_DIV_ERR);
                    exit(ZERO_DIV_ERR);
                }
                res = pop()/op2;
                fprint(res);
                push(res);
                break;
            default:
                printf("\nInvalid");
                break;
        }
    }
}

int getop(FILE *fp,char s[])
{
    int i,c;
    while((s[0]=c=getc(fp)) == ' ' || c=='\t' || c=='\n'); //eat all the spaces and new lines
    if(c==EOF) return c;
    
    s[1]='\0';
    
    if( c!='\n' && !isdigit(c) && c !='.') {
        while((i=getc(fp))!='\n'); //eat the next chars after an operand
        return c;
    }
    
    i=0;
    if(isdigit(c)) while(isdigit(s[++i]=c=getc(fp)));
    if(c=='.') while(isdigit(s[++i]=c=getc(fp)));
    s[i]='\0';
    
    
    return NUMBER;
}

void push(double f){
    //check overflow
    if(TOS==MAXOP) 
        {
            err_msg(STK_OVR_FLOW);
            exit(STK_OVR_FLOW);
        }
    else
        stack[++TOS]=f;
    show_stack();
}

double pop(){
    //check underflow
    if(TOS<0) {
        err_msg(STK_UDR_FLOW);
        exit(STK_UDR_FLOW+1);
    }
    else
        return stack[TOS--];
}

void show_stack(){
    int i=-1;
    while(++i<=TOS) printf("%g ",stack[i]);
    print(TOS);
}
