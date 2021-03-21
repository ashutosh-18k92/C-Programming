/*
Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. It is
easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
*/
#include<stdio.h>
#include<ctype.h>

#define WORD_SIZE 20
#define NL 18
#define BL 17

int main()
{
	FILE *fp = fopen("text.txt","rb+");
	int ch;
	int wl[WORD_SIZE],wordlen=0;
	int i;
	for(i=0;i<WORD_SIZE;++i){
		wl[i]=0;
	}
	
	while((ch=getc(fp))!=EOF){
		if(!isalpha(ch) && wordlen>0){
			wl[wordlen]+=1;
			wordlen=0;
		}
			else{
			++wordlen;
		}
		
		if(ch=='\n'){
			wl[NL]+=1;
		}
		if(ch==' '){
			wl[BL]+=1;
		}
	
		putchar(ch);		
	}
	
	int j;
	for(i=0;i<WORD_SIZE;++i){
		if(wl[i]==0) continue;
		printf("%d\t",i);
		for(j=1;j<=wl[i];j++){
			printf("|");
		}
		printf("\n");
	}
	fclose(fp);
    return 0;
}
