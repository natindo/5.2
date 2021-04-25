#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGHT 128

char* str(void) {
    int n = 0;
    char* s = (char*)malloc(sizeof(char));
    int maxvalue = 1;
    char c = getchar();
    while (c != '\n') {
        s[n++] = c;
    if (n >= maxvalue) {
        maxvalue *= 2;
        s = (char*)realloc(s, maxvalue * sizeof(char));
    }
    c = getchar();
}
s[n] = '\0';
return s;
}

int main(void) {
char* s = str();
printf("\n");
printf("%s", s);
return 0;
}