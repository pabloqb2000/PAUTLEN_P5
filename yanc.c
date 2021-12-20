#include <stdio.h>
#include <string.h>

int yylex();
int yyparse();
FILE * out = NULL;

int main(int argc, char ** argv) {
    extern FILE * yyin;
    printf("BIENVENIDO A NUESTRO COMPILADOR\n");
    yyin = fopen(argv[1], "r");
    if(yyin == NULL) {
        printf("Error al abrir el archivo de entrada %s\n", argv[1]);
        return 1;
    }
    out = fopen(argv[2], "w");
    if(out == NULL) {
        printf("Error al abrir el archivo de salida %s\n", argv[2]);
        fclose(yyin);
        return 1;
    }
    
    yyparse();

    fclose(yyin);
    fclose(out);
    return 0;
}
