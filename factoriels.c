#include <stdio.h>
#include <stdlib.h>
#include<string.h>

static char *fact(char *s,unsigned x)
{
    unsigned sum =0;
    size_t len = strlen(s);
    size_t i=len;

    while(i>0)
    {
        sum += (s[--i] -'0') * x;
        s[i]= sum % 10+ '0';
        sum /=10;
    }
    while(sum)
    {
        len++;
        memmove (&s[1],s,len);
        s[i]= sum %10 +'0';
        sum /= 10;
    }
    return s;
}
char * strfact(char *dest,unsigned n)
{
    strcpy(dest, "1");
    while(n>1)
    {
        fact(dest,n--);
    }
    return dest;
}
void test_fact(unsigned n)
{

    char s[1000];
    printf( "%3u!= %s\n",n,strfact(s,n));
}

int main(void)
{
    int n;
    printf ("Entrez un nombre :");
    scanf("%d",&n);
  test_fact(n);
    return 0;
}
