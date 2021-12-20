#ifndef ALPHA_H
#define ALPHA_H

#define VARIABLE 1
#define PARAMETER 2
#define FUNCTION 3

#define INT 0
#define BOOLEAN 1

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
};
typedef struct _atr_info atr_info;

#endif