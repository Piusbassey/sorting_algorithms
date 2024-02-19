#include "sort.h"

/**
 * swap - swaps two elements in an array
 * @a: first element to swap
 * @b: second element to swap
 */
void swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * lomuto_partition - partitions an array using the Lomuto scheme
 * @array: array to partition
 * @low: low index of the subarray
 * @high: high index of the subarray
 * @size: size of the array
 * Return: the final partition index
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot, i, j;

    pivot = array[high]; /* pivot is the last element */
    i = low - 1; /* i is the index of the smaller element */

    for (j = low; j <= high - 1; j++)
    {
        /* if current element is smaller than or equal to pivot */
        if (array[j] <= pivot)
        {
            i++; /* increment index of smaller element */
            swap(&array[i], &array[j]); /* swap it with the current element */
            if (i != j) /* if the elements are different */
                print_array(array, size); /* print the array */
        }
    }
    swap(&array[i + 1], &array[high]); /* swap the pivot with the element next to i */
    if (i + 1 != high) /* if the elements are different */
        print_array(array, size); /* print the array */
    return (i + 1); /* return the partition index */
}

/**
 * quick_sort_rec - sorts an array of integers in ascending order using
 * the Quick sort algorithm with recursion
 * @array: array to sort
 * @low: low index of the subarray
 * @high: high index of the subarray
 * @size: size of the array
 */
void quick_sort_rec(int *array, int low, int high, size_t size)
{
    int pi;

    if (low < high) /* if the subarray has more than one element */
    {
        pi = lomuto_partition(array, low, high, size); /* partition the subarray */
        quick_sort_rec(array, low, pi - 1, size); /* sort the left subarray */
        quick_sort_rec(array, pi + 1, high, size); /* sort the right subarray */
    }
}

/**
 * quick_sort - sorts an array of integers in ascending order using
 * the Quick sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2) /* if the array is invalid or trivial */
        return;

    quick_sort_rec(array, 0, size - 1, size); /* call the recursive function */
}
