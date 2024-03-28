#include <stdio.h>
void MAXMIN (int num1, int num2);

int main ()
{
	int num1, num2;
	printf("Nhap lan luot 2 so: \n");
	scanf("%d %d",&num1, &num2);
	MAXMIN(num1, num2);
	return 0;
}

void MAXMIN (int num1, int num2)
{
	int max, min;
	int *ptr1, *ptr2;
	ptr1 = &num1;
	ptr2 = &num2;
	
	if (*ptr1 > *ptr2)
	{
		max = *ptr1;
		min = *ptr2;
	}
	else
	{
		max = *ptr2;
		min = *ptr1;
	}
	printf("Max: %d\n",max);
	printf("Min: %d\n",min);
}
