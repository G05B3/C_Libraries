#include <stdio.h>
#include <stdlib.h>

static int *queue;
static int ffree; /* número de elementos existentes no acervo */
static int hsize;

#define exch(A, B) {int t = A; A = B; B = t; }


//Pode ser preciso trocar os sinais
int lessPri(int child1, int child2, int wt[]){
    if (wt[child1]>=wt[child2])
        return 1;
    return 0;
}

void FixUp(int Heap[], int Idx, int wt[])
{
    while (Idx > 0 && lessPri(Heap[(Idx - 1) / 2], Heap[Idx], wt))
    {
        exch(Heap[Idx], Heap[(Idx - 1) / 2]);
        Idx = (Idx - 1) / 2;
    }
}

void FixDown(int Heap[], int Idx, int N, int wt[])
{
    int Child; /* índice de um nó descendente */
    while (2 * Idx < N - 1)
    { /* enquanto não chegar às folhas */
        Child = 2 * Idx + 1;
        /* Selecciona o maior descendente. */
        /* Nota: se índice Child é N-1, então só há um descendente */
        if (Child < (N - 1) && lessPri(Heap[Child], Heap[Child + 1], wt))
            Child++;
        if (!lessPri(Heap[Idx], Heap[Child], wt))
            break; /* condição acervo */
        /* satisfeita */
        exch(Heap[Idx], Heap[Child]);
        /* continua a descer a árvore */
        Idx = Child;
    }
}

void PQinit(unsigned Size)
{
    queue = (int *)calloc(Size , sizeof(int));
    hsize = Size;
    ffree = 0;
}
void PQinsert(int I, int wt[])
{
    /* insere novo elemento no fim e restabelece ordenação com FixUp */
    if ((ffree + 1) < hsize)
    {
        queue[ffree] = I;
        FixUp(queue, ffree, wt);
        ffree++;
    }
}

int PQdelmin(int wt[])
{
    /* troca maior elemento com último da tabela e reordena com FixDown */
    exch(queue[0], queue[ffree - 1]);
    FixDown(queue, 0, ffree - 1, wt);
    /* ultimo elemento não considerado na reordenação */
    return queue[--ffree];
}

void PQDec(int w, int wt[]){
    
    int i;
    for (i=0; i < ffree; i++){
        if (w==queue[i])break;
    }
    FixUp(queue, i, wt);
}

int PQempty()
{
    return !ffree; //penso que free = 0 signifique fila vazia. - ass. Martim
}

void PQdestroy()
{
    free(queue);
}

/*
void PQsort(Item pTable[], int L, int R)
{
    int Aux;
    PQinit(R - L + 1);
    for (Aux = L; Aux <= R; Aux++)
        PQinsert(pTable[Aux]);
    for (Aux = R; Aux >= L; Aux--)
        pTable[Aux] = PQdelmax();
}
*/

//not needed
void Heapsort(int Table[], int L, int R, int wt[])
{
    int Aux, Top = R;
    /* Constroi acervo na própria tabela, executando FixDown na parte inferior */
    for (Aux = (L + R - 1) / 2; Aux >= L; Aux--)
        FixDown(Table, Aux, R, wt);
    /* Reordena a tabela, trocando o topo e exercendo FixDown na tabela com */
    /* dimensão –1 (na troca, o menor é já colocado na posição final) */
    while (Top > L)
    {
        exch(Table[L], Table[Top]);
        FixDown(Table, L, --Top, wt);
    }
}

