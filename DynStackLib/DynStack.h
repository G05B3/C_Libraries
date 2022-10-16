#ifndef DYNsstack_H
#define DYNsstack_H

typedef struct _sstack sstack;
typedef sstack* stack;

stack create_stack();
void push(stack* S, int value);
void pop(stack* S);
void destroy_stack(stack S);
int peek(stack S);
int peek_prev(stack S);
void display_stack(stack S);
sstack* prev(sstack* S);

#endif