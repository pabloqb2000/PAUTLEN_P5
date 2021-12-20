%{
#include <stdio.h>
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

%type <atributos> funcion
%type <atributos> f_nombre
%type <atributos> f_parametros
%type <atributos> f_declaracion
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
};

prog_inicio: TOK_MAIN TOK_LLAVEIZQUIERDA {
    table = stable_init();
    escribir_subseccion_data(out);
    escribir_cabecera_bss(out);
};

declaraciones: declaracion {fprintf(out, ";R2:\t<declaraciones> ::= <declaracion>\n");}
             | declaracion declaraciones {fprintf(out, ";R3:\t<declaraciones> ::= <declaracion> <declaraciones>\n");}
             ;

declaracion: clase identificadores TOK_PUNTOYCOMA {
        declaracion = NONE;      
        fprintf(out, ";R4:\t<declaracion> ::= <clase> <identificadores> ;\n");
    }
    ;

clase: clase_escalar {fprintf(out, ";R5:\t<clase> ::= <clase_escalar>\n");}
     | clase_vector {fprintf(out, ";R7:\t<clase> ::= <clase_vector>\n");}
     ;

clase_escalar: tipo {fprintf(out, ";R9:\t<clase_escalar> ::= <tipo>\n");}
             ;

tipo: TOK_INT {
        tipo_variable = INT;
        if(declaracion != LOCAL_VARIABLE && declaracion != PARAMETER) declaracion = VARIABLE;
        fprintf(out, ";R10:\t<tipo> ::= int\n");}
    | TOK_BOOLEAN {
        tipo_variable = BOOLEAN;
        if(declaracion != LOCAL_VARIABLE && declaracion != PARAMETER) declaracion = VARIABLE;
        fprintf(out, ";R11:\t<tipo> ::= boolean\n");}
    ;

clase_vector: TOK_ARRAY tipo TOK_CORCHETEIZQUIERDO constante_entera TOK_CORCHETEDERECHO {fprintf(out, ";R15:\t<clase_vector> ::= array <tipo> [<constante_entera>]\n");}
            ;

identificadores: identificador {
                    fprintf(out, ";R18:\t<identificadores> ::= <identificador>\n");
                }
               | identificador TOK_COMA identificadores {
                    fprintf(out, ";R19:\t<identificadores> ::= <identificador> , <identificadores>\n");
                   } 
               ;

funciones: funcion funciones {
    fprintf(out, ";R20:\t<funciones> ::= <funcion> <funciones>\n");}
         |  {
    fprintf(out, ";R21:\t<funciones> ::=\n");}
         ;

f_nombre: TOK_FUNCTION tipo TOK_IDENTIFICADOR {
            open_ambit(table, yylval.atributos.nombre, FUNCTION*MAX_N_TIPOS + $2.tipo);
            declaracion = PARAMETER;
            strcpy($$.nombre, yylval.atributos.nombre);
            fprintf(out, ";R22_1:\t<f_nombre> ::= function <tipo> <identificador> \n");
        };

f_parametros: f_nombre TOK_PARENTESISIZQUIERDO parametros_funcion {

    declaracion = LOCAL_VARIABLE;
};

f_declaracion: f_parametros TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA declaraciones_funcion {
            declararFuncion(out, $1.nombre, n_variables_locales);

            declaracion = NONE;
            fprintf(out, ";R22_3:\t<f_declaracion> ::= <f_nombre> ( <parametros_funcion> ) { <declaraciones_funcion> \n");
        };

funcion: f_declaracion sentencias TOK_LLAVEDERECHA {
            n_parametros = 0;
            n_variables_locales = 0;
            close_ambit(table);
            fprintf(out, ";R22_3:\t<funcion> ::= <declaraciones_funcion> <sentencias> } \n");
            };

parametros_funcion: parametro_funcion resto_parametros_funcion {fprintf(out, ";R23:\t<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>\n");}
                  |  {fprintf(out, ";R24:\t<parametros_funcion> ::=\n");}   
                  ;

resto_parametros_funcion: TOK_PUNTOYCOMA parametro_funcion resto_parametros_funcion {fprintf(out, ";R25:\t<resto_parametros_funcion> ::= ; <parametro_funcion> <resto_parametros_funcion>\n");}
                        |  {fprintf(out, ";R26:\t<resto_parametros_funcion> ::=\n");}
                        ;

parametro_funcion: tipo identificador {
                fprintf(out, ";R27:\t<parametro_funcion> ::= <tipo> <identificador>\n");
                }
                 ;

declaraciones_funcion: declaraciones {fprintf(out, ";R28:\t<declaraciones_funcion> ::= <declaraciones>\n");}
                     |  {fprintf(out, ";R29:\t<declaraciones_funcion> ::=\n");}
                     ;

sentencias: sentencia {fprintf(out, ";R30:\t<sentencias> ::= <sentencia>\n");}
          | sentencia sentencias {fprintf(out, ";R31:\t<sentencias> ::= <sentencia> <sentencias>\n");}
          ;

sentencia: sentencia_simple TOK_PUNTOYCOMA {fprintf(out, ";R32:\t<sentencia> ::= <sentencia_simple> ;\n");}
         | bloque {fprintf(out, ";R33:\t<sentencias> ::= <bloque>\n");}
         ;

sentencia_simple: asignacion {fprintf(out, ";R34:\t<sentencia_simple> ::= <asignacion>\n");}
                | lectura {fprintf(out, ";R35:\t<sentencia_simple> ::= <lectura>\n");}
                | escritura {fprintf(out, ";R36:\t<sentencia_simple> ::= <escritura>\n");}
                | retorno_funcion {fprintf(out, ";R38:\t<sentencia_simple> ::= <retorno_funcion>\n");}
                ;

bloque: condicional {fprintf(out, ";R40:\t<bloque> ::= <condicional>\n");}
      | bucle {fprintf(out, ";R41:\t<bloque> ::= <bucle>\n");}
      ;

asignacion: identificador TOK_ASIGNACION exp {
        int n = $1.tipo / (MAX_N_TIPOS * MAX_N_CAT);
        int cat = ($1.tipo / MAX_N_TIPOS) % MAX_N_CAT;
        int tipo = $1.tipo % MAX_N_TIPOS;
        printf("%d, %d, %d\n", n, cat, tipo);

        if (cat == VARIABLE) {
            asignar(out, $1.nombre, $3.es_direccion);
        } else if (cat == LOCAL_VARIABLE) {
            escribirVariableLocal(out, n);
            asignarDestinoEnPila(out, $3.es_direccion);
        } else if (cat == PARAMETER) {
            escribirParametro(out, n, n_parametros);
            asignarDestinoEnPila(out, $3.es_direccion);
        } else {
            error_semantico("No se puede asignar valores a una funcion\n");
        }

        fprintf(out, ";R43:\t<asignacion> ::= <identificador> = <exp>\n");
    }
    | elemento_vector TOK_ASIGNACION exp {
        fprintf(out, ";R44:\t<asignacion> ::= <elemento_vector> = <exp>\n");}
    ;

elemento_vector: identificador TOK_CORCHETEIZQUIERDO exp TOK_CORCHETEDERECHO {fprintf(out, ";R48:\t<elemento_vector> = <identificador> [<exp>]\n");};

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
                fprintf(out, ";R50:\t<condicional> ::= if ( <exp> ) { <sentencias> }\n");
              }
           |   if_else_exp TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA
              {
                ifthenelse_fin(out, $1.etiqueta);
                fprintf(out, ";R51:\t<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }\n");
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
              $$.etiqueta = $1.etiqueta;
              while_exp_pila(out, $2.es_direccion, $1.etiqueta);
            };

bucle:  bucle_exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA{
        while_fin(out, $1.etiqueta);
        fprintf(out, ";R52:\t<bucle> ::= while ( <exp> ) { <sentencias> }\n");
      };

lectura: TOK_SCANF identificador {
                leer(out, $2.nombre, $2.tipo);
            };

escritura: TOK_PRINTF exp {
                escribir(out, $2.es_direccion, $2.tipo);
            };

retorno_funcion: TOK_RETURN exp {
    retornarFuncion(out, $2.es_direccion);
    fprintf(out, ";R61:\t<retorno_funcion> ::= return <exp>\n");};

exp: exp TOK_MAS exp        {
        if($1.tipo == INT && $3.tipo == INT) {
            $$.tipo = INT;
            $$.es_direccion = FALSE;
            sumar(out, $1.es_direccion, $3.es_direccion);
        } else {
            error_semantico("Operandos de la suma no enteros");
        }}  
   | exp TOK_MENOS exp       {
       if($1.tipo == INT && $3.tipo == INT) {
            $$.tipo = INT;
            $$.es_direccion = FALSE;    
            restar(out, $1.es_direccion, $3.es_direccion);
        } else {
            error_semantico("Operandos de la resta no enteros");
        }}
   | exp TOK_DIVISION exp    {
        if($1.tipo == INT && $3.tipo == INT) {
            $$.es_direccion = FALSE;    
            $$.tipo = INT;
            dividir(out, $1.es_direccion, $3.es_direccion);
        } else {
            error_semantico("Operandos de la división no enteros");
        }}
   | exp TOK_ASTERISCO exp   {
        if($1.tipo == INT && $3.tipo == INT) {
            $$.es_direccion = FALSE;    
            $$.tipo = INT;
            multiplicar(out, $1.es_direccion, $3.es_direccion);
        } else {
            error_semantico("Operandos de la multiplicacion no enteros");
        }}
   | TOK_MENOS exp   {
        if($2.tipo == INT) {
            $$.es_direccion = FALSE;    
            $$.tipo = INT;
            cambiar_signo(out, $2.es_direccion);
        } else {
            error_semantico("Valor negativo no entero");
        }}
   | exp TOK_AND exp {
        if($1.tipo == BOOLEAN && $3.tipo == BOOLEAN) {
            $$.es_direccion = FALSE;    
            $$.tipo = BOOLEAN;
            y(out, $1.es_direccion, $3.es_direccion);
        } else {
            error_semantico("Operandos de AND no booleanos");
        }} 
   | exp TOK_OR exp  {
        if($1.tipo == BOOLEAN && $3.tipo == BOOLEAN) {
            $$.es_direccion = FALSE;    
            $$.tipo = BOOLEAN;
            o(out, $1.es_direccion, $3.es_direccion);
        } else {
            error_semantico("Operandos de OR no boolenanos");
        }} 
   | TOK_NOT exp     {
        if($2.tipo == BOOLEAN) {
            $$.es_direccion = FALSE;    
            $$.tipo = BOOLEAN;
            no(out, $2.es_direccion);
        } else {
            error_semantico("Negacion de valor no booleano");
        }}
   | TOK_IDENTIFICADOR   {
        int n = $1.tipo % (MAX_N_TIPOS * MAX_N_CAT);
        int cat = ($1.tipo / MAX_N_TIPOS) % MAX_N_TIPOS * MAX_N_CAT;
        int tipo = $1.tipo % MAX_N_TIPOS;

        if (cat == VARIABLE) {
            escribir_operando(out, $1.nombre, TRUE);
        } else if (cat == LOCAL_VARIABLE) {
            escribirVariableLocal(out, n);
        } else {
            escribirParametro(out, n, n_parametros);
        }

        $$.es_direccion = TRUE;   
        $$.tipo = tipo;
        }
   | constante       {
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
   | elemento_vector {fprintf(out, ";R85:\t<exp> ::= <elemento_vector>\n");}
   | identificador TOK_PARENTESISIZQUIERDO lista_expresiones TOK_PARENTESISDERECHO {fprintf(out, ";R88:\t<exp> ::= <identificador> ( <lista_expresiones> )\n");}
   ;

lista_expresiones: exp resto_lista_expresiones {fprintf(out, ";R89:\t<lista_expresiones> ::= <exp> <resto_lista_expresiones>\n");}
	             | {fprintf(out, ";R90:\t<lista_expresiones> ::=\n");} 
                 ;	
                 
resto_lista_expresiones: TOK_COMA exp resto_lista_expresiones {fprintf(out, ";R91:\t<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>\n");}
	                   | {fprintf(out, ";R92:\t<resto_lista_expresiones> ::=\n");} 
                       ;

comparacion: exp TOK_IGUAL exp {
                if($1.tipo == INT && $3.tipo == INT) {
                    $$.tipo = BOOLEAN;
                    $$.es_direccion = FALSE;
                    igual(out,$1.es_direccion, $3.es_direccion, etiqueta);
                    $$.etiqueta = etiqueta;
                    etiqueta++;
                } else {
                    error_semantico("Operandos de comparación no enteros");
                }} 
 	       | exp TOK_DISTINTO exp {
                if($1.tipo == INT && $3.tipo == INT) {
                    $$.tipo = BOOLEAN;
                    $$.es_direccion = FALSE;
                    distinto(out,$1.es_direccion,$3.es_direccion,$$.etiqueta);
                    $$.etiqueta++;
                } else {
                    error_semantico("Operandos de comparación no enteros");
                }} 
 	       | exp TOK_MENORIGUAL exp {
                if($1.tipo == INT && $3.tipo == INT) {
                    $$.tipo = BOOLEAN;
                    $$.es_direccion = FALSE;
                    menor_igual(out,$1.es_direccion,$3.es_direccion,etiqueta);
                    $$.etiqueta = etiqueta;
                    etiqueta++;
                } else {
                    error_semantico("Operandos de comparación no enteros");
                }}  
 	       | exp TOK_MAYORIGUAL exp {
                if($1.tipo == INT && $3.tipo == INT) {
                    $$.tipo = BOOLEAN;
                    $$.es_direccion = FALSE;
                    mayor_igual(out,$1.es_direccion,$3.es_direccion,etiqueta);
                    $$.etiqueta = etiqueta;
                    etiqueta++;
                } else {
                    error_semantico("Operandos de comparación no enteros");
                }}  
 	       | exp TOK_MENOR exp  {
                if($1.tipo == INT && $3.tipo == INT) {
                    $$.tipo = BOOLEAN;
                    $$.es_direccion = FALSE;
                    menor(out,$1.es_direccion,$3.es_direccion,etiqueta);
                    $$.etiqueta = etiqueta;
                    etiqueta++;
                } else {
                    error_semantico("Operandos de comparación no enteros");
                }}  
 	       | exp TOK_MAYOR exp  {
                if($1.tipo == INT && $3.tipo == INT) {
                    $$.tipo = BOOLEAN;
                    $$.es_direccion = FALSE;
                    mayor(out,$1.es_direccion, $3.es_direccion,etiqueta);
                    $$.etiqueta = etiqueta;
                    etiqueta++;
                } else {
                    char str[128];
                    sprintf(str, "Operandos de comparación no enteros (%d y %d)", $1.tipo, $3.tipo);
                    error_semantico(str);
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
        if(declaracion == VARIABLE) {
            if(stable_insert(table, yylval.atributos.nombre, VARIABLE * MAX_N_TIPOS + tipo_variable) == ERROR) {
                error_semantico("El identificador ya existe.");
            } else {
                declarar_variable(out, yylval.atributos.nombre, tipo_variable, 1);
            }
        } else if (declaracion == NONE) {
            strcpy($$.nombre, yylval.atributos.nombre);
            $$.tipo = stable_search(table, yylval.atributos.nombre); 
            $$.es_direccion = TRUE;
        } else if (declaracion == PARAMETER) {
            if(stable_insert(table, yylval.atributos.nombre, 
                n_parametros*MAX_N_CAT*MAX_N_TIPOS + PARAMETER * MAX_N_TIPOS + tipo_variable) == ERROR) {
                error_semantico("El identificador ya existe.");
            }
            n_parametros++;
        } else if (declaracion == LOCAL_VARIABLE) {
            if(stable_insert(table, yylval.atributos.nombre,
                n_variables_locales*MAX_N_CAT*MAX_N_TIPOS + LOCAL_VARIABLE * MAX_N_TIPOS + tipo_variable) == ERROR) {
                error_semantico("El identificador ya existe.");
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
