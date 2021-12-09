%{
#include <stdio.h>
#include <string.h>
#include "alpha.h"
#include "sym_table.h"
#include "generacion.h"

int yylex();
void yyerror();
extern FILE * out;
extern long yylin;
extern long yycol;
extern int yy_morph_error;
extern int etiqueta = 0;

stable* stable = stable_init();
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

%left TOK_IGUAL TOK_DISTINTO TOK_MENORIGUAL TOK_MAYORIGUAL TOK_MENOR TOK_MAYOR
%left TOK_MAS TOK_MENOS
%left TOK_ASTERISCO TOK_DIVISION 
%left TOK_AND TOK_OR
%left TOK_NOT
%%


programa: TOK_MAIN TOK_LLAVEIZQUIERDA declaraciones funciones sentencias TOK_LLAVEDERECHA {fprintf(out, ";R1:\t<programa> ::= main { <declaraciones> <funciones> <sentencias> }\n");};

declaraciones: declaracion {fprintf(out, ";R2:\t<declaraciones> ::= <declaracion>\n");}
             | declaracion declaraciones {fprintf(out, ";R3:\t<declaraciones> ::= <declaracion> <declaraciones>\n");}
             ;

declaracion: clase identificadores TOK_PUNTOYCOMA {
        char delim[] = ",";
        char *ptr = strtok($2.name, delim);

        while(ptr != NULL) {
            stable_insert(stable, ptr, $1.tipo);
            declarar_variable(out, ptr, $1.tipo, 1);
            ptr = strtok(ptr, delim);
        }
        
        fprintf(out, ";R4:\t<declaracion> ::= <clase> <identificadores> ;\n");
    }
    ;

clase: clase_escalar {fprintf(out, ";R5:\t<clase> ::= <clase_escalar>\n");}
     | clase_vector {fprintf(out, ";R7:\t<clase> ::= <clase_vector>\n");}
     ;

clase_escalar: tipo {fprintf(out, ";R9:\t<clase_escalar> ::= <tipo>\n");}
             ;

tipo: TOK_INT {fprintf(out, ";R10:\t<tipo> ::= int\n");}
    | TOK_BOOLEAN {fprintf(out, ";R11:\t<tipo> ::= boolean\n");}
    ;

clase_vector: TOK_ARRAY tipo TOK_CORCHETEIZQUIERDO constante_entera TOK_CORCHETEDERECHO {fprintf(out, ";R15:\t<clase_vector> ::= array <tipo> [<constante_entera>]\n");}
            ;

identificadores: identificador {
                    $$.nombre = $1.nombre
                    fprintf(out, ";R18:\t<identificadores> ::= <identificador>\n");
                }
               | identificador TOK_COMA identificadores {
                    $$.nombre = strcat($1.nombre, ",");
                    $$.nombre = strcat($$.nombre, $3.nombre);
                    fprintf(out, ";R19:\t<identificadores> ::= <identificador> , <identificadores>\n");
                   } 
               ;

funciones: funcion funciones {fprintf(out, ";R20:\t<funciones> ::= <funcion> <funciones>\n");}
         |  {fprintf(out, ";R21:\t<funciones> ::=\n");}
         ;

funcion: TOK_FUNCTION tipo identificador TOK_PARENTESISIZQUIERDO parametros_funcion TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA declaraciones_funcion sentencias TOK_LLAVEDERECHA {fprintf(out, ";R22:\t<funcion> ::= function <tipo> <identificador> ( <parametros_funcion> ) { <declaraciones_funcion> <sentencias> } \n");}
       ;

parametros_funcion: parametro_funcion resto_parametros_funcion {fprintf(out, ";R23:\t<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>\n");}
                  |  {fprintf(out, ";R24:\t<parametros_funcion> ::=\n");}   
                  ;

resto_parametros_funcion: TOK_PUNTOYCOMA parametro_funcion resto_parametros_funcion {fprintf(out, ";R25:\t<resto_parametros_funcion> ::= ; <parametro_funcion> <resto_parametros_funcion>\n");}
                        |  {fprintf(out, ";R26:\t<resto_parametros_funcion> ::=\n");}
                        ;

parametro_funcion: tipo identificador {fprintf(out, ";R27:\t<parametro_funcion> ::= <tipo> <identificador>\n");}
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

asignacion: identificador TOK_ASIGNACION exp {fprintf(out, ";R43:\t<asignacion> ::= <identificador> = <exp>\n");}
          | elemento_vector TOK_ASIGNACION exp {fprintf(out, ";R44:\t<asignacion> ::= <elemento_vector> = <exp>\n");}
          ;

elemento_vector: identificador TOK_CORCHETEIZQUIERDO exp TOK_CORCHETEDERECHO {fprintf(out, ";R48:\t<elemento_vector> = <identificador> [<exp>]\n");};

condicional: TOK_IF TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA {fprintf(out, ";R50:\t<condicional> ::= if ( <exp> ) { <sentencias> }\n");} 
           | TOK_IF TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA TOK_ELSE TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA {fprintf(out, ";R51:\t<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }\n");}
           ;

bucle: TOK_WHILE TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA {fprintf(out, ";R52:\t<bucle> ::= while ( <exp> ) { <sentencias> }\n");};

lectura: TOK_SCANF identificador {
                leer(out, $2.nombre, $2.tipo);
            };

escritura: TOK_PRINTF exp {
                escribir(out, $2.es_direccion, $2.tipo);
            };

retorno_funcion: TOK_RETURN exp {fprintf(out, ";R61:\t<retorno_funcion> ::= return <exp>\n");};

exp: exp TOK_MAS exp         {
        if($1.tipo == ENTERO && $3.tipo == ENTERO) {
            $$.tipo = ENTERO;
            $$.es_direccion = FALSE;
            sumar(out, $1.es_direccion, $2.es_direccion);
        } else {
            error_semantico("Operandos de la suma no enteros");
        }}  
   | exp TOK_MENOS exp       {
       if($1.tipo == ENTERO && $3.tipo == ENTERO) {
            $$.tipo = ENTERO;
            $$.es_direccion = FALSE;    
            restar(out, $1.es_direccion, $2.es_direccion);
        } else {
            error_semantico("Operandos de la resta no enteros");
        }}
   | exp TOK_DIVISION exp    {
        if($1.tipo == ENTERO && $3.tipo == ENTERO) {
            $$.es_direccion = FALSE;    
            $$.tipo = ENTERO;
            dividir(out, $1.es_direccion, $2.es_direccion);
        } else {
            error_semantico("Operandos de la división no enteros");
        }}
   | exp TOK_ASTERISCO exp   {
        if($1.tipo == ENTERO && $3.tipo == ENTERO) {
            $$.es_direccion = FALSE;    
            $$.tipo = ENTERO;
            multiplicar(out, $1.es_direccion, $2.es_direccion);
        } else {
            error_semantico("Operandos de la multiplicacion no enteros");
        }}
   | TOK_MENOS exp   {
        if($2.tipo == ENTERO) {
            $$.es_direccion = FALSE;    
            $$.tipo = ENTERO;
            cambiar_signo(out, $1.es_direccion);
        } else {
            "Valor negativo no entero"
        }}
   | exp TOK_AND exp {
        if($1.tipo == BOOLEAN && $3.tipo == BOOLEAN) {
            $$.es_direccion = FALSE;    
            $$.tipo = BOOLEAN;
            y(out, $1.es_direccion, $2.es_direccion);
        } else {
            error_semantico("Operandos de AND no booleanos");
        }} 
   | exp TOK_OR exp  {
        if($1.tipo == BOOLEAN && $3.tipo == BOOLEAN) {
            $$.es_direccion = FALSE;    
            $$.tipo = BOOLEAN;
            o(out, $1.es_direccion, $2.es_direccion);
        } else {
            error_semantico("Operandos de OR no boolenanos");
        }} 
   | TOK_NOT exp     {
        if($2.tipo == BOOLEAN) {
            $$.es_direccion = FALSE;    
            $$.tipo = BOOLEAN;
            no(out, $1.es_direccion, $2.es_direccion);
        } else {
            error_semantico("Negacion de valor no booleano");
        }}
   | identificador   {
            $$.es_direccion = TRUE;    
            $$.tipo = stable_search(stable, $1.nombre);
            escribir_operando(out, $1.nombre, TRUE);
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
                if($1.tipo == ENTERO && $3.tipo == ENTERO) {
                    $$.tipo = BOOLEAN;
                    $$.es_direccion = FALSE;
                    igual(out,$1.es_direccion, $3.es_direccion, etiqueta);
                    $$.etiqueta = etiqueta;
                    etiqueta++;
                } else {
                    error_semantico("Operandos de comparación no enteros");
                }} 
 	       | exp TOK_DISTINTO exp {
                if($1.tipo == ENTERO && $3.tipo == ENTERO) {
                    $$.tipo = BOOLEAN;
                    $$es_direccion = FALSE;
                    distinto(out,$1.es_direccion,$3.es_direccion,$$.etiqueta);
                    $$.etiqueta++;
                } else {
                    error_semantico("Operandos de comparación no enteros");
                }} 
 	       | exp TOK_MENORIGUAL exp {
                if($1.tipo == ENTERO && $3.tipo == ENTERO) {
                    $$.tipo = BOOLEAN;
                    $$.es_direccion = FALSE;
                    menor_igual(out,$1.es_direccion,$3.es_direccion,etiqueta);
                    $$.etiqueta = etiqueta;
                    etiqueta++;
                } else {
                    error_semantico("Operandos de comparación no enteros");
                }}  
 	       | exp TOK_MAYORIGUAL exp {
                if($1.tipo == ENTERO && $3.tipo == ENTERO) {
                    $$.tipo = BOOLEAN;
                    $$.es_direccion = FALSE;
                    mayor_igual(out,$1.es_direccion,$3.es_direccion,etiqueta);
                    $$.etiqueta = etiqueta;
                    etiqueta++;
                } else {
                    error_semantico("Operandos de comparación no enteros");
                }}  
 	       | exp TOK_MENOR exp  {
                if($1.tipo == ENTERO && $3.tipo == ENTERO) {
                    $$.tipo = BOOLEAN;
                    $$.es_direccion = FALSE;
                    menor(out,$1.es_direccion,$3.es_direccion,etiqueta);
                    $$.etiqueta = etiqueta;
                    etiqueta++;
                } else {
                    error_semantico("Operandos de comparación no enteros");
                }}  
 	       | exp TOK_MAYOR exp  {
                if($1.tipo == ENTERO && $3.tipo == ENTERO) {
                    $$.tipo = BOOLEAN;
                    $$.es_direccion = FALSE;
                    mayor(out,$1.es_direccion, $3.es_direccion,etiqueta);
                    $$.etiqueta = etiqueta;
                    etiqueta++;
                } else {
                    error_semantico("Operandos de comparación no enteros");
                }}  
           ;

constante: constante_logica {$$.valor = $1.valor; $$.tipo = BOOLEAN;}
         | constante_entera {$$.valor = $1.valor; $$.tipo = ENTERO; }
         ;

constante_logica: TOK_TRUE  {$$.tipo = BOOLEAN; $$.valor = yylval.atributos.valor;}
            	| TOK_FALSE {$$.tipo = BOOLEAN; $$.valor = yylval.atributos.valor;}
                ;
constante_entera: TOK_CONSTANTE_ENTERA {$$.tipo = ENTERO; $$.valor = yylval.atributos.valor;}
                ;

identificador: TOK_IDENTIFICADOR {$$.nombre = yylval.atributos.nombre;}
             ;

%%

void error_semantico (char *error_msg)
{
  fprintf(stderr,"****Error semantico en linea %d: %s\n", yylineno, error_msg);
}

void yyerror(const char * s) {
    if(!yy_morph_error) {
        printf("****Error sintactico en linea: %ld, columna: %ld\n\n\t%s\n", yylin, yycol, s);
    } else {
        printf("****Error morfologico\n");
    }
}
