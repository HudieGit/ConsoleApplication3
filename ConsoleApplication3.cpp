#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <malloc.h>

int swap(int arr[], int a, int b) {
	int c = arr[a];
	arr[a] = arr[b];
	arr[b] = c;

	return 0;
}

int bubble(int arr[], int start, int end) {
	for (int i = start; i < end; i++) {
		for (int j = start + 1; j < end - i; j++) {
			if (arr[j - 1] > arr[j]) {
				swap(arr, j - 1, j);
			}
		}
	}
	return 0;
}

int choice(int arr[], int start, int end) {
	for (int i = start; i < end; i++) {
		int min = i;
		for (int j = i + 1; j < end; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		swap(arr, min, i);
	}
	return 0;
}

int take(int arr[], int start, int end) {
	for (int i = start + 1; i < end; i++) {
		int new_elem = arr[i];
		int check = i - 1;
		while (check >= 0 && arr[check] > new_elem) {
			arr[check + 1] = arr[check];
			check--;
		}
		arr[check + 1] = new_elem;
	}
	return 0;
}

int merge(int arr[], int start, int end) {
	if (start == end) return 0;
	int mid = (start + end) / 2;
	merge(arr, start, mid);
	merge(arr, mid + 1, end);

	//вспомогательный массив
	int* ar_hp = (int*)malloc((end + 1) * sizeof(int));
	
	int start_left = start; int start_right = mid + 1;

	for (int n = 0; n < end - start + 1; n++) {
		if (((start_left <= mid) && (arr[start_left] < arr[start_right])) || (start_right > end)) {
			ar_hp[n] = arr[start_left];
			start_left += 1;
		}
		else {
			ar_hp[n] = arr[start_right];
			start_right += 1;
		}
	}

	//запись отсортированного вспомогательного массива в исходный
	for (int i = 0; i < end - start + 1; i++) {
		arr[start + i] = ar_hp[i];
	}

	free(ar_hp);

	return 0;
}
	
int quick(int arr[], int start, int end) {
	int start_left = start;
	int end_right = end;
	int mid = arr[(start + end) / 2];

	do {
		while (arr[start_left] < mid) start_left++;
		while (arr[end_right] > mid) end_right--;

		if (start_left <= end_right) {
			if (arr[start_left] > arr[end_right]) swap(arr, start_left, end_right);
			start_left++;
			end_right--;
		}

	} while (start_left <= end_right);

	if (start_left <= end) quick(arr, start_left, end);
	if (start <= end_right) quick(arr, start, end_right);
	
	return 0;
}

int shell(int arr[], int start, int en) {
	int end = en + 1;
	//расстояние шага
	for (int step = end / 2; step > start; step /= 2) {

		for (int i = step; i < end; i++) {

			for (int j = i - step; j >= start && arr[j] > arr[j + step]; j -= step) {
				swap(arr, j, j + step);
			}
		}

	}

	return 0;
}




int main()
{
	int* array_ = (int*)malloc(8 * 4);
	int yh[] = { 8, 6, 4, 5, 3, 1, 7, 2 };
	shell(yh, 0, 7);
	for (int i = 0; i < 8; i++) {
		printf("%d ", yh[i]);
	}

	free(array_);
}