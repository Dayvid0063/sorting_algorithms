#include "sort.h"

/**
 * range_output - func print a range of elem
 * @array: Array to print
 * @start: Start index
 * @end: End index
 */
void range_output(int *array, int start, int end)
{
	int u;

	for (u = start; u <= end; u++)
	{
		if (u > start)
			printf(", ");
		printf("%d", array[u]);
	}
	printf("\n");
}

/**
 * swap_elem - Func swap two elem
 * @array: Array
 * @i: First element
 * @j: Second element
 * @path: path sorting
 */
void swap_elem(int *array, int i, int j, int path)
{
	int elem;

	if (path == (array[i] > array[j]))
	{
		elem = array[i];
		array[i] = array[j];
		array[j] = elem;
	}
}

/**
 * bitonic_merge - Bitonic merge sequence
 * @array: Array to sort
 * @low: Starting index
 * @size: Size
 * @path: Sorting path
 */
void bitonic_merge(int *array, int low, int size, int path)
{
	int u, v;

	if (size > 1)
	{
		v = size / 2;
		for (u = low; u < low + v; u++)
			swap_elem(array, u, u + v, path);

		bitonic_merge(array, low, v, path);
		bitonic_merge(array, low + v, v, path);
	}
}

/**
 * recursive_sort - Func recursively runs bitonic sort
 * @array: Array
 * @low: Starting index
 * @size: Size
 * @path: Sorting direction
 */
void recursive_sort(int *array, int low, int size, int path)
{
	int v;

	if (size > 1)
	{
		v = size / 2;
		printf("Merging [%d/%d] (%s):\n", size, (int)size,
				(path == 1) ? "UP" : "DOWN");
		range_output(array, low, low + size - 1);

		recursive_sort(array, low, v, 1);
		recursive_sort(array, low + v, v, 0);

		bitonic_merge(array, low, size, path);

		printf("Result [%d/%d] (%s):\n", size, (int)size,
				(path == 1) ? "UP" : "DOWN");
		range_output(array, low, low + size - 1);
	}
}

/**
 * bitonic_sort - Func runs bitonic sort algorithm
 * @array: Array
 * @size: Size
 */
void bitonic_sort(int *array, size_t size)
{
	int top;

	if (size < 2 || !array)
		return;

	top = 1;
	recursive_sort(array, 0, (int)size, top);
}
