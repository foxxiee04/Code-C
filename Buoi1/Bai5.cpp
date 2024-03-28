#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void inputArr (int *arr, int size);
void outputArr (int *arr, int size);
void outputEvenNumbers (int *arr, int size);
int maxNumber (int *arr, int size);

int main ()
{
	int size;
	printf("Nhap kich thuoc mang: ");
	scanf("%d",&size);
	
	//Bo nho dong
	int *arr = (int*)malloc(size*sizeof(int));
	if (arr == NULL)
	{
		printf("Khong du bo nho\n");
		return 1;
	}
	inputArr (arr, size);
	outputArr (arr, size);
	outputEvenNumbers (arr, size);
	printf("Phan tu lon nhat la: %d\n", maxNumber(arr, size));

	free(arr);
	return 0;
}

void inputArr (int *arr, int size)
{
	printf("Nhap mang so nguyen: \n");
	for (int i = 0; i < size; i++)
	{
		printf("Phan tu thu [%d]: ", i + 1);
		scanf("%d", arr + i);
	}
}

void outputArr (int *arr, int size)
{
	printf("Mang vua nhap: \n");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", *(arr + i));
	}
	printf("\n");
}

void outputEvenNumbers (int *arr, int size)
{
	printf("Cac so chan: \n");
	for (int i = 0; i < size; i++)
		if (*(arr + i) % 2 == 0)
		{
			printf("%d ", *(arr + i));
		}
	printf("\n");
}

int maxNumber(int *arr, int size) 
{
    int max = *arr;
    for (int i = 1; i < size; i++) 
	{
        if (*(arr + i) > max) 
		{
            max = *(arr + i);
        }
    }
    return max;
}

