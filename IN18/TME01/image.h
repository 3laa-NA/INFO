#ifndef IMAGE_H_
#define IMAGE_H_

#define VAL(img,i,j) (img)->buff[(i)*(img)->w+(j)]

typedef struct _image_t
{
  unsigned long w; // largeur en pixels
  unsigned long h; // hauteur en pixels
  unsigned char *buff; // w x h octets correspondant aux pixels
} image_t;

image_t *creer_image();

void detruire_image(image_t *p);

void negatif(image_t *src);

void modifier_lumin(image_t *src, float pourcent);

image_t *rotation(image_t *src, int angle);

image_t *charger_image_pgm(char *nom_fichier);

int sauver_image_pgm(char *nom_fichier, image_t *img);

#endif
