#include<stdio.h>
#include<math.h>
#define SIZE 10

double looupTable[SIZE];

void traverse(){
	 int i=0;
	 
	 while(i<SIZE){
	printf("%.0f  ",looupTable[i]);
	i++;
	}
putchar('\n');
}
double powerDP(int m,int n){
	traverse();
	double res;
	if(n==0){
		res = 1;
		looupTable[n]=res;
	}
else if (looupTable[n]!=-1){
		res = looupTable[n];
	}
        else{
	if(n%2==0){
		res = powerDP(m,n/2)*powerDP(m,n/2);
		looupTable[n]=res;
	}
        else
 {
		res = powerDP(m,n/2)*powerDP(m,n/2)*m;
		looupTable[n]=res;
	}
}
        return res;
}

        double power(int m,int n){
	int i=0;
	while(i<SIZE){
		looupTable[i]=-1;
		i++;
	}
        return powerDP(m,n);
}



        int main()
        {
int m,n;
m=5;
n=4;
printf("%d^%d = %.0f\n",m,n,power(m,n));
traverse();
return 0;
}
