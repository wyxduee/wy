//#include"stdafx.h"
#include<stdio.h>
#include<stdlib.h>
//void plist(int *nums, int numsSize, int **p);
void subsets(int* nums, int numsSize, int **p, int k, int n, int *s);
void main()
{
	int nums[] = { 1,2,3,4,6,9,25 };
	int numsSize = 7;
	int *p[128];
	int s[128] = { 0 };
	int i, j;
	//plist(nums, numsSize, p);
	subsets(nums, numsSize, p, -1, 0, s);
	for (i = 0; i<128; i++)
	{
		for (j = 0; j <s[i]; j++, p[i]++)
		{
			printf("%d", *p[i]);
			printf(" ");
		}
		printf("\n");
	}
}
/*void plist(int *nums, int numsSize, int **p)///�����ݵ�������еݼӴ洢������ָ������Ӧ�ĵ�ַ����Ӧ�ı�����
{
int i, j;
for (i = 0; i<numsSize; i++)
{
int *a=(int *)malloc(sizeof(int)*(i+1));
p[i] = a;
for (j = 0; j <= i; j++,a++)
{
*a = nums[j];
}
}

}*/
void subsets(int* nums, int numsSize, int **p, int k, int n, int *s)///k��ʾ��ѭ��Ҫ��ӵ�������Ԫ�ص�λ�ã�n��ʾǰ���ٸ��Ӽ��ĸ�����s�洢���Ǹ��������Ӽ��ĳ���
{
	if (k>numsSize-1)
		return;
	else if (k == -1 || k == 0)
	{
		if (k == -1)
		{
			p[0] = NULL;
			s[0] = 0;
		}
		else
		{
			int *a = (int *)malloc(sizeof(int));
			p[1] = a;
			*p[1] = nums[0];
			s[1] = 1;
		}
		n = 2;///n=1;

	}
	else {
		int i, j;
		for (i = 0; i < n; i++)
		{
			s[n + i] = s[i] + 1;
			int* a = (int *)malloc(sizeof(int)*s[n+i]);
			p[n + i] = a;
			int *b = p[i];
			for (j = 0; j < s[i]; j++, a++, b++)
			{
					*a = *b;///�����Ӽ�
			}
			*a = nums[k];///Ϊÿһ���Ӽ����һ���µ�Ԫ�أ������µ��Ӽ�
		}
		n = 2 * n;
	}
	k++;
	subsets(nums, numsSize, p, k, n, s);

}


