/*
Purpose: Quick Sort 
Best Case: T(n) = O(nlog(n))
Average Case : T(n)= O(nlog(n)) 
Worst Case: T(n) = O(n^2)
Best practical choice for sorting because it is remarkably effiecient on average case.
Stable: sorting in place.
Best suited implementation Style: randomized (choosing a random pivot)
*/

#include<stdio.h>
#define iprint(a) printf("%d ",a)
#define exchange(A,i,j) c=A[i],A[i]=A[j],A[j]=c;

void traverse(int *A);

void quicksort(int *A,int p,int r);
int partition(int *A,int p,int r);


int main(){
    int c;
	int A[]={2,8,7,1,3,5,6,4};
	traverse(A);
    exchange(A,2,3)
	traverse(A);
}

int partition(int *A,int p,int r){
    int key=A[p];
    int i=p-1;
    int j=p;
    while(j<r){
        if(key<=A[j]){
            
        }
    }
}

void traverse(int A[]){
	int len = sizeof(A)/sizeof(int);
	iprint(len);
}



