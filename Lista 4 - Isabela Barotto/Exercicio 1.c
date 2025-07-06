#include <stdio.h>

int main() {
    int num, n, first, last, digits = 0, pow = 1, result;
    scanf("%d", &num);

    n = num < 0 ? -num : num;
    last = n % 10;

    int temp = n;
    while (temp >= 10) {
        temp /= 10;
        pow *= 10;
        digits++;
    }
    first = temp;

    result = n - first * pow - last + last * pow + first;
    if (num < 0) result = -result;

    printf("%d\n", result);
    return 0;
}