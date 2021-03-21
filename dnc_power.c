#include<stdio.h>

int power(int x,int m);

int main(){
	int x,m;
	x=2,
	m=10;
	int r = power(x,m);	
	printf("%d",r);
	return 0;
}

int power(int x, int m){
	int res;
	if(m==0){
		return 1;
	}
	else{
		if(m%2==0)
  		res =  power(x,m/2)*power(x,m/2);
 		else
		res = power(x,(m-1)/2)*x*power(x,(m-1)/2);
	}
	return res;
}
