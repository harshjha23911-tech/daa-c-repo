#include <stdio.h>

int main() {
    int n;
    double a, r, sum = 0;

    printf("Enter first term (a): ");
    scanf("%lf", &a);

    printf("Enter common ratio (r): ");
    scanf("%lf", &r);

    printf("Enter number of terms (n): ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        sum = sum + a;
        a = a * r;
    }

    printf("Sum = %.2lf\n", sum);

    return 0;
}