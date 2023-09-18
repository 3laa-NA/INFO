#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "image.h"

#define TMP_STR_SIZE 256

image_t *creer_image()
{
  
  // Allouer de la mémoire pour la structure image_t
  image_t* img = (image_t*)malloc(sizeof(image_t));

  // Initialiser les champs de la structure
  img->w = 0;
  img->h = 0;

  return img;  
}

void detruire_image(image_t *p)
{
  
  free(p->buff);
  free(p);
  
}

void negatif(image_t *img)
{
  
  for (unsigned long i = 0; i < img->h * img->w; i++) {
    img->buff[i] = 255 - img->buff[i];
  }
  
}

void modifier_lumin(image_t *img, float pourcent)
{
  
  /* a completer */
  
}


image_t *rotation(image_t *src, int angle)
{
  image_t *dst;

  /* a completer */
  
  return dst;
}


image_t *charger_image_pgm(char *nom_fichier)
{
  FILE *f;
  image_t *img;
  unsigned int nb_ng;
  char tmp_str[TMP_STR_SIZE];
  enum format {BIN, ASCII} pgm_form;

  /* Ouverture du fichier en lecture */
  f=fopen(nom_fichier, "r");


  if (!f)
    {
      /* on ecrit sur le flux d'erreur */
      fprintf(stderr, "impossible d'ouvrir le fichier %s\n", nom_fichier);
      return NULL;
    }

  /* on lit une ligne en supprimant les eventuels commentaires */
  do
    fgets(tmp_str, TMP_STR_SIZE, f);
  while (*tmp_str == '#');

  /* on determine le format */
  if ( !strcmp(tmp_str, "P5\n"))
    pgm_form = BIN;
  else if ( !strcmp(tmp_str, "P2\n"))
    pgm_form = ASCII;
  else
    {
      fprintf(stderr, "format fichier non pgm\n");
      return NULL;
    }

  img = creer_image();

  /* on lit une ligne en supprimant les eventuels commentaires */
  do
    fgets(tmp_str, TMP_STR_SIZE, f);
  while (*tmp_str == '#');

  /* on determine la largeur et la hauteur de l'image */
  if (sscanf(tmp_str, "%ld %ld\n", &(img->w), &(img->h)) != 2)
    {
      /* si le sscanf n'a pas lu les deux entiers longs attendus: */
      fprintf(stderr, "format fichier non pgm\n");
      detruire_image(img);
      return NULL;
    }

  /* on lit une ligne en supprimant les eventuels commentaires */
  do
    fgets(tmp_str, TMP_STR_SIZE, f);
  while (*tmp_str == '#');

  /* on lit le niveau de gris */
  if (sscanf(tmp_str, " %d ", &nb_ng) != 1)
    {
      /* si le sscanf n'a pas lu l'entier attendu: */
      fprintf(stderr, "format fichier non pgm\n");
      detruire_image(img);
      return NULL;
    }

  if (nb_ng != 255)
    {
      fprintf(stderr, "Nombre de ng different de 255: erreur\n");
      detruire_image(img);
      return NULL;
    }

  /* on alloue l'espace pour stocker l'image */
  img->buff = (unsigned char *) malloc(img->w * img->h * sizeof (unsigned char));

  /* on lit l'image en prenant en compte le format */
  if ( pgm_form == BIN )
    {
      if (fread(img->buff, img->w, img->h, f) != img->h)
        {
          fprintf(stderr, "fichier image imcomplet!\n");
          return NULL;
        }
    }
  else
    {
      unsigned int i,j;
      unsigned char *p = img->buff;
      for ( i = 0; i < img->h; i++)
        for ( j = 0; j < img->w; j++)
          fscanf(f, "%hhu ", p++);
    }

  fclose(f);
  return img;
}

int sauver_image_pgm(char *nom_fichier, image_t *img)
{
  FILE *f;

  f=fopen(nom_fichier, "w");

  if (!f)
    {
      fprintf(stderr, "impossible d'ouvrir le fichier %s\n", nom_fichier);
      return 0;
    }

  fprintf(f, "P5\n");
  fprintf(f, "#Genere par guimp UPMC.\n");
  fprintf(f, "%ld %ld\n", img->w, img->h);
  fprintf(f, "255\n");

  fwrite(img->buff, img->w, img->h, f);
  fclose(f);
  return 1;
}


int main(void) {

  /* a completer */

  return 0;
}
