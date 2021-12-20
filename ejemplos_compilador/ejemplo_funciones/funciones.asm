segment .data
	msg_error_indice_vector db "Indice de vector fuera de rango", 0
	msg_error_division db "Error division por 0", 0
segment .bss
	__esp resd 1
	_x resd 1
	_y resd 1
	_resultado resd 1
segment .text
	global main
	extern malloc, free
	extern scan_int, print_int, scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string
_suma:
	push ebp
	mov ebp, esp
	sub esp, 0
	lea eax, [ebp + 12]	
	push dword eax
	lea eax, [ebp + 8]	
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
main:
	mov dword [__esp], esp
	push dword 1
	pop dword eax
	mov dword [_x], eax
	push dword 3
	pop dword eax
	mov dword [_y], eax
	push dword _x
	pop eax
	mov eax, [eax]
	push eax
	push dword _y
	pop eax
	mov eax, [eax]
	push eax
	call _suma
	add esp, 8
	push dword eax
	pop dword eax
	mov dword [_resultado], eax
	push dword _resultado
	pop eax
	mov eax, [eax]
	push dword eax
	call print_int
	add esp, 4
	call print_endofline
	push dword _x
	pop eax
	mov eax, [eax]
	push eax
	push dword 1
	call _suma
	add esp, 8
	push dword eax
	pop dword eax
	mov dword [_resultado], eax
	push dword _resultado
	pop eax
	mov eax, [eax]
	push dword eax
	call print_int
	add esp, 4
	call print_endofline
	push dword 10
	push dword _y
	pop eax
	mov eax, [eax]
	push eax
	call _suma
	add esp, 8
	push dword eax
	pop dword eax
	mov dword [_resultado], eax
	push dword _resultado
	pop eax
	mov eax, [eax]
	push dword eax
	call print_int
	add esp, 4
	call print_endofline
	push dword 3
	push dword 5
	call _suma
	add esp, 8
	push dword eax
	pop dword eax
	mov dword [_resultado], eax
	push dword _resultado
	pop eax
	mov eax, [eax]
	push dword eax
	call print_int
	add esp, 4
	call print_endofline
	jmp near fin
fin_error_division: 
	push dword msg_error_division
	call print_string
	add esp, 4
	call print_endofline
	jmp near fin
fin_indice_fuera_rango: 
	push dword msg_error_indice_vector
	call print_string
	add esp, 4
	call print_endofline
	jmp near fin
fin: 
	mov esp, [__esp]
	ret
