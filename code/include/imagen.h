#ifndef _IMAGEN
#define _IMAGEN

typedef struct {
	unsigned char r, g, b;
} RGB;

RGB *leer_ppm(const char *, int *, int *, int *);
void escribir_ppm(const char *, int, int, int, const RGB *);
void suavizar(int, int, RGB *);

#endif