section .data 
    msg1 db "String:"
    msg2 db " : "
    newline db 10

section .bss
    str1 resb 25
    chr resb 1
    count resb 1

section .text
    global _start
_start:    
    mov eax, 4
    mov ebx, 1
    mov ecx, msg1
    mov edx, 7
    int 0x80

    mov eax, 3
    mov ebx, 0
    mov ecx, str1
    mov edx, 25
    int 0x80
    mov byte [str1 + eax - 1], 0

    mov edi, str1

.outer_loop:
    mov dl, [edi]
    cmp dl, 0
    je .exit
    mov esi, str1
    xor ecx, ecx

.inner_loop:
    mov al, [esi]
    cmp al, 0
    je .after_count
    cmp al, dl
    jne .skip
    inc ecx
.skip:
    inc esi
    jmp .inner_loop

.after_count:
    mov eax, ecx
    add al, '0'
    mov [count], al
    mov [chr],dl
    
    mov eax, 4
    mov ebx, 1
    mov ecx, chr
    mov edx, 1
    int 0x80

    mov eax, 4
    mov ebx, 1
    mov ecx, msg2
    mov edx, 3
    int 0x80
    
    mov eax, 4
    mov ebx, 1
    mov ecx, count
    mov edx, 1
    int 0x80

    mov eax, 4
    mov ebx, 1
    mov ecx, newline
    mov edx, 1
    int 0x80

    inc edi
    jmp .outer_loop

.exit:
    mov eax, 1
    xor ebx, ebx
    int 0x80
