#include <stdio.h>
#include <string.h>

void remove_palindrome(char str[]) {
    int len = strlen(str);
    int i, eh_palindromo = 1;

    for (i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            eh_palindromo = 0;
            break;
        }
    }

    if (eh_palindromo) {
        if (len % 2 == 0) {
            str[len / 2] = '\0';
        } else {
            str[len / 2 + 1] = '\0';
        }
    }
}

void vec_to_str(int n, int vec[], char str[]) {
    int i, j = 0;

    for (i = 0; i < n; i++) {
        if (vec[i] < 0) {
            str[j++] = '(';
            str[j++] = (-vec[i]) + 48;
            str[j++] = ')';
        } else {
            str[j++] = vec[i] + 48;
        }

        if (i < n - 1) {
            str[j++] = ' ';
        }
    }

    str[j] = '\0';
}

void uncompress(int n, int vec[]) {
    int i = 0;

    while (i < n) {
        if (vec[i] == -1) {
            int val = vec[i + 1];
            int rep = vec[i + 2];
            for (int j = 0; j < rep; j++) {
                printf("%d ", val);
            }
            i += 3;
        } else {
            printf("%d ", vec[i]);
            i++;
        }
    }
}