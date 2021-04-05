#include <stdio.h>

#define Maxline 200

int search_first_position(int str1[Maxline], int str2[Maxline]){
    int i, j, n;
    n = -1;
    for (i = 0; str2[i] != '\0'; ++i){
        for (j = 0; str1[j] != '\0'; ++j) {
            if (str2[i] == str1[j]) {
                n = j;
                break;
            }
        }
        if (n != -1) {
            printf(" Элемент "); 
            putchar(str2[i]); 
            printf(" первый раз встречается в сторке на %d месте\n", n);
        } else {
            printf("-1\n");
        }
    };
}

int main() {
    int s1[Maxline], s2[Maxline], i, c;

    i = 0;
    while ((c = getchar()) != '\n') {
        s1[i++] = c;
    }
    s1[i] = '\0';
    i = 0;
    while ((c = getchar()) != '\n') {
        s2[i++] = c;
    }
    s2[i] = '\0';

    search_first_position(s1, s2);
}