/*Дана квадратная вещественная матрица размерности n х n. 
Найти скалярное произведение строки на столбец, на пересечении которых находится последний минимальный элемент матрицы.*/

#include <iostream>
using namespace std;
int** memory(int n, int m);
void fill(int** a, int n, int m);
void find_last_min(int** a, int n, int m, int imin, int jmin);
int sp(int** a, int n, int imin, int jmin);
int main()
{	
	int n, imin=0 , jmin=0;
	printf("vvedite razmer\n");
	scanf_s("%d", &n);
	int** A = memory(n, n);
	fill(A,n, n);
	find_last_min(A, n, n, imin, jmin);
	printf("%d", sp(A, n, imin, jmin));
}

//выделение памяти
int** memory(int n, int m)
{
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[m];
	}
	return a;
}
//заполнение элементов
void fill(int** a, int n, int m)
{
	printf("zapolnite massiv");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf_s("%d", &a[i][j]);
		}
	}
}
//поиск последнего минимального элемента в массиве
void find_last_min(int** a, int n, int m,int imin,int jmin)
{
	int min=INT_MAX;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j]<min)
			{
				imin = i;
				jmin = j;
				min = a[i][j];
			}
		}
	}
}
int sp(int**a, int n, int imin, int jmin)
{
	int sp = 0;
	for (int i = 0; i < n; i++)
	{
		sp = sp + (a[imin][i]*a[i][jmin]);
	}
	return sp;
}