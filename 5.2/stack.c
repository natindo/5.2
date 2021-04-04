#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXVAL 100 

int sp = 0;
double val[MAXVAL];
void push (double);
double pop (void); 

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error,\n");
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf ("321‚\n");
    return 0.0;
    }
}