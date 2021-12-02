#ifndef ALPHA_H
#define ALPHA_H

typedef enum{
    ENTERO,
    LOGICO
} tipo_var;

struct _atr_info {
	char* nombre;
	tipo_var tipo;
    int valor_entero;
    int es_direccion;
    int etiqueta;
};
typedef struct _atr_info atr_info;

#endif