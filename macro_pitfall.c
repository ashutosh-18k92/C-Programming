#include<stdio.h>

#define max(a,b) ((a)>=(b) ? (a):(b))
#define square(x) (x)*(x)
#define fprint(expr) printf(#expr " = %g\n", expr)
#define paste(front, back) front ## back
#define dprint(i) printf(#i" %d",i);
#define LN printf("\n");

/*
Although it looks like a function call, a use of max expands into in-line code. Each occurrence
of a formal parameter (here A or B) will be replaced by the corresponding actual argument.
Thus the line
x = max(p+q, r+s);
will be replaced by the line
x = ((p+q) > (r+s) ? (p+q) : (r+s));

Pitfall: 

x=max(++i,++j) := ++i > ++j ? ++i : ++j

x = square(2+3) := 2+3*2+3 resulting 11 which was intended to be 25 so watch out
*/

char *ij="Hello Program.\n" ;

int main()
{
    int i=3,j=7,mx;
    mx = max(++i,++j);   // DANGER !!!
    dprint(mx);
    mx = square(2+3);
    LN;
    dprint(mx);
    LN;
    dprint(i);
    dprint(j);
    fprint((float)i/j);    
    LN;
    char *str = paste(i,j);  // results in an identifier rather a string 
    printf("\n%s",str);
    return 0;
}
