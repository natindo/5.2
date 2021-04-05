#include <stdio.h>
#include <math.h>


double numb (char c);
int digit(char c);
void compare(double result);


int main() {
    char sym;
    int w = 0;
    double arr[100] = {0};
    while (sym != '\n') {
        if (digit(sym = getchar())) {
            arr[w] = numb(sym);
            w++;
        }else if (sym == '+') {
            arr[w - 2] = arr[w - 2] + arr[w-1];
            w--;
        }else if (sym == '-') {
            arr[w - 2] = arr[w - 2] - arr[w - 1];
            w--;
        }else if (sym == '*') {
            arr[w - 2] = arr[w - 2] * arr[w - 1];
            w--;
        }else if (sym == '/') {
            arr[w - 2] = arr[w - 2] / arr[w - 1];
            w--;
        }else if (sym == '^') {
            arr[w - 2] = pow(arr[w - 2], arr[w - 1]);
            w--;
        }else if (sym == '%') {
            arr[w - 2] = (int)arr[w - 2] % (int)arr[w - 1];
            w--;
        }else if (sym == 's')
            arr[w - 1] = sin(arr[w-1]);
        else if (sym == 'c')
            arr[w - 1] = cos(arr[w-1]);
    }
    compare(arr[w-1]);

    return 0;
}