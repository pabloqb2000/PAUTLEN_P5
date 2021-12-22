%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alpha.h"
#include "sym_table.h"
#include "generacion.h"

int yylex();
void yyerror();
void error_semantico (char *error_msg);
extern FILE * out;
extern long yylin;
extern long yycol;
extern int yy_morph_error;

stable* table;
int tipo_variable;
int etiqueta = 0;
int declaracion = NONE;
int n_parametros = 0;
int n_variables_locales = 0;
int tam_vector = 1;
int es_vector = ESCALAR;
int hay_retorno = FALSE;
int es_func = FALSE;
%}

%union {
	atr_info atributos;
}

%token TOK_MAIN 
%token TOK_INT 
%token TOK_BOOLEAN 
%token TOK_ARRAY 
%token TOK_FUNCTION 
%token TOK_IF 
%token TOK_ELSE 
%token TOK_WHILE 
%token TOK_SCANF 
%token TOK_PRINTF 
%token TOK_RETURN 

%token TOK_PUNTOYCOMA         
%token TOK_COMA               
%token TOK_PARENTESISIZQUIERDO
%token TOK_PARENTESISDERECHO  
%token TOK_CORCHETEIZQUIERDO  
%token TOK_CORCHETEDERECHO    
%token TOK_LLAVEIZQUIERDA     
%token TOK_LLAVEDERECHA       
%token TOK_ASIGNACION         
%token TOK_MAS                
%token TOK_MENOS              
%token TOK_DIVISION           
%token TOK_ASTERISCO          
%token TOK_AND                
%token TOK_OR                 
%token TOK_NOT                
%token TOK_IGUAL              
%token TOK_DISTINTO           
%token TOK_MENORIGUAL         
%token TOK_MAYORIGUAL         
%token TOK_MENOR              
%token TOK_MAYOR     

%token <atributos> TOK_IDENTIFICADOR 

%token <atributos> TOK_CONSTANTE_ENTERA
%token TOK_TRUE            
%token TOK_FALSE           

%token TOK_ERROR

%type <atributos> identificadores
%type <atributos> identificador
%type <atributos> tipo

%type <atributos> exp
%type <atributos> comparacion
%type <atributos> constante
%type <atributos> constante_logica
%type <atributos> constante_entera
%type <atributos> elemento_vector
%type <atributos> asignacion_vector

%type <atributos> funcion
%type <atributos> f_nombre
%type <atributos> f_parametros
%type <atributos> f_declaracion
%type <atributos> lista_expresiones
%type <atributos> resto_lista_expresiones
%type <atributos> if_tok
%type <atributos> if_exp
%type <atributos> if_else_exp
%type <atributos> while
%type <atributos> bucle_exp
%type <atributos> bucle

%left TOK_IGUAL TOK_DISTINTO TOK_MENORIGUAL TOK_MAYORIGUAL TOK_MENOR TOK_MAYOR
%left TOK_MAS TOK_MENOS
%left TOK_ASTERISCO TOK_DIVISION 
%left TOK_AND TOK_OR
%left TOK_NOT
%%

programa: prog_funciones sentencias TOK_LLAVEDERECHA {
    escribir_fin(out);
};

prog_funciones: prog_declaraciones funciones {
    escribir_inicio_main(out);
};

prog_declaraciones: prog_inicio declaraciones {
    escribir_segmento_codigo(out);
    declaracion = NONE;      
};

prog_inicio: TOK_MAIN TOK_LLAVEIZQUIERDA {
    table = stable_init();
    escribir_subseccion_data(out);
    escribir_cabecera_bss(out);
};

declaraciones: declaracion {}
             | declaracion declaraciones {}
             ;

declaracion: clase identificadores TOK_PUNTOYCOMA {
        es_vector = ESCALAR;
        tam_vector = 1;
            }
    ;

clase: clase_escalar {}
     | clase_vector {}
     ;

clase_escalar: tipo {}
             ;

tipo: TOK_INT {
        $$.tipo = INT;
        tipo_variable = INT;
        if(declaracion == NONE) declaracion = VARIABLE;
        }
    | TOK_BOOLEAN {
        $$.tipo = BOOLEAN;
        tipo_variable = BOOLEAN;
        if(declaracion == NONE) declaracion = VARIABLE;
        }
    ;

clase_vector: TOK_ARRAY tipo TOK_CORCHETEIZQUIERDO constante_entera TOK_CORCHETEDERECHO {
        tam_vector = atoi($4.valor);
        if(tam_vector < 1 || tam_vector > 64) {
            error_semantico("El tamanyo del vector excede los limites permitidos (1,64).");
        }
        es_vector = VECTOR;
    };

identificadores: identificador {
                                    }
               | identificador TOK_COMA identificadores {
                                       } 
               ;

funciones: funcion funciones {
    }
         |  {
    }
         ;

f_nombre: TOK_FUNCTION tipo TOK_IDENTIFICADOR {
        declaracion = PARAMETER;
        es_func = TRUE;
        strcpy($$.nombre, yylval.atributos.nombre);
        $$.tipo = $2.tipo;
    };

f_parametros: f_nombre TOK_PARENTESISIZQUIERDO parametros_funcion {
    strcpy($$.nombre, $1.nombre);
    $$.tipo = $1.tipo;
    declaracion = LOCAL_VARIABLE;
};

f_declaracion: f_parametros TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA declaraciones_funcion {    
            open_ambit(
                table,
                $1.nombre, 
                n_parametros*MAX_N_TIPOS*MAX_N_CAT*MAX_N_DIM + 
                FUNCTION*MAX_N_TIPOS +
                $1.tipo
            );
            
            declararFuncion(out, $1.nombre, n_variables_locales);

            declaracion = NONE;
        };

funcion: f_declaracion sentencias TOK_LLAVEDERECHA {
            char msg[1200];

            if(!hay_retorno) {
                sprintf(msg, "Funcion %s sin sentencia de retorno", $1.nombre);
                error_semantico(msg);
            }

            n_parametros = 0;
            n_variables_locales = 0;
            hay_retorno = FALSE;
            es_func = FALSE;
            close_ambit(table);
        };

parametros_funcion: parametro_funcion resto_parametros_funcion {}
                  |  {}   
                  ;

resto_parametros_funcion: TOK_PUNTOYCOMA parametro_funcion resto_parametros_funcion {}
                        |  {}
                        ;

parametro_funcion: tipo identificador {
                                }
                 ;

declaraciones_funcion: declaraciones {}
                     |  {}
                     ;

sentencias: sentencia {}
          | sentencia sentencias {}
          ;

sentencia: sentencia_simple TOK_PUNTOYCOMA {}
         | bloque {}
         ;

sentencia_simple: asignacion {}
                | lectura {}
                | escritura {}
                | retorno_funcion {}
                ;

bloque: condicional {}
      | bucle {}
      ;

asignacion: identificador TOK_ASIGNACION exp {
        int n = $1.tipo / (MAX_N_TIPOS * MAX_N_CAT * MAX_N_DIM);
        int dim = ($1.tipo / (MAX_N_TIPOS * MAX_N_CAT)) % MAX_N_DIM;
        int cat = ($1.tipo / MAX_N_TIPOS) % MAX_N_CAT;
        int tipo = $1.tipo % MAX_N_TIPOS;

        if(tipo != $3.tipo) {
            error_semantico("Asignacion incompatible");
        }

        if(dim != ESCALAR) {
            error_semantico("No se puede asignar un valor a un vector sin indicar su indice");
        }

        if (cat == VARIABLE) {
            asignar(out, $1.nombre, $3.es_direccion);
        } else if (cat == LOCAL_VARIABLE) {
            escribirVariableLocal(out, n+1);
            asignarDestinoEnPila(out, $3.es_direccion, FALSE);
        } else if (cat == PARAMETER) {
            escribirParametro(out, n, n_parametros);
            asignarDestinoEnPila(out, $3.es_direccion, FALSE);
        } else {
            error_semantico("No se puede asignar valores a una funcion");
        }

    }
    | asignacion_vector exp {
        if($1.tipo != $2.tipo % MAX_N_TIPOS) {
            error_semantico("Asignacion incompatible");
        }

        asignarDestinoEnPila(out, $2.es_direccion, TRUE);
    };

asignacion_vector: elemento_vector TOK_ASIGNACION {
        int n = $1.tipo / (MAX_N_TIPOS * MAX_N_CAT * MAX_N_DIM);
        int tipo = $1.tipo % MAX_N_TIPOS;
        $$.tipo = tipo;
        
        escribir_elemento_vector(out, $1.nombre, n, $1.es_direccion);    
    };

elemento_vector: identificador TOK_CORCHETEIZQUIERDO exp TOK_CORCHETEDERECHO {
        int dim = ($1.tipo / (MAX_N_TIPOS * MAX_N_CAT)) % MAX_N_DIM;
        if(dim != VECTOR) {
            error_semantico("Intento de indexacion de una variable que no es de tipo vector.");
        }

        strcpy($$.nombre, $1.nombre);
        $$.es_direccion = $3.es_direccion;
        $$.tipo = $1.tipo;

        if($3.tipo != INT) {
            error_semantico("El indice en una operacion de indexacion tiene que ser de tipo entero");
        }
    };

if_tok:  TOK_IF TOK_PARENTESISIZQUIERDO {
            $$.etiqueta = etiqueta;
            etiqueta++;
          };
          
if_exp: if_tok exp TOK_PARENTESISDERECHO {
            $$.etiqueta = $1.etiqueta;
            if ($2.tipo != BOOLEAN){
                error_semantico("Condicional con condicion de tipo int");
                return -1;
            }
            ifthen_inicio(out, $2.es_direccion, $1.etiqueta);
        };


condicional:  if_exp TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA{
                ifthen_fin(out, $1.etiqueta);
                              }
           |   if_else_exp TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA
              {
                ifthenelse_fin(out, $1.etiqueta);
                              };

if_else_exp: if_exp TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA TOK_ELSE {
            $$.etiqueta = $1.etiqueta; 
            ifthenelse_fin_then(out, $1.etiqueta);
          };
while: TOK_WHILE TOK_PARENTESISIZQUIERDO{
        while_inicio(out, etiqueta);
        $$.etiqueta = etiqueta;
        etiqueta++;
      };

bucle_exp:  while exp {
              if($2.tipo != BOOLEAN) {
                  error_semantico("Bucle con condicion de tipo int");
              }
              $$.etiqueta = $1.etiqueta;
              while_exp_pila(out, $2.es_direccion, $1.etiqueta);
            };

bucle:  bucle_exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA{
        while_fin(out, $1.etiqueta);
              };

lectura: TOK_SCANF identificador {
                leer(out, $2.nombre, $2.tipo % MAX_N_TIPOS);
            };

escritura: TOK_PRINTF exp {
                escribir(out, $2.es_direccion, $2.tipo);
            };

retorno_funcion: TOK_RETURN exp {
        if(!es_func) {
            error_semantico("Sentencia de retorno fuera del cuerpo de una función");
        }

        hay_retorno = TRUE;
        retornarFuncion(out, $2.es_direccion);
    };

exp: exp TOK_MAS exp        {
        if($1.tipo == INT && $3.tipo == INT) {
            $$.tipo = INT;
            $$.es_direccion = FALSE;
            sumar(out, $1.es_direccion, $3.es_direccion);
        } else {
            error_semantico("Operacion aritmetica con operandos boolean");
        }}  
   | exp TOK_MENOS exp       {
       if($1.tipo == INT && $3.tipo == INT) {
            $$.tipo = INT;
            $$.es_direccion = FALSE;    
            restar(out, $1.es_direccion, $3.es_direccion);
        } else {
            error_semantico("Operacion aritmetica con operandos boolean");
        }}
   | exp TOK_DIVISION exp    {
        if($1.tipo == INT && $3.tipo == INT) {
            $$.es_direccion = FALSE;    
            $$.tipo = INT;
            dividir(out, $1.es_direccion, $3.es_direccion);
        } else {
            error_semantico("Operacion aritmetica con operandos boolean");
        }}
   | exp TOK_ASTERISCO exp   {
        if($1.tipo == INT && $3.tipo == INT) {
            $$.es_direccion = FALSE;    
            $$.tipo = INT;
            multiplicar(out, $1.es_direccion, $3.es_direccion);
        } else {
            error_semantico("Operacion aritmetica con operandos boolean");
        }}
   | TOK_MENOS exp   {
        if($2.tipo == INT) {
            $$.es_direccion = FALSE;    
            $$.tipo = INT;
            cambiar_signo(out, $2.es_direccion);
        } else {
            error_semantico("Operacion aritmetica con operandos boolean");
        }}
   | exp TOK_AND exp {
        if($1.tipo == BOOLEAN && $3.tipo == BOOLEAN) {
            $$.es_direccion = FALSE;    
            $$.tipo = BOOLEAN;
            y(out, $1.es_direccion, $3.es_direccion);
        } else {
            error_semantico("Operacion logica con operandos int");
        }} 
   | exp TOK_OR exp  {
        if($1.tipo == BOOLEAN && $3.tipo == BOOLEAN) {
            $$.es_direccion = FALSE;    
            $$.tipo = BOOLEAN;
            o(out, $1.es_direccion, $3.es_direccion);
        } else {
            error_semantico("Operacion logica con operandos int");
        }} 
   | TOK_NOT exp     {
        if($2.tipo == BOOLEAN) {
            $$.es_direccion = FALSE;    
            $$.tipo = BOOLEAN;
            no(out, $2.es_direccion);
        } else {
            error_semantico("Operacion logica con operandos int");
        }}
   | identificador   {
        int n = $1.tipo / (MAX_N_TIPOS * MAX_N_CAT * MAX_N_DIM);
        int dim = ($1.tipo / (MAX_N_TIPOS * MAX_N_CAT)) % MAX_N_DIM;
        int cat = ($1.tipo / MAX_N_TIPOS) % MAX_N_CAT;
        int tipo = $1.tipo % MAX_N_TIPOS;

        if(dim != ESCALAR) {
            error_semantico("No se puede operar con vectores sin indice\n");
        }

        if (cat == VARIABLE) {
            escribir_operando(out, $1.nombre, TRUE);
        } else if (cat == LOCAL_VARIABLE) {
            escribirVariableLocal(out, n+1);
        } else {
            escribirParametro(out, n, n_parametros);
        }

        $$.es_direccion = TRUE;   
        $$.tipo = tipo;
        }
   | constante {
            $$.es_direccion = FALSE;    
            $$.tipo = $1.tipo;
            escribir_operando(out, $1.valor, FALSE);
        }
   | TOK_PARENTESISIZQUIERDO comparacion TOK_PARENTESISDERECHO {
            $$.es_direccion = FALSE;  
            $$.tipo = $2.tipo;
        }
   | TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO {
            $$.tipo = $2.tipo;
        }
   | elemento_vector {
        int n = $1.tipo / (MAX_N_TIPOS * MAX_N_CAT * MAX_N_DIM);
        int tipo = $1.tipo % MAX_N_TIPOS;
        
        $$.tipo = tipo;
        $$.es_direccion = TRUE;

        escribir_elemento_vector(out, $1.nombre, n, $1.es_direccion);
    }
   | identificador TOK_PARENTESISIZQUIERDO lista_expresiones TOK_PARENTESISDERECHO {   
        int n = $1.tipo / (MAX_N_TIPOS * MAX_N_CAT * MAX_N_DIM);
        int cat = ($1.tipo / MAX_N_TIPOS) % MAX_N_CAT;
        int tipo = $1.tipo % MAX_N_TIPOS;
        char msg[1200];
        $$.es_direccion = FALSE;  
        $$.tipo = tipo;  

        if(cat != FUNCTION){
            error_semantico("Llamada a objeto no invocable");
        }

        if(n != $3.n) {
            sprintf(msg, "Numero incorrecto de parametros en llamada a funcion. (Se tienen: %d, se esperaban: %d)", $3.n, n);
            error_semantico(msg);
        }

        llamarFuncion(out, $1.nombre, $3.n);

    };

lista_expresiones: resto_lista_expresiones {
        $$.n = $1.n; 
    }
    | {
        $$.n = 0; 
    };	
                 
resto_lista_expresiones: resto_lista_expresiones TOK_COMA exp {
        $$.n = $1.n+1; 
        operandoEnPilaAArgumento(out, $3.es_direccion);
    }
    | exp {
        $$.n = 1;
        operandoEnPilaAArgumento(out, $1.es_direccion);
        } 
    ;

comparacion: exp TOK_IGUAL exp {
                if($1.tipo == INT && $3.tipo == INT) {
                    $$.tipo = BOOLEAN;
                    $$.es_direccion = FALSE;
                    igual(out,$1.es_direccion, $3.es_direccion, etiqueta);
                    $$.etiqueta = etiqueta;
                    etiqueta++;
                } else {
                    error_semantico("Comparacion con operandos boolean");
                }} 
 	       | exp TOK_DISTINTO exp {
                if($1.tipo == INT && $3.tipo == INT) {
                    $$.tipo = BOOLEAN;
                    $$.es_direccion = FALSE;
                    distinto(out,$1.es_direccion,$3.es_direccion,$$.etiqueta);
                    $$.etiqueta++;
                } else {
                    error_semantico("Comparacion con operandos boolean");
                }} 
 	       | exp TOK_MENORIGUAL exp {
                if($1.tipo == INT && $3.tipo == INT) {
                    $$.tipo = BOOLEAN;
                    $$.es_direccion = FALSE;
                    menor_igual(out,$1.es_direccion,$3.es_direccion,etiqueta);
                    $$.etiqueta = etiqueta;
                    etiqueta++;
                } else {
                    error_semantico("Comparacion con operandos boolean");
                }}  
 	       | exp TOK_MAYORIGUAL exp {
                if($1.tipo == INT && $3.tipo == INT) {
                    $$.tipo = BOOLEAN;
                    $$.es_direccion = FALSE;
                    mayor_igual(out,$1.es_direccion,$3.es_direccion,etiqueta);
                    $$.etiqueta = etiqueta;
                    etiqueta++;
                } else {
                    error_semantico("Comparacion con operandos boolean");
                }}  
 	       | exp TOK_MENOR exp  {
                if($1.tipo == INT && $3.tipo == INT) {
                    $$.tipo = BOOLEAN;
                    $$.es_direccion = FALSE;
                    menor(out,$1.es_direccion,$3.es_direccion,etiqueta);
                    $$.etiqueta = etiqueta;
                    etiqueta++;
                } else {
                    error_semantico("Comparacion con operandos boolean");
                }}  
 	       | exp TOK_MAYOR exp  {
                if($1.tipo == INT && $3.tipo == INT) {
                    $$.tipo = BOOLEAN;
                    $$.es_direccion = FALSE;
                    mayor(out,$1.es_direccion, $3.es_direccion,etiqueta);
                    $$.etiqueta = etiqueta;
                    etiqueta++;
                } else {
                    error_semantico("Comparacion con operandos boolean");
                }}
           ;

constante: constante_logica {$$.valor = $1.valor; $$.tipo = BOOLEAN;}
         | constante_entera {$$.valor = $1.valor; $$.tipo = INT; }
         ;

constante_logica: TOK_TRUE  {$$.tipo = BOOLEAN; $$.valor = yylval.atributos.valor;}
            	| TOK_FALSE {$$.tipo = BOOLEAN; $$.valor = yylval.atributos.valor;}
                ;
constante_entera: TOK_CONSTANTE_ENTERA {$$.tipo = INT; $$.valor = yylval.atributos.valor;}
                ;

identificador: TOK_IDENTIFICADOR {
        char msg[1200];
        if(declaracion == VARIABLE) {
            if(stable_insert(
                table, 
                yylval.atributos.nombre,
                    tam_vector * MAX_N_TIPOS * MAX_N_CAT * MAX_N_DIM + 
                    es_vector * MAX_N_CAT * MAX_N_TIPOS +
                    VARIABLE * MAX_N_TIPOS +
                    tipo_variable) == ERROR) {
                sprintf(msg, "Declaracion duplicada (%s)", yylval.atributos.nombre);
                error_semantico(msg);
            }
            
            declarar_variable(out, yylval.atributos.nombre, tipo_variable, tam_vector);
            
        } else if (declaracion == NONE) {
            strcpy($$.nombre, yylval.atributos.nombre);
            $$.tipo = stable_search(table, yylval.atributos.nombre);
            if($$.tipo == ERROR) {
                sprintf(msg, "Acceso a variable no declarada (%s)", yylval.atributos.nombre);
                error_semantico(msg);
            }
            $$.es_direccion = TRUE;
        } else if (declaracion == PARAMETER) {
            if(stable_insert(
                table, 
                yylval.atributos.nombre,
                    n_parametros * MAX_N_CAT * MAX_N_TIPOS * MAX_N_DIM +
                    es_vector * MAX_N_CAT * MAX_N_TIPOS +
                    PARAMETER * MAX_N_TIPOS +
                    tipo_variable) == ERROR) {
                sprintf(msg, "Declaracion duplicada (%s)", yylval.atributos.nombre);
                error_semantico(msg);
            }
            n_parametros++;
        } else if (declaracion == LOCAL_VARIABLE) {
            if(tam_vector > 1) {
                error_semantico("Variable local de tipo no escalar.");
            }
            if(stable_insert(
                table, 
                yylval.atributos.nombre,
                    n_variables_locales * MAX_N_CAT * MAX_N_TIPOS * MAX_N_DIM +
                    es_vector * MAX_N_CAT * MAX_N_TIPOS +
                    LOCAL_VARIABLE * MAX_N_TIPOS +
                    tipo_variable) == ERROR) {
                sprintf(msg, "Declaracion duplicada (%s)", yylval.atributos.nombre);
                error_semantico(msg);
            }
            n_variables_locales++;
        }
    };

%%

void error_semantico (char *error_msg)
{
  fprintf(stderr,"****Error semantico en linea %ld: %s\n", yylin, error_msg);
}

void yyerror(const char * s) {
    if(!yy_morph_error) {
        fprintf(stderr, "****Error sintactico en linea: %ld, columna: %ld\n\n\t%s\n", yylin, yycol, s);
    } else {
        fprintf(stderr, "****Error morfologico\n");
    }
}
