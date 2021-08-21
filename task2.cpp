#include <stdio.h>
#include <math.h>

float f(float x);

float rect(float a, float b, int n);

int main() {
    system("chcp 65001");
    float a1, b1;
    int n1;
    printf("Укажите нижний предел интегрирования a = ");
    scanf("%f", &a1);
    printf("Укажите верхний предел интегрирования b = ");
    scanf("%f", &b1);
    printf("Укажите количество разбиений n = ");
    scanf("%d", &n1);
    printf("Интеграл от функиции f(x) на промежутке [%.2f, %.02f] равен %f\n", a1, b1, rect(a1, b1, n1));
    system("pause");
    return 0;
}

float f(float x) {
    return sqrt(x * x + pow(M_E, x));
}

float rect(float a, float b, int n) {
    float h, x, s;
    // h шаг интегрирования
    // x текущее значение переменной интегрирования
    // s результат
    int i;
    s = 0.0;
    h = (b - a) / n; // определение шага интегрирования
    x = a + h / 2;
    for (i = 1; i <= n; i++) {
        s = s + f(x);
        x = x + h;
    }
    return s * h;
}