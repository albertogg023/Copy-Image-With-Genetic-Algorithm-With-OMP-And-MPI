#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <omp.h>
#include <time.h>
#include <sys/time.h>
#include "../include/imagen.h"
#include "../include/ga.h"

#define PRINT 0
#define PROB_MUTACION 1500 

static double mseconds() {
	struct timeval t;
	gettimeofday(&t, NULL);
	return t.tv_sec*1000 + t.tv_usec/1000;
}


unsigned int randomSeed;
#pragma omp threadprivate(randomSeed)

static int aleatorio(int max)
{
	return (rand_r(&randomSeed) % (max + 1)); // rand_r en lugar de rand puesto que se usa esta funcion en paralelo
}



void init_imagen_aleatoria(RGB *imagen, int max, int total)
{
//#pragma omp parallel for
	for (int i = 0; i < total; i++)
	{
		//! paralelizable
		//! schedule
		imagen[i].r = aleatorio(max);
		imagen[i].g = aleatorio(max);
		imagen[i].b = aleatorio(max);
	}
}

RGB *imagen_aleatoria(int max, int total)
{
	RGB *imagen = (RGB *)malloc(total * sizeof(RGB));
	assert(imagen);

	init_imagen_aleatoria(imagen, max, total);
	return imagen;
}

static int comp_fitness(const void *a, const void *b)
{
	/* qsort pasa un puntero al elemento que está ordenando */
	return (*(Individuo **)a)->fitness - (*(Individuo **)b)->fitness;
}

void crear_imagen(const RGB *imagen_objetivo, int num_pixels, int ancho, int alto, int max, int num_generaciones, int tam_poblacion, int num_hilos_ini, int num_hilos_fit, RGB *imagen_resultado, const char *output_file)
{

	int i, mutation_start;
	char output_file2[32];
	double diferencia_fitness, fitness_anterior, fitness_actual;

	/* INicializar srandr*/

	// A. Crear Poblacion Inicial (array de imagenes aleatorias)
	Individuo **poblacion = (Individuo **)malloc(tam_poblacion * sizeof(Individuo *)); //! PELIGRO PUNTERO A INDIVIDUO
	assert(poblacion);

	#pragma omp parallel
	{
		randomSeed = omp_get_thread_num() * time(NULL);
	}
	double ti = mseconds();
	#pragma omp parallel for num_threads(num_hilos_ini)
	for (i = 0; i < tam_poblacion; i++)
	{
		poblacion[i] = (Individuo *)malloc(sizeof(Individuo));
		poblacion[i]->imagen = imagen_aleatoria(max, num_pixels);
		fitness(imagen_objetivo, poblacion[i], num_pixels);
	}
	
	double tf = mseconds();
    double time_taken = (tf - ti)/1000;
	printf("%f\n",time_taken);
	//printf("Con n_hilos_ini = %d - - - - tarda %d\n", num_hilos_ini, time_taken);

	qsort(poblacion, tam_poblacion, sizeof(Individuo *), comp_fitness);
	// B. Evolucionar la Población (durante un número de generaciones)
	for (int g = 0; g < num_generaciones; g++)
	{
		fitness_anterior = poblacion[0]->fitness;

		// Promocionar a los descendientes de los individuos más aptos
		for (i = 0; i < (tam_poblacion / 2) - 1; i += 2)
		{
			//! Hay problemas al paralelizar por choques de la poblacion[i] y poblacion[i+1]
			cruzar(poblacion[i], poblacion[i + 1], poblacion[tam_poblacion / 2 + i], poblacion[tam_poblacion / 2 + i + 1], num_pixels);
		}

		// Mutar una parte de la individuos de la población (se decide que muten tam_poblacion/4)
		mutation_start = tam_poblacion / 4;



		#pragma omp parallel for
		for (i = mutation_start; i < tam_poblacion; i++)
		{
			mutar(poblacion[i], max, num_pixels);
		}

		// Recalcular Fitness

		for (i = 0; i < tam_poblacion; i++)
		{
			//! paralelizable
			fitness(imagen_objetivo, poblacion[i], num_pixels);
		}

		// Ordenar individuos según la función de bondad (menor "fitness" --> más aptos)
		

		
		qsort(poblacion, tam_poblacion, sizeof(Individuo *), comp_fitness);
		// La mejor solución está en la primera posición del array
		fitness_actual = poblacion[0]->fitness;

		diferencia_fitness = abs(fitness_actual - fitness_anterior);

		// Guardar cada 300 iteraciones para observar el progreso
		if (PRINT)
		{
			printf("Generacion %d - ", g);
			printf("Fitness = %e - ", fitness_actual);
			printf("Diferencia con Fitness Anterior = %.2e%c\n", diferencia_fitness, 37);
			if ((g % 300) == 0)
			{
				printf("%s\n", output_file);
				sprintf(output_file2, "image_%d.ppm", g);
				escribir_ppm(output_file2, ancho, alto, max, poblacion[0]->imagen);
			}
		}
	}

	// Devuelve Imagen Resultante
	memmove(imagen_resultado, poblacion[0]->imagen, num_pixels * sizeof(RGB));

	// Release memory
	for (i = 0; i < tam_poblacion; i++)
	{
		//! paralelizable
		free(poblacion[i]->imagen);
		free(poblacion[i]);
	}
	free(poblacion);
}

void cruzar(Individuo *padre1, Individuo *padre2, Individuo *hijo1, Individuo *hijo2, int num_pixels)
{
	// Elegir un "punto" de corte aleatorio a partir del cual se realiza el intercambio de los genes.
	//  Cruzar los genes de cada padre con su hijo
	//  Intercambiar los genes de cada hijo con los del otro padre

	//?  Generamos un numero aleatorio de entre 0 y el numero total de pixeles para elegir el lugar del corte a partir del cual se distribuyen los
	//? genes de un padre o del otro

	int random_number = aleatorio(num_pixels);

	#pragma omp parallel sections
	{
		#pragma omp section
		{
			for (int i = 0; i < random_number; i++)
			{

				//! paralelizable

				hijo1->imagen[i] = padre1->imagen[i];

				hijo2->imagen[i] = padre2->imagen[i];
			}
		}
		#pragma omp section
		{
			for (int i = random_number; i < num_pixels; i++)
			{
				//! paralelizable
				hijo1->imagen[i] = padre2->imagen[i];
				hijo2->imagen[i] = padre1->imagen[i];
			}
		}
	}
}

void fitness(const RGB *objetivo, Individuo *individuo, int num_pixels)
{
	// Determina la calidad del individuo (similitud con el objetivo)
	// calculando la suma de la distancia existente entre los pixeles

	double diff = 0.0;

	// TODO ejecutar los 3 por separado

	individuo->fitness = 0;


	//#pragma omp parallel for reduction(+: diff) schedule(guided)
	for (int i = 0; i < num_pixels; i++)
	{
		diff +=abs(objetivo[i].r - individuo->imagen[i].r) + abs(objetivo[i].g - individuo->imagen[i].g) + abs(objetivo[i].b - individuo->imagen[i].b);
	}
	
	individuo->fitness=diff;
}

void mutar(Individuo *actual, int max, int num_pixels)
{

	//#pragma omp parallel for schedule(guided)
	for (int i = 0; i < num_pixels; i++)
	{
		if (aleatorio(PROB_MUTACION)<= 1)
		{
			actual->imagen[i].r = aleatorio(max);
			actual->imagen[i].g = aleatorio(max);
			actual->imagen[i].b = aleatorio(max);
		}
	}
}