#include "sort.h"

/**
 * _swap - func swaps two numbers
 * @a: first number
 * @b:  second number
 */
void _swap(int *a, int *b)
{
	int elem = *a;
	*a = *b;
	*b = elem;
}

/**
 * bubble_sort - Func sorts an ARR of num using bubble sort algorithm
 * @array: Array being sorted
 * @size: Array size
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t u, v;
	int exchange;

	if (array == NULL || size < 2)
		return;

	for (v = size; v > 0; v--)
	{
		exchange = 0;
		for (u = 0; u < v - 1; u++)
		{
			if (array[u] > array[u + 1])
			{
				_swap(&array[u], &array[u + 1]);
				exchange = 1;
			}
		}
		if (exchange == 0)
			break;
		print_array(array, size);
	}
}
