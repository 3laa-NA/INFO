#ifndef __FILE_H__
#define __FILE_H__
#include <stdlib.h>
#include <stdio.h>

typedef struct cell_file
{
    int val;
    struct cell_file* prec;
    struct cell_file* suiv;    
} Cellfile;

typedef struct int_file
{
    Cellfile *first;
    Cellfile *last;
} IntFile;

IntFile *creer_file();
void liberer_file(IntFile *file);
int est_vide(IntFile *file);
void enfiler(IntFile *file, int val);
int defiler(IntFile *file);


#endif