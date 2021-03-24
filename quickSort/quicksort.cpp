#include <bits/stdc++.h>
using namespace std;


int arrLen;

void printArr(int *arr, int len) {
  for (int j = 0; j <=len; j++)
    cout << arr[j] << " ";
  cout << "\n";
}

void exchange(int *A, int i, int j) {
  int t = A[i];
  A[i] = A[j];
  A[j] = t;
}

int getRandomIndex(int start,int end){
	time_t t;
	srand((unsigned)time(&t));
	return start + (rand()%(end-start+1));
}


int partition(int *A, int start, int end) {
  int random_pivot_position = getRandomIndex(start,end);
  exchange(A,random_pivot_position,start); 
  
  int initial_pivot_postition = start;
  int current_pivot_position = initial_pivot_postition;
  int seeker = initial_pivot_postition + 1;
  int pivot = A[initial_pivot_postition];
  while (seeker <= end) {
    if (A[seeker] <= pivot) {
      current_pivot_position++;
      if (current_pivot_position != seeker) {
        exchange(A, current_pivot_position, seeker);
        printArr(A, arrLen);
      }
    }
    seeker++;
  }
  exchange(A, current_pivot_position, initial_pivot_postition);
  return current_pivot_position;
}

/*
 * The idea of quick sort is fairly simple
 * choose an element E from the array
 * put all elements smaller than E to left and
 * put all elements larger than E to right */
/*
 * How cleaverly you can do it?*/

void quicksort(int *A, int p, int r) {
  int q;
  if (p < r) {
    q = partition(A, p, r);
    quicksort(A, p, q - 1);
    quicksort(A, q + 1, r);
  }
}

int main() {
  freopen("input.txt", "r", stdin);
  int *arr;
  cin>>arrLen;
  arr = (int *)malloc(arrLen*sizeof(int));
  for(int i=0;i<arrLen;i++) cin>>arr[i];
  quicksort(arr, 0, arrLen-1);
  printArr(arr, arrLen-1);
  return 0;
}
