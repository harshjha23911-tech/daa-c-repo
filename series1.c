#include <stdio.h>
#include <math.h>

int main() {
    int n;
    double x, sum;

    printf("Enter value of X: ");
    scanf("%lf", &x);

    printf("Enter value of n: ");
    scanf("%d", &n);

    if (x == 1)
        sum = n + 1;
    else
        sum = (pow(x, n + 1) - 1) / (x - 1);

    printf("Sum = %.2lf\n", sum);

    return 0;
}