#include <math.h>
#include <stdio.h>

int digit(char c) {
    if ('0' <= c && c <= '9')
        return 1;
    else return 0;
}


double numb(char c) {
    int k, fl = 0, i = 0;
    char count[100] = {'0'};
    double hu = 0;
    while (c != ' ' && c != '\n') {
        if (digit(c) || c == '.')
            count[i] = c;
        i++;
        c = getchar();
    }
    count[i] = '\0';
    for (int j = 0; count[j] != '\0'; ++j) {
        if (count[j] == '.') {
            k = j;
            fl = 1;
        }
        if (fl == 0)
            hu = hu * 10.0 +(count[j] - '0');
        else hu = hu + (count[j] - '0') * pow(0.1, j - k);
    }
    if (fl == 1)
        hu = hu+2;
    return hu;
}

void compare(double result) {
    if (pow(result,2) > pow((int)result, 2))
        printf("%.3f", result);
    else printf("%d", (int)result);
}