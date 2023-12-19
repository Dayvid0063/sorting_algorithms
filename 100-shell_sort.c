#include "sort.h"

/**
 * shell_sort - Func sorts array using the shell sort algorithm
 * @array: Array
 * @size: Size of the array
 **/
void shell_sort(int *array, size_t size)
{
	unsigned int n, u, v;
	int elem;

	n = 1;

	if (!array || size < 2)
		return;

	while (n < size / 3)
		n = n * 3 + 1;

	while (n > 0)
	{
		for (u = n; u < size; u++)
		{
			elem = array[u];
			v = u;

			while (v >= n && array[v - n] > elem)
			{
				array[v] = array[v - n];
				v -= n;
			}

			array[v] = elem;
		}

		print_array(array, size);
		n /= 3;
	}
}
