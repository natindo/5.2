#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef char str[256];
#define get_str(s) ( scanf("%255[^\n]%*c", (s)) == 1 )

int len(const void * a, const void * b) {
    return strlen(*(char**)a) - strlen(*(char**)b);
}

int main(void) {
    unsigned nStrings;

    while ( printf("Number of strings: ") && scanf("%u", &nStrings) == 1 && nStrings ) {
        str buf;
        unsigned i;
        char c;
        char ** strings = malloc(sizeof(char*) * nStrings);
        assert(strings);
        while ( scanf("%c", &c) == 1 && c != '\n' ) {
            ;
        }    
        for ( i = 0; i < nStrings; ++i ) {
            printf("> ");
            if ( ! get_str(buf) ) {
                fprintf(stderr, "Input error!\n");
                return 1;
            }
            strings[i] = strdup(buf);
            assert(strings[i]);
        }
        qsort(strings, nStrings, sizeof(char*), len);
        printf("\nResult:\n");
        for ( i = 0; i < nStrings; ++i ) {
            printf("%s\n", strings[i]);
            free(strings[i]);
        }
        free(strings);
        printf("\n");
    }
    return 0;
}
