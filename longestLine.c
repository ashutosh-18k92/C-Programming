/*
program that reads a set of text lines and prints the longest. 

The outline is simple enough:
while (there's another line)
if (it's longer than the previous longest)
(save it)
(save its length)
print longest line
*/
#include<stdio.h>

#define MAXLINE 1000
#define iprint(a) printf("\n%d\n",a)
#define sprint(s) printf("\n%s\n",s)

int getline(FILE **fp,char *line);
void copy(char *to, char *from);

int main(){
	int max,len;
	char line[MAXLINE];
	char longest[MAXLINE];
	FILE *fp = fopen("file.txt","rb+");
	max=0;
	while((len=getline(&fp,line))>0){
		if(len>max){
			max = len;
			copy(longest,line);
		}
	}
	sprint(longest);
	fclose(fp);
	return 0;
}

int getline(FILE **fp,char *line){
	int ch;
	int i=0;
	while((ch=getc(*fp))!='\n' && i<MAXLINE-1){
		if(ch==EOF) return 0;
		line[i]=ch;
		i++;
	}
	line[i+1] ='\0';
	return i;
}

void copy(char *to,char *from){
	int i=0;
	while((to[i]=from[i])!='\0') ++i;
}
