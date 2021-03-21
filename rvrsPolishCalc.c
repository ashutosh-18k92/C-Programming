#include<stdio.h>
#include<stdlib.h>

#define null NULL
#define SIZE 10
#define dprintln(d) printf("%d\n",d)
#define sprintln(s) printf("%s\n",s)

void Error(int exit_code){
    static char *err[]={
        "",
        "\nStackFullException\n",
        "\nStatckEmptyException\n",
        "\nOut of Memory\n"
    };
    printf("%s",err[exit_code]);
}

enum exitcode{
    stack_full=1,
    stack_empty,
    out_of_memory
};

typedef struct _stack* stack;


struct _stack{
    int data;
    stack next;
    stack prev;
};
int stack_size=0;

/*
Improvising TOS: data will point to the number of items in the stack
and next will point to the TOP OF STACK node.
*/
stack TOS=null;

stack createNode(int data){
    stack node = malloc(sizeof(struct _stack));
    if(!node){
        Error(out_of_memory);
        exit(out_of_memory);
    }
    node->data = data;
    node->next =null;
    node->prev = null;
    return node;
}

void push(stack *stk,int data);
int pop();
stack createStack(int data);


main(){
    stack mystack=createStack(0);
    push(&mystack,1);
    return 0;
}

stack createStack(int data){
    stack mystack;
    mystack = malloc(sizeof(struct _stack));
    if(!mystack){
        Error(out_of_memory);
        exit(out_of_memory);
    }
    mystack->data = data;
    mystack->next = null;
    TOS = malloc(sizeof(struct _stack));
    TOS->data=1;
    TOS->next = mystack;
    return mystack;
}



void push(stack *stk,int data){
    //check overflow
    stack node;
    if(TOS->data==SIZE){
        Error(stack_full);
        exit(stack_full);
    }
    else{
        node = createNode(data);
        
    }
            
    if(*stk)
    dprintln((*stk)->data);
    if(TOS)
    dprintln(TOS->data);
}

int pop(){
    
}
