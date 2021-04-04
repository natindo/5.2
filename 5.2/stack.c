#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

static double stack[STACK_SIZE];
static int top = -1;

void push(double n){
    if (top +1 < STACK_SIZE) {
        stack[++top] = n;
    } else {
        printf("error: stack is full\n");
        exit(111);
    }
}

double pop() {
    if (top != -1) {
        return stack[top--];
    } else {
        printf("error: stack is empty\n");
        exit(222);
    }
}