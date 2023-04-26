#include "sort.h"
#include <stdio.h>

/**
 * selection_sort - function sorts numbers using the selction sort algorithm
 * @array: an unsorted array of numbers
 * @size: size of the array
 *
 * Return: none
 *
 * Description - The least number is assumed to be at the index 0 of the array
 * A second variable is  initialized to check for the smallest number as the
 * loop executes. if found, the index of the number replaces the initial. The
 * numbers at these two posts gets swapped at the end. This process is run
 * size - 1 times to ensure all the numbers are accounted for.
 */
void selection_sort(int *array, size_t size)
{
	int temp;
	size_t least_num_index, i, j;

	if (!array || !size || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		least_num_index = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[least_num_index])
				least_num_index = j;
		}
		if (least_num_index != i)
		{
			temp = array[i];
			array[i] = array[least_num_index];
			array[least_num_index] = temp;
			print_array(array, size);
		}
	}
}
