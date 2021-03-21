/*
a program is self aware if it can write itself (entrire code) 
on a file.
*/

/*
Write a program to copy its input to its output, replacing each tab by \t, each
backspace by \b, and each backslash by \\. This makes tabs and backspaces visible in an
unambiguous way.
*/

#include<stdio.h>
main()
{
	int c;
	FILE *fp = fopen("file.txt","w");
	if(!fp) {
	printf("Cannot open file");
	exit(1);
	}
	printf("[~] quit\n");
	while((c=getchar())!='~'){
		putchar(c);
		if(c=='\n')
		fputs("\\n",fp);
		else if (c=='\b')
		fputs("\\b",fp);
		else if(c=='\t')
		fputs("\\t",fp);
		else if(c==' ')
		fputs("[ ]",fp);
		else
		putc(c,fp);
	}
	
	fclose(fp);
	fp=fopen("file.txt","rb");
	while((c=getc(fp))!=EOF){
		putchar(c);
	}
	fclose(fp);
}
