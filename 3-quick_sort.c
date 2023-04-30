#include "sort.h"
#include <stdio.h>

/**
 * lomuto_partition - function partions array in preparation for sorting
 * @array: array to be sorted in ascending order
 * @size: size of array
 * @lo: first num in partition
 * @hi: last num of partition
 *
 * Return: returns index of the pivot
 */
size_t lomuto_partition(int *array, size_t size, ssize_t lo, ssize_t hi)
{
	int temp, pivot;
	ssize_t i, j;
	/*choose last element as pivot*/
	pivot = array[hi];
	/*pivot index*/
	i = lo - 1;
	for (j = lo; j < hi; j++)
	{
		if (array[j] <= pivot)
		{
			i = i + 1;
			/*swap current element with element at index*/
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	/*place pivot element in the correct position*/
	if (array[hi] < array[i + 1])
	{
		temp = array[i + 1];
		array[i + 1] = array[hi];
		array[hi] = temp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort - function sorts array using the quicksort algorithm
 * @array: array to be sorted in ascending order
 * @size: size of array
 * @lo: first num in partition
 * @hi: last num of partition
 *
 * Return: none
 */
void quicksort(int *array, size_t size, ssize_t lo, ssize_t hi)
{
	ssize_t p;

	/*partition array*/
	if (lo < hi)
	{
		p = lomuto_partition(array, size, lo, hi);
		/*sort the two partitions, sorting left side first*/
		quicksort(array, size, lo, p - 1);
		quicksort(array, size, p + 1, hi);
	}
}

/**
 * quick_sort - function sorts entire array after the partition level sorts
 * @array: array to be sorted in ascending order
 * @size: size of array
 *
 * Return: none
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	/*sorting the entire array from 0 to end, after the partition level sorts*/
	quicksort(array, size, 0, size - 1);
}
