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
    swi(p,q);//pָ���ַ���β��ĸ,qָ���ַ�������ĸ
    printf(ptr);
    printf("\n");
    p=q=ptr;
    while(*p!='\0')
    {
        s=p;//sָ���ַ������һ����ĸ
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
        }//pָ����һ���ַ�������ĸ


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
