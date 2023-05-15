//Lab7_2.c Добуток не 0 елементів масиву та сума елементів від першого відємного за допомогою функцій
#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <math.h>

void Gener_Arr(const int N);
void Out_Arr(int a[], const int N);
long Dob_Arr(int a[], const int N);
int Sum_abs_Arr(int a[], const int N);

const int N = 6;
int a[6];

int main(void)
{
	setlocale(LC_CTYPE, "ukr");

	Gener_Arr(N);
	Out_Arr(a, N);
	printf("\n Добуток елементiв вектору вiдмiнних вiд нуля становить %ld", Dob_Arr(a, N));
	printf("\n Сума модулiв елементiв масива пiсля першого вiд’ємного становить %d", Sum_abs_Arr(a, N));

	int getch(); getch();
	return 0;
}

//Функція - генератор масиву розміром N випадковими числами від Low до High
void Gener_Arr(const int N)
{
	const int Low = -100, High = 100;
	srand(time(0));
	for (int i = 0; i < N; i++)
		a[i] = Low + rand() % (High - Low + 1);
}
//Функція виведення одномірного масиву на екран розміром N
void Out_Arr(int a[], const int N)
{
	printf("\n Згенерований вектор A[1,%d] = {", N);
	for (int i = 0; i < N; i++)
		printf("%d, ", a[i]);
	printf("\b\b}");
}
//Функція обрахунку добутку не 0 елементів масиву
long Dob_Arr(int a[], const int N)
{
	long D = 1;
	for (int i = 0; i < N; i++)
		if (a[i] != 0) D *= a[i];
	return D;
}
//Функція підрахунку суми модулів елементів після 1 відємного
int Sum_abs_Arr(int a[], const int N)
{
	int A, S = 0, k = 0;
	for (int i = 0; i < N; i++)
	{
		if (a[i] < 0) k += 1;
		if (a[i] < 0 && k == 1) A = i;
	}
	for (int i = A + 1; i < N; i++) S += abs(a[i]);
	return S;
}
