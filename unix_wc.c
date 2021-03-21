#include<stdio.h>
/*
counting lines, words, and characters
*/
#define IN 1
#define OUT 0
main()
{
	FILE *fp = fopen("wc.txt","wb");
	int ch,nw,nc,nl;
	int state=OUT;
	nc=nw=nl=0;
	while((ch=getchar())!='~'){
		++nc;
		if(ch=='\n')
		++nl;
		if(ch==' ' || ch=='\t' || ch=='\n')
		state=OUT;
		else if(state==OUT){
			++nw;
			state=IN;
		}
		putc(ch,fp);
	}
	printf("\ncharacters=%d words=%d lines=%d",nc,nw,nl);
	fclose(fp);
}
