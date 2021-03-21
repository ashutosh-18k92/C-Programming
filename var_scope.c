#include<stdio.h>
#define print(a) printf(#a" = %d\n",a)

/*
Local Var: comes to existence when the function is called and is destroyed when function exits.

Static Var: this variable is treated as global variable for storage purposes, but its usage is only 
            limited to the functions i.e. its value can be used outside the fuction unless returned.
*/


int foo(){
    printf("\n%s\n",__FUNCTION__);
    int j=0;
    static int i=0;
    print(++i);
    print(++j);
    return i;
}

void bar(){
    printf("\n%s\n",__FUNCTION__);
    static int i=0;
    print(++i);
}

main()
{
    foo();
    foo();
    int k = foo();
    print(k);
    bar();
    bar();
}
