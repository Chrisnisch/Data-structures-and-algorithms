#include <stdio.h>
#include <math.h>
#include <windows.h>

double myFunc(double x, double a) {
    return (sqrt((exp(a)-1)* cos(x)));
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    double xStart = -11.;
    double xEnd = 21.;
    double xDelta = 2.8;
    double a;
    printf("Введите параметр a: \n");
    scanf("%lf", &a);
    double x = xStart;
    printf("№п/п\t\tx\t\ta\t\ty\n");
    int n = 1;
    while (x <= xEnd) {
        double y = myFunc(x, a);
        if (y != y) {
            printf("%d\t%10.6lf\t%10.lf\tневозможно вычислить\n", n++, x, a);
        } else {
            printf("%d\t%10.6lf\t%10.lf\t%10.6lf\n", n++, x, a, y);
        }
        x += xDelta;
    }
    return 0;
}