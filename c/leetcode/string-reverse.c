#include <stdio.h>
#include <stdlib.h>
void swi(char *p,char *q);
void main()
{
    char ptr[]="the bule sky";
    printf(ptr);
    printf("\n");
    char *p,*q,*s;
    p=q=ptr;
    while(*p!='\0')
    {
        p++;
    }
    p--;
    swi(p,q);//p指向字符串尾字母,q指向字符串首字母
    printf(ptr);
    printf("\n");
    p=q=ptr;
    while(*p!='\0')
    {
        s=p;//s指向字符串最后一个字母
        p++;
        while(*p==' '||*p=='\0')
        {
            if(*p=='\0')
            {
                swi(s,q);
            }
            else
            {
                p++;
                if(*p!=' ')
                {
                    swi(s,q);
                    q=p;
                }
            }
        }//p指向下一个字符串首字母


    }
    swi(s,q);
    printf(ptr);
    printf("\n");


}


void swi(char *p,char *q)
{
    char temp;
    while(p>q)
    {
        temp=*p;
        *p=*q;
        *q=temp;
        p--;
        q++;
    }
}
