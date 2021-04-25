#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strend(char* s, char* t) {
    size_t strel1 = strlen(s);
    size_t strel2 = strlen(t);
    int i = 0;
    if (strel1 < strel2)
        return 0;
    for (size_t i = strel1 - strel2; i <= strel1; i++) {
        if (s[i] != t[i])
            return 0;
        i++;
    }
return 1;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
