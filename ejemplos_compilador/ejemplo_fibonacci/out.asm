segment .data
	error_division_0 db "Error division por 0!", 0
	error_tamano_array db "Indice de vector fuera de rango", 0

segment .bss
	__esp resd 1
;R10:	<tipo> ::= int
;R9:	<clase_escalar> ::= <tipo>
;R5:	<clase> ::= <clase_escalar>
	_x resd 1
	_resultado resd 1
;R18:	<identificadores> ::= <identificador>
;R19:	<identificadores> ::= <identificador> , <identificadores>
;R4:	<declaracion> ::= <clase> <identificadores> ;
;R2:	<declaraciones> ::= <declaracion>

segment .text
	global main
	extern malloc, free
	extern scan_int, print_int, scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string
;R10:	<tipo> ::= int
;R22_1:	<f_nombre> ::= function <tipo> <identificador> 
;R10:	<tipo> ::= int
;R27:	<parametro_funcion> ::= <tipo> <identificador>
;R26:	<resto_parametros_funcion> ::=
;R23:	<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>
;R10:	<tipo> ::= int
;R9:	<clase_escalar> ::= <tipo>
;R5:	<clase> ::= <clase_escalar>
;R18:	<identificadores> ::= <identificador>
;R19:	<identificadores> ::= <identificador> , <identificadores>
;R4:	<declaracion> ::= <clase> <identificadores> ;
;R2:	<declaraciones> ::= <declaracion>
;R28:	<declaraciones_funcion> ::= <declaraciones>

_fibonacci_funcion:
	push ebp
	mov ebp, esp
	sub esp, 8
;R22_3:	<f_declaracion> ::= <f_nombre> ( <parametros_funcion> ) { <declaraciones_funcion> 
	lea eax, [ebp+8]
	push dword eax
	push dword 0

	pop dword ebx
	pop dword eax
	mov dword eax, [eax]

	cmp eax, ebx
	je near IGUAL_1
	push dword 0
	jmp near NO_IGUAL_1
IGUAL_1:
	push dword 1
NO_IGUAL_1:
	pop eax
	cmp eax, 0
	je near ifthen_fin_then_0
	push dword 0
	pop eax
	mov esp, ebp
	pop ebp
	ret
;R61:	<retorno_funcion> ::= return <exp>
;R38:	<sentencia_simple> ::= <retorno_funcion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;R30:	<sentencias> ::= <sentencia>

ifthen_fin_then_0:
;R50:	<condicional> ::= if ( <exp> ) { <sentencias> }
;R40:	<bloque> ::= <condicional>
;R33:	<sentencias> ::= <bloque>
	lea eax, [ebp+8]
	push dword eax
	push dword 1

	pop dword ebx
	pop dword eax
	mov dword eax, [eax]

	cmp eax, ebx
	je near IGUAL_3
	push dword 0
	jmp near NO_IGUAL_3
IGUAL_3:
	push dword 1
NO_IGUAL_3:
	pop eax
	cmp eax, 0
	je near ifthen_fin_then_2
	push dword 1
	pop eax
	mov esp, ebp
	pop ebp
	ret
;R61:	<retorno_funcion> ::= return <exp>
;R38:	<sentencia_simple> ::= <retorno_funcion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;R30:	<sentencias> ::= <sentencia>

ifthen_fin_then_2:
;R50:	<condicional> ::= if ( <exp> ) { <sentencias> }
;R40:	<bloque> ::= <condicional>
;R33:	<sentencias> ::= <bloque>
	lea eax, [ebp+8]
	push dword eax
	push dword 1

	pop dword ebx
	pop dword eax
	mov dword eax, [eax]
	sub eax, ebx
	push dword eax
;R92:	<resto_lista_expresiones> ::=
;R89:	<lista_expresiones> ::= <exp> <resto_lista_expresiones>
	call _fibonacci_funcion
	add esp, 4
	push dword eax
;R88:	<exp> ::= <identificador> ( <lista_expresiones> )
	lea eax, [ebp - 4]
	push dword eax
	pop eax
	pop ebx
	mov [eax], ebx
;R43:	<asignacion> ::= <identificador> = <exp>
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
	lea eax, [ebp+8]
	push dword eax
	push dword 2

	pop dword ebx
	pop dword eax
	mov dword eax, [eax]
	sub eax, ebx
	push dword eax
;R92:	<resto_lista_expresiones> ::=
;R89:	<lista_expresiones> ::= <exp> <resto_lista_expresiones>
	call _fibonacci_funcion
	add esp, 4
	push dword eax
;R88:	<exp> ::= <identificador> ( <lista_expresiones> )
	lea eax, [ebp - 8]
	push dword eax
	pop eax
	pop ebx
	mov [eax], ebx
;R43:	<asignacion> ::= <identificador> = <exp>
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
	lea eax, [ebp - 4]
	push dword eax
	lea eax, [ebp - 8]
	push dword eax

	pop dword ebx
	mov dword ebx, [ebx]
	pop dword eax
	mov dword eax, [eax]
	add eax, ebx
	push dword eax
	pop eax
	mov esp, ebp
	pop ebp
	ret
;R61:	<retorno_funcion> ::= return <exp>
;R38:	<sentencia_simple> ::= <retorno_funcion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;R30:	<sentencias> ::= <sentencia>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R22_3:	<funcion> ::= <declaraciones_funcion> <sentencias> } 
;R21:	<funciones> ::=
;R20:	<funciones> ::= <funcion> <funciones>

main:
	mov dword [__esp], esp


	push dword _x
	call scan_int
	add esp, 4

;R35:	<sentencia_simple> ::= <lectura>
;R32:	<sentencia> ::= <sentencia_simple> ;
	push dword _x
	pop eax
	mov eax, [eax]
	push dword eax
;R92:	<resto_lista_expresiones> ::=
;R89:	<lista_expresiones> ::= <exp> <resto_lista_expresiones>
	call _fibonacci_funcion
	add esp, 4
	push dword eax
;R88:	<exp> ::= <identificador> ( <lista_expresiones> )
	pop dword eax
	mov dword [_resultado], eax
;R43:	<asignacion> ::= <identificador> = <exp>
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
	push dword _resultado

	pop eax

	mov eax, [eax]
	push dword eax

	call print_int
	add esp, 4
	call print_endofline
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;R30:	<sentencias> ::= <sentencia>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R31:	<sentencias> ::= <sentencia> <sentencias>


fin_programa:
	mov esp, [__esp]
	ret


division_entre_0_fin:
	push dword error_division_0
	call print_string
	add esp, 4
	call print_endofline
	jmp near fin_programa


tamano_array_fin:
	push dword error_tamano_array
	call print_string
	add esp, 4
	call print_endofline
	jmp near fin_programa
