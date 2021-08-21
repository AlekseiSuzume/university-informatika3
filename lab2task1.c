#include <math.h>
#include <conio.h>
#include <stdio.h>
#include <windows.h>

float f(float, float);
float ya(float);

int main(void ) {
    system("chcp 65001");
    int k, n;
    float a, b, h, x, y0;
    printf("Введите a: ");
    scanf("%f", &a);
    printf("Введите b: ");
    scanf("%f", &b);
    printf("Введите y[0]: ");
    scanf("%f", &y0);
    printf("Введите количество разбиений n: ");
    scanf("%d", &n);
    float y[n + 1];
    y[0] = y0; // начальное условие
    x = a;
    h = (b - a) / n;
    for (k = 1; k <= n; k++) // метод Эйлера
    {
        y[k] = y[k - 1] + h * f(x, y[k - 1]);
        x = a + k * h;
    }
// сравнение с аналитическим решением
    for (k = 0; k <= n; k++) {
        x = a + k * h;
        printf("x = %4.2f \tanalytical = %5.2f \tEuler = %5.2f\n", x, ya(x), y[k]);
    }
    getch();
}

float f(float x, float y) // правая часть
{
    return (y / (x + 1)) + expf(x) * (x + 1);
}

float ya(float x) // аналитическое решение
{
    return (x + 1) * expf(x);
}