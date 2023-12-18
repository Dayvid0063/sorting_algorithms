#include <stdio.h>

/**
 * _swap - func swaps two numbers
 * @a: first number
 * @b: second number
 */
void _swap(int *a, int *b)
{
	int elem = *a;
	*a = *b;
	*b = elem;
}

/**
 * lomuto_partition - Lomuto partition scheme
 * @array: Array of int
 * @size: Size
 * @left: Starting index
 * @right: Ending index
 * Return: Final partition
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot = array + right;
	int u, v = left - 1;
	size_t w;

	for (u = left; u <= right - 1; u++)
	{
		if (array[u] < *pivot)
		{
			v++;
			if (v != u)
			{
				_swap(&array[v], &array[u]);
				for (w = 0; w < size; w++)
				{
					printf("%d", array[w]);
					if (w != size - 1)
					{
						printf(", ");
					}
				}
				printf("\n");
			}
		}
	}
	if ((v + 1) != right)
	{
		_swap(&array[v + 1], &array[right]);
		for (w = 0; w < size; w++)
		{
			printf("%d", array[w]);
			if (w != size - 1)
			{
				printf(", ");
			}
		}
		printf("\n");
	}

	return (v + 1);
}

/**
 * _sort - Func recursively sorts the array
 * @array: Array of int
 * @size: Size
 * @left: Starting index
 * @right: Ending index
 */
void _sort(int *array, size_t size, int left, int right)
{
	int div;

	if (left < right)
	{
		div = lomuto_partition(array, size, left, right);
		_sort(array, size, left, div - 1);
		_sort(array, size, div + 1, right);
	}
}

/**
 * quick_sort - Function sorts array using quicksort
 * @array: Array of int
 * @size: Size
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	_sort(array, size, 0, size - 1);
}
