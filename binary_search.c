#include<stdio.h>
#define SIZE 100
#define iprint(a) printf("%d\n",a)

//Binary Search: returns the index of the element if found in the given array; -1 otherwise.

int len(int *arr){
    int i=-1;
    while(arr[++i]);
    return i;
}

int arr[SIZE]={1,2,3,4,5,6,7,8,9,10};
int binarySearch(int x,int *arr);

main(){
    printf("\n%s: index starts at 0\n",__FUNCTION__);
    int i=1;
    while(i<=len(arr))
        iprint(binarySearch(i++,arr));
    return 0;
}

int binarySearch(int x,int *arr){
    int low = 0;
    int high = len(arr)-1;
    int mid;
    while(low<=high){
        mid = (high+low)/2;
        if(x<arr[mid])
            high = mid-1;
        else if(x>arr[mid])
            low = mid+1;
        else
            return mid;
    }
    return -1;
}

