#include <stdio.h>
void Operation (int num1, int num2);

int main () 
	{
		int num1, num2;
		printf("Nhap lan luot 2 so: \n");
		scanf("%d %d",&num1,&num2);
		Operation(num1, num2);
		return 0;
	}
	
void Operation (int num1, int num2)
{
	int sum, diff, prod;
	float quotient;
	int *ptr1, *ptr2;
	
	ptr1 = &num1;
	ptr2 = &num2;
	
	sum = *ptr1 + *ptr2;
	diff = *ptr1 - *ptr2;
	prod = *ptr1 * *ptr2;
	printf("Tong: %d\n", sum);
	printf("Hieu: %d\n", diff);
	printf("Tich: %d\n", prod);
	if (*ptr2 != 0)
	{
		quotient = (float)*ptr1 / *ptr2;
		printf("Thuong: %.2f\n", quotient);
	}
	else printf ("Khong the chia\n");

}
