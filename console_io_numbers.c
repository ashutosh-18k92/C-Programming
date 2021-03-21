#include<stdio.h>
int main()
{
int i,j;

//discarding a whitespace: in below example the leading whitespace will be
// discarded when supplied in the input string as specified in the control string.
scanf("  %d",&i);
printf("%d",i);
// suppressing an input: in the below case the char will be read and discarded 
// say we want to give comma as a separator.
scanf("%d %*c %d",&i,&j);
printf("co-ordinates(%d,%d)",i,j);
scanf("%d,%d",&i,&j);
printf("co-ordinates(%d,%d)",i,j);
	return 0;
}
