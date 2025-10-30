section .data 
    msg1 db "Number1:"
    msg4 db "Number2:"
    msg2 db "Sum:"
    msg3 db "Difference:"
    newline db 10

section .bss
    num1 resb 10
    num2 resb 10
    result resb 10

section .text
    global _start
_start:    
    mov eax, 4
    mov ebx, 1
    mov ecx, msg1
    mov edx, 8
    int 0x80

    mov eax, 3
    mov ebx, 0
    mov ecx, num1
    mov edx, 10
    int 0x80
    mov byte [num1 + eax - 1], 0
    mov ecx, num1
    xor eax, eax
.read:
    mov bl, [ecx]
    cmp bl, 0
    je .done
    sub bl, '0'
    imul eax, eax, 10
    movzx ebx,bl
    add eax, ebx
    inc ecx
    jmp .read
.done:
    mov esi, eax
    mov eax, 4
    mov ebx, 1
    mov ecx, msg4
    mov edx, 8
    int 0x80

    mov eax, 3
    mov ebx, 0
    mov ecx, num2
    mov edx, 10
    int 0x80
    mov byte [num2 + eax - 1], 0
    mov ecx, num2
    xor eax, eax
.read1:
    mov bl, [ecx]
    cmp bl, 0
    je .done1
    sub bl, '0'
    imul eax, eax, 10
    movzx ebx,bl
    add eax, ebx
    inc ecx
    jmp .read1
.done1:
    mov edi, eax
    mov eax, 4
    mov ebx, 1
    mov ecx, msg2
    mov edx, 5
    int 0x80
    mov eax, edi
    add eax, esi
    mov ecx, result+9
    mov byte [ecx], 0
    mov ebx, 10
.convert_sum:
    mov edx, 0
    div ebx
    add dl, '0'
    dec ecx
    mov [ecx], dl
    test eax, eax
    jnz .convert_sum
    mov eax, 4
    mov ebx, 1
    mov edx, result+10
    sub edx, ecx
    mov ecx, ecx
    int 0x80
    mov eax, 4
    mov ebx, 1
    mov ecx, newline
    mov edx, 1
    int 0x80
    mov eax, 4
    mov ebx, 1
    mov ecx, msg3
    mov edx, 12
    int 0x80
    mov eax, esi
    sub eax, edi
    mov ecx, result+9
    mov byte [ecx], 0
    mov ebx, 10
.convert_diff:
    mov edx, 0
    div ebx
    add dl, '0' 
    dec ecx
    mov [ecx], dl
    test eax, eax
    jnz .convert_diff
    mov eax, 4
    mov ebx, 1  
    mov edx, result+10
    sub edx, ecx
    mov ecx, ecx
    int 0x80
    mov eax,1
    mov ebx,0
    int 0x80