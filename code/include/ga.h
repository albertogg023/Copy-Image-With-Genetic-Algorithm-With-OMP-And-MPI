#ifndef _GA
#define _GA

#include "imagen.h"

typedef struct {
	RGB *imagen;
	double fitness;
} Individuo;

void crear_imagen(const RGB *imagen_objetivo, int num_pixels, int ancho, int alto, int max,
	int num_generaciones, int tam_poblacion,
	int num_hilos_ini, int num_hilos_fit,
	RGB *imagen_resultado, const char *output_file);

void cruzar(Individuo *, Individuo *, Individuo *, Individuo *, int);
void fitness(const RGB *, Individuo *, int, int);
void mutar(Individuo *, int, int);

#endif
