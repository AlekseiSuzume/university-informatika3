#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <conio.h>

float f(float x);
int sign(float x);
float bisec(float a, float b, float eps, float eps1);

int main(void) {
    system("chcp 65001");
    float a, b, x, xi, eps, eps1 = 0.0001;
    printf("Введите a: ");
    scanf("%f", &a);
    printf("Введите b: ");
    scanf("%f", &b);
    printf("Введите точность вычислений eps: ");
    scanf("%f", &eps);

    if (f(b) * f(a) > 0) {
        return printf("Условие сходимости не выполнено");
    }
    printf("x = %f", bisec(a, b, eps, eps1));
    getch();
}


float f(float x) {
    return 2 + (3 * x) + pow(cos(x), 2);
}

int sign(float x) {
    int result;
    if (x > 0) {
        result = 1;
    } else {
        result = -1;
    }
    return result;
}

float bisec(float a, float b, float eps, float eps1) {
    float x;
    while ((b - a) > eps) {
        x = (a + b) / 2;
        if (fabsf(f(x)) <= eps1) break;
        if (sign(f(a)) != sign(f(x))) {
            b = x;
        } else {
            a = x;
        }
    }
    return x;
}



