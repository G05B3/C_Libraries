#ifndef STACK_H
#define STACK_H

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

struct Stack* createStack(unsigned capacity);
int isFull(struct Stack*);
int isEmpty(struct Stack*);
void push(struct Stack*, int);
int pop(struct Stack*);
int peek(struct Stack*);

#endif