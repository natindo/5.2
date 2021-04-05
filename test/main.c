#include <stdio.h>

int search(char arr[], char s[]) {
    int count = -1;
    for (int i = 0; arr[i] != '\n'; ++i) {
        if (count == -1) {
            for (int j = 0; s[j] != '\n'; ++j) {
                if (count == -1)
                    if (arr[i] == s[j])
                        count = i;
            }
        }
        else break;
    }
    return count;
}

int main() {
    char arr[128], s[128], c;
    int a;

    for (int i = 0; (c = getchar()) != '\n'; ++i) {
        arr[i] = c;
        a = i;
    }
    arr[a+1] = '\n';
    for (int i = 0; (c = getchar()) != '\n'; ++i) {
        s[i] = c;
        a = i;
    }
    s[a+1] = '\n';
    if (search(arr, s) != -1)
        printf("%d", search(arr, s));
    else printf("%d", -1);

    return 0;
}
