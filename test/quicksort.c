#include <stdio.h>

void	swap(int *n1, int *n2)
{
	int	temp;

	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

int	partition(int *array, int min, int max)
{
	int	pivot;
	int	i;
	int	j;

	i = (min - 1);
	pivot = array[max];
	j = min;
	while (j < max)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
		j++;
	}
	swap(&array[i + 1], &array[max]);
	return (i + 1);
}

void	quicksort(int *array, int min, int max)
{
	int	pi;

	if (min < max)
	{
		pi = partition(array, min, max);
		quicksort(array, min, pi - 1);
		quicksort(array, pi + 1, max);
	}
}

int	main(void)
{
	int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int array1[10] = {3, 4, 1, 7, 2, 6, 7, 8, 9, 5};

	quicksort(array1, 0, 9);
	for (int i = 0; i < 10; i++)
		printf("%d\n", array1[i]);
}