#include <stdio.h>

void quick_sort(int*, int, int);
int partition(int*, int, int);

int main(void) {
	int arr[4] = {10, 5, 2, 3};

	quick_sort(arr, 0, 3);

	for (int i=0; i<4; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}

void quick_sort(int *array, int start, int end) {
	if (start < end) {
		int q = partition(array, start, end);

		quick_sort(array, start, q-1);
		quick_sort(array, q+1, end);
	}
}

int partition(int *array, int start, int end) {
	int pivot = array[end];
	int i = start - 1;
	int temp = 0;

	for (int j=start; j<end; j++) {
		if (array[j] <= pivot) {
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}

	temp = array[i+1];
	array[i+1] = array[end];
	array[end] = temp;

	return i+1;
}
