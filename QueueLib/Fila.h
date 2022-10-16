#include "Item.h"

#ifndef FILA_H
#define FILA_H

typedef struct fila F;
void FilaDump(F*);
F *FilaInit(int);
int FilaEmpty(F*);
void FilaPut(F*, Item);
Item FilaGet(F*);
Item FilaPeek(F*);

#endif