#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#include "calc.h"

#define MAXOP 100
#define NUMBER '0'
#define MAXLINE 500

char line[MAXLINE];
int line_i;

int getop(char s[])
{
    int i, c;

    while ((s[0] = c = line[line_i++]) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;  
    i = 0;
    if (isdigit(c)) 
        while (isdigit(s[++i] = c = line[line_i++]))
            ;
    if (c =='.') 
        while (isdigit(s[++i] = line[line_i++]))
            ;
    s[i] = '\0';
    line_i--;
    
    return NUMBER;
}

int getl(char s[], int lim)
{
    int c, i;
    i = 0;
    
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}



int main () {
    int type;
    double op2;
    char s[MAXOP];
    int t, g;

    while (getl(line, MAXLINE) != 0) {
        line_i = 0;

        while ((type = getop(s)) != EOF) {
            switch (type)
            {
            case NUMBER:
                push (atof(s));
                break;
            case '+':
                push (pop() + pop());
                break;
            case '*':
                push (pop() * pop());
                break;
            case '-':
                op2 = pop();
                push (pop() + op2);
                break;
            case '%' :
                op2 = pop();
                if (op2 != 0.0) {
                    t = (pop() / op2);
                    trunc (t);
                    push (t);

                } else {
                    printf("error: zero divisor\n");
                    return -1;
                }
                break;
            case '^' :
                op2 = pop ();
                t = pow (op2, pop ());
                push (t);
                break;    
            case '/' :
                op2 = pop();
                if (op2 != 0.0) {
                    push (pop() / op2);
                } else {
                    printf("error: zero divisor\n");
                    return -1;
                }
                break;
            case '\n': 
                printf("\t%.8g\n", pop());
                break;     
            default:
                printf("error: unknown command %s\n", s);
                return -2;
            }
        }
    }
    return 0;
}