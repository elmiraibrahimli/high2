#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

#define SIZE 1001

char x[SIZE], y[SIZE];
int i, j, lenx, leny, m[2][SIZE];

int main() {
	//Читаем две входные последовательности в массивы x и y.
	//При этом значения x[0] и y[0] обнуляем, а входные строки заносим в массивы,
	//начиная с первой ячейки.Длины последовательностей сохраняем в переменных lenx и leny.
	x[0] = y[0] = 0;
	while (scanf("%s %s\n", x + 1, y + 1) == 2)
	{
		lenx = strlen(x + 1); leny = strlen(y + 1);
		//Обнуляем массив m. Динамически вычисляем значения f(i, j). Изначально m[0][j] содержит значения f(0, j).
		//Далее в m[1][j] заносим значения f(1, j). Поскольку для вычисления f(2, j) достаточно иметь значения
		//двух предыдущих строк массива m, то значения f(2, j) можно сохранять в ячейках m[0][j],
		//значения f(3, j) – в ячейках m[1][j] и так далее.
		memset(m, 0, sizeof m);
		for (i = 1; i <= lenx; i++)
			for (j = 1; j <= leny; j++)
				if (x[i] == y[j]) m[i % 2][j] = 1 + m[(i - 1) % 2][j - 1];
				else m[i % 2][j] = max(m[(i - 1) % 2][j], m[i % 2][j - 1]);
				printf("%d\n", m[lenx % 2][leny]);
	}
	return 0;
}
