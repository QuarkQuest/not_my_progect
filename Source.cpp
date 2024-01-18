#pragma warning(disable : 4996)
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
void output(int** a, int n) {//функция вывода матрицы
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
int input(int** a, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = rand() % 2;
		}
	}
	return **a;
}
bool proverka(int **a, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			printf("%d/%d\n", i, j);
			if (a[i][j] != a[j][i]) {
				return false;
			}
		}
	}
	return true;
}
int main() {
	//матрица 
	int n;
	srand(time(NULL));
	scanf("%d", &n);
	int** a;
	a = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		a[i] = (int*)malloc(n * sizeof(int));
	}
	input(a,n);
	output(a, n);
	if (proverka(a,n)) {
		printf("Yes");
	}
	else {
		printf("No");
	}
	for (int i = 0; i < n; i++) {
		free(a[i]);
	}
	free(a);
}