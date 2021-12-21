#ifndef ALPHA_H
#define ALPHA_H

#define MAX_N_TIPOS 8
#define MAX_N_CAT 8
#define MAX_N_DIM 4

// Categorias (CAT):
#define NONE 0
#define VARIABLE 1
#define PARAMETER 2
#define FUNCTION 3
#define LOCAL_VARIABLE 4

// Tipos:
#define INT 0
#define BOOLEAN 1

// Dimensiones (DIM):
#define ESCALAR 1
#define VECTOR 2

#define FALSE 0
#define TRUE 1

struct _atr_info {
	char nombre[1024];
	int tipo;
    char *valor;
    int es_direccion;
    int etiqueta;
    int n;
};
typedef struct _atr_info atr_info;

#endif