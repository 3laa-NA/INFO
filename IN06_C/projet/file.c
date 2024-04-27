#include "file.h"

IntFile *creer_file()
{
    IntFile *file = (IntFile *)malloc(sizeof(IntFile));
    file->first = NULL;
    file->last = NULL;
    return file;
}

void liberer_file(IntFile *file)
{
    Cellfile *suiv;
    Cellfile *current = file->first;
    while (current != NULL)
    {
        suiv = current->suiv;
        free(current);
        current = suiv;
    }
    free(file);
}

int est_vide(IntFile *file)
{
    return file->first == NULL;
}

void enfiler(IntFile *file, int val)
{
    Cellfile *new = (Cellfile *)malloc(sizeof(Cellfile));
    new->val = val;
    new->suiv = file->first;
    new->prec = NULL;
    if (file->first != NULL)
        file->first->prec = new;
    else
        file->last = new;
    file->first = new;
}

int defiler(IntFile *file)
{
    if (file->last == NULL)
        return -1;
    if (file->last->prec == NULL)
        file->first = NULL;
    int val = file->last->val;
    Cellfile *cell = NULL;
    if (file->last->prec != NULL)
    {
        file->last->prec->suiv = NULL;
        cell = file->last->prec;
    }
    free(file->last);
    file->last = cell;
    return val;
}