#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

int main() {

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO start_attribute;
    GetConsoleScreenBufferInfo(hStdOut, &start_attribute);

    srand(time(NULL));

    int n;

    printf("Set the arrays dimension:\n");
    scanf("%d", &n);

    int A[n][n];
    int B[n][n];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = rand() % 100;
            B[i][j] = rand() % 100;
        }
    }

    printf("Source arrays:\n");
    SetConsoleTextAttribute(hStdOut, 3);
    printf("A:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%2d ", A[i][j]);
        }
        printf("\n");
    }
    SetConsoleTextAttribute(hStdOut, 10);
    printf("B:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%2d ", B[i][j]);
        }
        printf("\n");
    }

    SetConsoleTextAttribute(hStdOut, start_attribute.wAttributes);
    printf("Output array:\n");
    int x[n][2*n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2*n; ++j) {
            if (j < n) {
                x[i][j] = A[i][j];
                SetConsoleTextAttribute(hStdOut, 3);
                printf("%2d ", x[i][j]);
            } else {
                x[i][j] = B[i][j - n];
                SetConsoleTextAttribute(hStdOut, 10);
                printf("%2d ", x[i][j]);
            }
        }
        printf("\n");
    }
    SetConsoleTextAttribute(hStdOut, start_attribute.wAttributes);

    return 0;
}
