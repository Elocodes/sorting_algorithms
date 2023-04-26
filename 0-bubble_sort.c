#include "sort.h"
/**
 * bubble_sort - function sorts numbers based on the bubble sort algorithm
 * @array: numbers to be sorted
 * @size: size of the array
 *
 * Return: none
 *
 * Description - The first two numbers are compared. if the first is greater,
 * numbers are swapped, then the swapped number and the one after it are
 * compared and swapped if needed. This loops till the swapped num settles
 * in its rightful position in the ascending order. The whole process is
 * repeated again starting from the first two numbers.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, temp, index;

	index = 0;

	if (!array || !size || size < 2)
		return;
	while (size > index)
	{
		for (i = 1; i < size; i++)
		{
			if (array[i - 1] > array[i])
			{
				temp = array[i - 1];
				array[i - 1] = array[i];
				array[i] = temp;
				print_array(array, size);
			}
		}
		index++;
	}
}
