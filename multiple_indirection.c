#include<stdio.h>

//Purpose: Multiple Indirection - referencing and dereferencing.
//Double pointer is just another name to the pointer it points to. 
//If below program is run we see q is just an alias of p, what p would do with p and *p 
//same does q with *q and **q (referencing 
// and dereferencing respectively).

int main(){
	int *p, **q, x;
	x = 10;
	p=&x;
	
	//referencing
	q=&p;
	printf("p=%p\n",p);
	printf("*p=%d\n",*p);
	printf("&p=%p\n",&p);
	printf("int **q;\nq=&p\n");
	printf("q=%p\n",q);
	printf("*q=%p\n",*q); //should give the address pointed by p
	printf("**q=%d",**q); // the value poihnted by p
	return 0;
}

//Conclusion: 

//1. *q references to the addresss of the variable which p is pointing to.

//2. **q references to the value of the variable which p is pointing to.

//3 there is no link between the address of pointer p itself being refereed by the doubl-pointer q.

