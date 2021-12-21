segment .data
	msg_error_indice_vector db "Indice de vector fuera de rango", 0
	msg_error_division db "Error division por 0", 0
segment .bss
	__esp resd 1
	_x resd 1
	_resultado resd 1
segment .text
	global main
	extern malloc, free
	extern scan_int, print_int, scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string
_fibonacci:
	push ebp
	mov ebp, esp
	sub esp, 8
	lea eax, [ebp + 8]
	push dword eax
	push dword 0

	pop dword ebx
	pop dword eax
	mov dword eax, [eax]

	cmp eax, ebx
	je near igual0
	push dword 0
	jmp near fin_igual0
igual0:
	push dword 1
fin_igual0:
	pop eax
	cmp eax, 0
	je near fin_then0
	push dword 0
	pop eax
	mov esp, ebp
	pop ebp
	ret
	jmp near fin_ifelse0
fin_then0:
fin_ifelse0:
	lea eax, [ebp + 8]	
	push dword eax
	push dword 1

	pop dword ebx
	pop dword eax
	mov dword eax, [eax]

	cmp eax, ebx
	je near igual1
	push dword 0
	jmp near fin_igual1
igual1:
	push dword 1
fin_igual1:
	pop eax
	cmp eax, 0
	je near fin_then1
	push dword 1
	pop eax
	mov esp, ebp
	pop ebp
	ret
	jmp near fin_ifelse1
fin_then1:
fin_ifelse1:
	lea eax, [ebp + 8]
	push dword eax
	push dword 1

	pop dword ebx
	pop dword eax
	mov dword eax, [eax]
	sub eax, ebx
	push dword eax
	call _fibonacci
	add esp, 4
	push dword eax
	lea eax, [ebp - 4]
	push dword eax
	pop dword ebx
	pop dword eax
	mov dword [ebx], eax
	lea eax, [ebp + 8]	push dword eax
	push dword 2
	pop dword ebx
	pop dword eax
	mov dword eax, [eax]
	sub eax, ebx
	push dword eax
	call _fibonacci
	add esp, 4
	push dword eax
	lea eax, [ebp - 8]
	push dword eax
	pop dword ebx
	pop dword eax
	mov dword [ebx], eax
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
main:
	mov dword [__esp], esp
	push dword _x
	call scan_int
	add esp, 4
	push dword _x
	pop eax
	mov eax, [eax]
	push eax
	call _fibonacci
	add esp, 4
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
