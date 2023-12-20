#include <windows.h>
#include <iostream>
#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <omp.h>

int swap(int arr[], int a, int b) {
	int c = arr[a];
	arr[a] = arr[b];
	arr[b] = c;

	return 0;
}

double bubble(int arr[], int start, int end) {
	time_t strt, finish;
	strt = clock();
	for (int i = start; i < end; i++) {
		for (int j = start + 1; j < end - i; j++) {
			if (arr[j - 1] > arr[j]) {
				swap(arr, j - 1, j);
			}
		}
	}
	finish = clock();
	double duration = ((double)(finish - strt)) / CLOCKS_PER_SEC;
	return duration;
}

double select(int arr[], int start, int end) {
	time_t strt, finish;
	strt = clock();
	for (int i = start; i < end; i++) {
		int min = i;
		for (int j = i + 1; j < end; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		swap(arr, min, i);
	}
	finish = clock();
	double duration = ((double)(finish - strt)) / CLOCKS_PER_SEC;
	return duration;
}

double insert(int arr[], int start, int end) {
	time_t strt, finish;
	strt = clock();
	for (int i = start + 1; i < end; i++) {
		int new_elem = arr[i];
		int check = i - 1;
		while (check >= 0 && arr[check] > new_elem) {
			arr[check + 1] = arr[check];
			check--;
		}
		arr[check + 1] = new_elem;
	}
	finish = clock();
	double duration = ((double)(finish - strt)) / CLOCKS_PER_SEC;
	return duration;
}

int merge_h(int arr[], int start, int end) {
	if (start == end) return 0;
	int mid = (start + end) / 2;
	merge_h(arr, start, mid);
	merge_h(arr, mid + 1, end);

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
double merge(int arr[], int start, int end) {
	time_t strt, finish;
	strt = clock();
	merge_h(arr, start, end);
	finish = clock();
	double duration = ((double)(finish - strt)) / CLOCKS_PER_SEC;
	return duration;
}

int quick_h(int arr[], int start, int end) {
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

	if (start_left <= end) quick_h(arr, start_left, end);
	if (start <= end_right) quick_h(arr, start, end_right);

	return 0;
}
double quick(int arr[], int start, int end) {
	time_t strt, finish;
	strt = clock();
	quick_h(arr, start, end);
	finish = clock();
	double duration = ((double)(finish - strt)) / CLOCKS_PER_SEC;
	return duration;
}

double shell(int arr[], int start, int en) {
	time_t strt, finish;
	strt = clock();
	int end = en + 1;
	//расстояние шага
	for (int step = end / 2; step > start; step /= 2) {

		for (int i = step; i < end; i++) {

			for (int j = i - step; j >= start && arr[j] > arr[j + step]; j -= step) {
				swap(arr, j, j + step);
			}
		}

	}

	finish = clock();
	double duration = ((double)(finish - strt)) / CLOCKS_PER_SEC;
	return duration;
}

double counting(int arr[], int start, int end) {
	/*time_t strt, finish;
	strt = clock();*/
	double start_ = omp_get_wtime();

	int max = 0; //подсчет максимума
	for (int i = 0; i < end; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}

	int* id = (int*)malloc((max + 1) * sizeof(int)); //создание доп массива и его обнуление
	for (int i = 0; i <= max; i++) id[i] = 0;

	for (int i = 0; i < end; i++) { //подсчет элементов
		id[arr[i]]++;
	}

	int count = 0;
	for (int i = 0; i <= max; i++) {
		while (id[i] != 0) {
			arr[count++] = i;
			id[i]--;

		}
	}
	//finish = clock();
	double SortTime = omp_get_wtime() - start_;
	//double duration = ((double)(finish - strt));
	free(id);
	return SortTime;
}

int count_r(int arr[], int n, int place) {
	int r = 1;
	return 0;
}

double radix(int arr[], int start, int end) {
	return 0;
}