#include "sort.h"

/**
 * sift_down - Je rétablis la propriété du tas maximal sous un nœud
 * @array: Array to sort
 * @size: Number of elements in the array
 * @root: Root of the subtree to sift down
 * @end: Last index included in the heap
 */
static void sift_down(int *array, size_t size, size_t root, size_t end)
{
	size_t child, swap;
	int value;

	(void)size;
	value = array[root];

	while (root * 2 + 1 <= end)
	{
		child = root * 2 + 1;
		swap = root;

		if (array[swap] < array[child])
			swap = child;
		if (child < end && array[swap] < array[child + 1])
			swap = child + 1;
		if (swap == root)
			return;

		array[root] = array[swap];
		array[swap] = value;
		print_array(array, size);
		value = array[swap];
		root = swap;
	}
}

/**
 * heap_sort - Je trie un tableau d'entiers avec le tri par tas
 * @array: Array to sort
 * @size: Number of elements in the array
 */
void heap_sort(int *array, size_t size)
{
	size_t start, end;
	int temporary;

	if (array == NULL || size < 2)
		return;

	start = (size - 2) / 2 + 1;
	while (start > 0)
	{
		start--;
		sift_down(array, size, start, size - 1);
	}

	end = size - 1;
	while (end > 0)
	{
		temporary = array[end];
		array[end] = array[0];
		array[0] = temporary;
		print_array(array, size);
		end--;
		sift_down(array, size, 0, end);
	}
}
