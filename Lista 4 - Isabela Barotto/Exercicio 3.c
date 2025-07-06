#include <stdio.h>

int main() {
    int num, bin = 0, mult = 1;
    scanf("%d", &num);

    while (num > 0) {
        bin += (num % 2) * mult;
        mult *= 10;
        num /= 2;
    }

    printf("%d\n", bin);
    return 0;
}