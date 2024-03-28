#include <stdio.h>
void swap (int num1,int num2);

int main ()
{
	int num1, num2;
	printf("Nhap num1: ");
	scanf("%d",&num1);
	printf("Nhap num2: ");
	scanf("%d",&num2);
	swap(num1, num2);
	return 0;
}

void swap (int num1,int num2)
{
	int swap = 0;
	int *ptr1, *ptr2;
	ptr1 = &num1;
	ptr2 = &num2;
	swap = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = swap;
	printf("Gia tri num1: %d\n",num1);
	printf("Gia tri num2: %d\n",num2);
}
