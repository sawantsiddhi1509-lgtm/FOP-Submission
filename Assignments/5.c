#include <stdio.h>

int main() {
    int a[10][10], b[10][10], sum[10][10];
    int i, j, r, c;

    // Input size
    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    // Input Matrix A
    printf("Enter Matrix A:\n");
    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++)
            scanf("%d", &a[i][j]);

    // Input Matrix B
    printf("Enter Matrix B:\n");
    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++)
            scanf("%d", &b[i][j]);

    // Addition
    printf("\nAddition of matrices:\n");
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            sum[i][j] = a[i][j] + b[i][j];
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    // Saddle Point (for Matrix A)
    int found = 0;
    for(i = 0; i < r; i++) {
        int min = a[i][0], col = 0;

        for(j = 1; j < c; j++) {
            if(a[i][j] < min) {
                min = a[i][j];
                col = j;
            }
        }

        int flag = 1;
        for(int k = 0; k < r; k++) {
            if(a[k][col] > min) {
                flag = 0;
                break;
            }
        }

        if(flag) {
            printf("\nSaddle Point = %d\n", min);
            found = 1;
        }
    }
    if(found == 0)
        printf("\nNo Saddle Point\n");

    // Inverse (only 2x2)
    if(r == 2 && c == 2) {
        float det = (a[0][0]*a[1][1] - a[0][1]*a[1][0]);

        if(det == 0) {
            printf("\nInverse not possible\n");
        } else {
            printf("\nInverse Matrix:\n");
            printf("%.2f %.2f\n", a[1][1]/det, -a[0][1]/det);
            printf("%.2f %.2f\n", -a[1][0]/det, a[0][0]/det);
        }
    } else {
        printf("\nInverse only for 2x2 matrix\n");
    }

    // Magic Square (for Matrix A)
    if(r == c) {
        int sumRow = 0, magic = 1;

        for(j = 0; j < c; j++)
            sumRow += a[0][j];

        for(i = 1; i < r; i++) {
            int temp = 0;
            for(j = 0; j < c; j++)
                temp += a[i][j];
            if(temp != sumRow)
                magic = 0;
        }

        for(j = 0; j < c; j++) {
            int temp = 0;
            for(i = 0; i < r; i++)
                temp += a[i][j];
            if(temp != sumRow)
                magic = 0;
        }

        int d1 = 0, d2 = 0;
        for(i = 0; i < r; i++) {
            d1 += a[i][i];
            d2 += a[i][r-i-1];
        }

        if(d1 != sumRow || d2 != sumRow)
            magic = 0;

        if(magic)
            printf("\nMagic Square\n");
        else
            printf("\nNot a Magic Square\n");

    } else {
        printf("\nMagic square needs square matrix\n");
    }

    return 0;
}