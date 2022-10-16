#include <stdio.h>
#include <stdlib.h>

typedef struct _sstack{

    int val;
    struct _sstack* prev;

}sstack;

sstack* create_stack()
{
    
    return NULL;
}

void push(sstack** S, int value)
{
    sstack* new = (sstack*)malloc(sizeof(sstack));
    new->val = value;
    new->prev = *S;
    *S = new;
}

void pop(sstack** S)
{
    //If there are no more elements to pop
    if (*S == NULL)
        return;

    sstack* P = (*S)->prev;
    free(*S);
    (*S) = P;
}

void destroy_stack(sstack* S)
{
    sstack* P;

    while (S != NULL)
    {
        P = S->prev;
        free(S);
        S = P;
    }
}

int peek(sstack* S)
{
    return S->val;
}

int peek_prev(sstack* S)
{
    if (S->prev==NULL)
        return -1;

    return S->prev->val;
}

void display_stack(sstack* S)
{
    int ctr = 0;
    sstack* P = S;

    while(P!=NULL){
        P = P->prev;
        ctr++;
    }
    while(S!=NULL){
        printf("\nstack[%d] = %d",--ctr,S->val);
        S =S->prev;
    }
}

sstack* prev(sstack* S)
{
    return S->prev;
}