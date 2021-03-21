#include<stdio.h>
#include<math.h>
#define SIZE 10

double lookup[SIZE];

void traverse(){
	 int i=0;
	 while(i<SIZE){
	printf("%.0f  ",lookup[i]);
	i++;
	}
	putchar('\n');
}
double powerDP(int m,int n){
	traverse();
	double res;
	if(n==0){
		res = 1;
		lookup[n]=res;
	} 
	if(lookup[n]!=-1){
		res = lookup[n];
	}
	else{
	if(n%2==0){
		res = powerDP(m,n/2)*powerDP(m,n/2);
		lookup[n]=res;
	}
	else
	{
		res = m*powerDP(m,n/2)*powerDP(m,n/2);
		lookup[n]=res;
	}
}
return res;
}

double power(int m,int n){
	int i=0;
	while(i<SIZE){
		lookup[i]=-1;
		i++;
	}
	return powerDP(m,n); 
}



main(){
printf("%.0f\n",power(5,6));
traverse();
}



