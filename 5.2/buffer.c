#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 100

static char buf[BUFSIZE];
static int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch (int c) {
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
        exit(333);
    } else {
        buf[bufp++] = c;
    }
}