#include <stdio.h>
#include <windows.h>
#include <math.h>

int main() {
    system("chcp 65001");
    int N;
    double eps = 0.00001;
    printf("Введите число уравнений системы: n = ");
    scanf("%d", &N);
    double a[N][N + 1];
    printf("Введите коэффициенты при неизвестных:\n\n");
    printf("a[1][1]*X1 + a[1][2]*X2 + ... + a[1][n]*Xn = Y[1]\n");
    printf("a[2][1]*X1 + a[2][2]*X2 + ... + a[2][n]*Xn = Y[2]\n");
    printf("...\n");
    printf("a[n][1]*X1 + a[n][2]*X2 + ... + a[n][n]*Xn = Y[n]\n\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("a[%d][%d] = ", i + 1, j + 1);
            scanf("%lf", &a[i][j]);
        }
        printf("Y[%d] = ", i + 1);
        scanf("%lf= ", &a[i][N]);
    }

    //Печать полученной матрицы
    printf("\n Матрица системы уравнений: \n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%6.2f\t", a[i][j]);
        }
        printf(" | %6.2f\n", a[i][N]);
    }
    printf("\n");

    double max;
    int index, k;
    k = 0;
    while (k < N) {
        //поиск строки с максимальным коэффициентом при a[i][k]
        index = k;
        max = fabs(a[k][k]);
        for (int i = k + 1; i < N; i++) {
            if (fabs(a[i][k]) > max) {
                max = fabs(a[i][k]);
                index = i;
            }
        }
        //проверка на ненулевые диагональные элементы
        if (max < eps) {
            printf("Решение получить невозможно из-за нулевого диагонального элемента");
        }
        //Перестановка строк
        for (int i = k; i < N; i++) {
            double temp = a[k][i];
            a[k][i] = a[index][i];
            a[index][i] = temp;
        }
        double temp = a[k][N];
        a[k][N] = a[index][N];
        a[index][N] = temp;

        //нормализация уравнений
        for (int i = k; i < N; i++) {
            double temp1 = a[i][k];
            if (fabs(temp1) < eps) continue;
            for (int j = k; j <= N; j++) {
                a[i][j] = a[i][j] / temp1;
            }
            if (i == k) continue;
            for (int j = k; j <= N; j++) {
                a[i][j] = a[i][j] - a[k][j];
            }
        }
        k++;
    }

    printf("Треугольный вид матрицы:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%6.2f\t", a[i][j]);
        }
        printf(" | %6.2f\t\n", a[i][N]);
    }
    printf("\n");

    //обратный ход
    double x[N];
    for (int i = 0; i < N; i++) {
        x[i] = a[i][N];
    }
    for (int i = N - 2; i >= 0; i--) {
        for (int j = i + 1; j < N; j++)
            x[i] = x[i] - x[j] * a[i][j];
    }

    //Печать ответа
    printf("В результате решения системы уравнений, получены следующие значения: \n");
    for (int i = 0; i < N; i++) {
        printf("x%d = %.4f\n", i + 1, x[i]);
    }

    system("pause");
    return 0;
}
