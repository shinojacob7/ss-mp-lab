section .data 
    msg1 db "String1:"
    msg2 db "Palindrome "
    msg3 db "Not Palindrome"
    newline db 10

section .bss
    str1 resb 25
    count resb 1

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
    mov ecx, str1
    mov edx, 25
    int 0x80
    mov byte [str1 + eax - 1], 0

    mov esi, str1
    dec eax
    dec eax
    lea edi, [str1 + eax]

.find:
    cmp esi, edi
    jge .palindrome
    mov al, [esi]
    mov bl, [edi]
    cmp al, 'A'
    jl .skip1
    cmp al, 'Z'
    jg .skip1
    add al, 32
.skip1:
    cmp bl, 'A'
    jl .skip2
    cmp bl, 'Z'
    jg .skip2
    add bl, 32
.skip2:
    cmp al, bl
    jne .notp
    inc esi
    dec edi
    jmp .find

.notp:
    mov eax, 4
    mov ebx, 1
    mov ecx, msg3
    mov edx, 14
    int 0x80
    mov eax, 4
    mov ebx, 1
    mov ecx, newline
    mov edx, 1
    int 0x80
    jmp .exit

.palindrome:   
    mov eax, 4
    mov ebx, 1
    mov ecx, msg2
    mov edx, 11
    int 0x80
    mov eax, 4
    mov ebx, 1
    mov ecx, newline
    mov edx, 1
    int 0x80

.exit:
    mov eax, 1
    xor ebx, ebx
    int 0x80
