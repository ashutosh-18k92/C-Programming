/*
span of a number: given an array of numbers, for an elemnet 'E'at index 'i' span(i) is defined as

|M|: for all k<i M[k]<E

*/

#include<stdio.h>
#include<stdlib.h>

#define print(op) printf(#op" = %d\n",op);
#define MAXOP 100

enum err{
    STK_UDR_FLOW,
    STK_OVR_FLOW,
};

void err_msg(int n){
    char *err[]={
    "Stack Underflow !!!\n",
    "Stack Overflow !!!\n"
    };
    printf("%s",err[n]);
}

int span(int);
int pop();
void push(int);
int isEmpty();
int isOverflow();
void show_stack();
int stack[MAXOP];
int TOS=-1;

double stock[] ={8,6,5,3,9,2,7,5,4};


main(){
    int i;
    for(i=0;i<10;i++){
        span(i);
    }
    show_stack();
}

int span(int index){
    if(isEmpty()) 
        push(index);
    else{
        while(stock[stack[TOS]]<=stock[index] || TOS==0) pop();
        push(index);
    }
}


int isEmpty(){
    return TOS ==-1;
}
int isOverflow(){
    return TOS==MAXOP;
}
void push(int f){
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

int pop(){
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
    printf("STK [ ");
    while(++i<=TOS) printf("%g ",stack[i]);
    printf("] ");
    print(TOS);
}

