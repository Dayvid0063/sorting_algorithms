#include "sort.h"
/**
 * shell_sort - A function that sorts an array of integers in ascending order
 * using the Shell sort algorithm
 * @array: The array to be printed
 * @size: Number of elements in the Array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	size_t i, j;
	int temp;

	while (gap < size / 3)
	{
		gap = gap * 3 + 1;
	}
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
		for (i = 0; i < size; i++)
		{
			printf("%d, ", array[i]);
		}
		printf("\n");
		gap = (gap - 1) / 3;
	}
}