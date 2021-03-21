#include<stdio.h>
#include<stdlib.h>
int main()
{
	//char pointers are good to hold strings 
	char *str = "a string.";
	puts(str);
	
	//for console i/O operations we need to have memmory 
	char name[80];
	puts("Enter your name: ");
	gets(name);
	puts(name);
	
	//its usually bad to know how many chars user is going to enter.
	// for this kind of scenasios what would be better.
	char *name2;
	puts("Enter your name: ");
	name2 = malloc(80);
	gets(name2);
	puts(name2);

	char s[10];
	gets(s);
	printf("%d",strlen(s));
	return 0;
}
