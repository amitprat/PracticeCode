/*
Tags - 
  Write your own printf with only putchar
  Write itoa method
  print double/float in smart way
  smart conversion from char * or string to integer
*/
#include<stdio.h>
#include<stdarg.h>

void myprintf(char *,...);
char* convert(unsigned int, int);
char *convertf(double d,int base);
int main()
{
    int i=65;
    double d = 3.164;
    unsigned int ui = 2999999999;
    char str[]="This is my string";
    myprintf("\nMessage = %s\n%d\n%c\n%f\n%u\n",str,i,'A',d,ui);
}

void myprintf(char* p,...)
{
    int i;
    unsigned int ui;
    double dval;
    char *ptr;
    va_list argp;
    va_start(argp, p);
    for(; *p!='\0'; p++)
    {
        while(*p!='%' && *p != '\0')
        {
            putchar(*p);
            p++;
        }
        if(! *p )   break;
        switch(*++p)
        {
        case 'c' :
            i =va_arg(argp,int);
            putchar(i);
            break;
        case 'u' :
            ui=va_arg(argp, unsigned int);
            ptr = convert(ui,10);
            while(*ptr) {
                putchar(*ptr++);
            }
            break;
        case 'd':
        case 'o':
        case 'x':
            i=va_arg(argp,int);
            if(i<0) {
                putchar('-');
                i = -i;
            }
            ptr = convert(i,10);
            while(*ptr) {
                putchar(*ptr++);
            }
            break;
        case 'f':
            dval = va_arg(argp,double);
            ptr = convert(dval,10);
            while(*ptr) {
                putchar(*ptr++);
            }
            putchar('.');
            i = (dval-(int)dval)*1000000;
            ptr = (convertf((dval-(int)dval),10));
            while(*ptr) {
                putchar(*ptr++);
            }
        break;
        case 's':
            char *s=va_arg(argp,char *);
            while(*s) {
                putchar(*s++);
            }
            break;
        }
    }
    va_end(argp);
}

char *convert(unsigned int num, int base)
{
    static char buf[33];
    char *ptr;
    double dval;
    ptr=&buf[sizeof(buf)-1];
    *ptr='\0';
    do
    {
        *--ptr="0123456789abcdef"[num%base];
        num/=base;
    }
    while(num!=0);
    return(ptr);
}
char *convertf(double d,int base)
{
    char buf[8];
    char *ptr = buf;
    while(d > 0.00001) {
        *ptr++ = "0123456789abcdef"[(int)(d*base)];
        d = d*base - (int)(d*base);
    }
    *ptr = '\0';
    return buf;
}
