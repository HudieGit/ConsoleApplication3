#include <windows.h>
#include <iostream>
#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "sortings.h"
#include <omp.h>

int start(char* name, int key, double K_time, int step) {
	FILE* file{};
	errno_t err;
	err = fopen_s(&file, name, "w");
	err = fprintf(file, "%d", step);
	err = fputc('\n', file);

	int array_length = 0;
	for (int i = 1; i <= 1000000000; i++) {

		array_length = i * step;
		printf("%d  ", array_length);

		int* array_ = (int*)malloc((array_length + 1) * sizeof(int));

		double start_ = omp_get_wtime();


		for (int j = 0; j < array_length; j++) {
			array_[j] = abs(rand());
		}

		double time = 0;
		switch (key)
		{
		case 1: time = bubble(array_, 0, array_length); break;
		case 2: time = insert(array_, 0, array_length); break;
		case 3: time = select(array_, 0, array_length); break;
		case 4: time = merge(array_, 0, array_length); break;
		case 5: time = quick(array_, 0, array_length); break;
		case 6: time = shell(array_, 0, array_length); break;
		case 7: time = counting(array_, 0, array_length); break;

		default:
			break;
		}

		printf("%.3f \n", time);
		err = fprintf(file, "%2.3lf", time);
		err = fputc('\n', file);

		free(array_);

		if (time > K_time) {
			break;
		}

	}
	printf("\n");
	err = fclose(file);
	return 0;
}
int clean(int x, int y, int len) {
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD l;
	COORD point; point.X = x; point.Y = y;
	FillConsoleOutputAttribute(output, 0, len, point, &l);
	return 0;
}
int poscur(int x, int y) {
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD l;
	COORD point; point.X = x; point.Y = y;
	SetConsoleCursorPosition(output, point);
	return 0;
}
int line_selection(int len) {
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD l;
	COORD point; point.X = 0; point.Y = 1;
	poscur(0, 0);
	printf("press <e> to select");

	int len_check = 0;
	while ((len_check == 0) || (len_check > len)) {
		char check = ' ';
		FillConsoleOutputAttribute(output, BACKGROUND_GREEN, 1, point, &l);
		do {
			check = _getch();
			FillConsoleOutputAttribute(output, 0, 1, point, &l);
			if ((check == 'w') && (point.Y != 1)) point.Y--;
			if ((check == 's') && (point.Y < len)) point.Y++;
			FillConsoleOutputAttribute(output, BACKGROUND_GREEN, 1, point, &l);
			Sleep(100);
		} while (check != 'e');
		clean(point.X, point.Y, 1);
		len_check = point.Y;
	}
	poscur(0, 0);
	clean(0, 0, 50);
	return len_check;
}
int settings(double* time, int* step) {
	clean(0, 0, 5000);
	printf("\n time: %2.3lf\n step: %d\n back\n", *(time), *(step));
	int check;
	do {
		check = line_selection(3);
		if (check == 1) {
			clean(7, 1, 10);
			poscur(7, 1);
			scanf_s("%lf", time);
		}
		if (check == 2) {
			clean(7, 2, 10);
			poscur(7, 2);
			scanf_s("%d", step);
		}
	} while (check != 3);
	poscur(0, 0);
	clean(0, 0, 3000);
	return -1;
}
 int test() {
	char b[] = "D:/ConsoleApplication3/bubble.txt"; //1
	char i[] = "D:/ConsoleApplication3/insert.txt";// 2
	char s[] = "D:/ConsoleApplication3/select.txt";// 3
	char m[] = "D:/ConsoleApplication3/merge.txt";// 4
	char q[] = "D:/ConsoleApplication3/quick.txt";// 5
	char ss[] = "D:/ConsoleApplication3/shell.txt";// 6
	char c[] = "D:/ConsoleApplication3/counting.txt";// 7

	HANDLE hProcess;
	HANDLE hThread;
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	ZeroMemory(&pi, sizeof(pi));

	int check = 0;
	int step = 500;
	double time = 1;

	do {
		printf("press <e> to select\n");
		printf(" _settings_\n bubble\n select\n insert\n merge\n quick\n shell\n counting\n");
		check = line_selection(8);
		switch (check) {
		case 1: check = settings(&time, &step); break;
		case 2: check = start(b, check - 1, time, step); break;
		case 3: check = start(i, check - 1, time, step); break;
		case 4: check = start(s, check - 1, time, step); break;
		case 5: check = start(m, check - 1, time, step); break;
		case 6: check = start(q, check - 1, time, step); break;
		case 7: check = start(ss, check - 1, time, step); break;
		case 8: check = start(c, check - 1, time, step); break;
		default: break;
		}
	} while (check != 0);

	return 0;
}


