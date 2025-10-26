section .data 
    msg1 db "String1:"
    msg2 db "String2:"
    msg3 db "found"
    msg4 db "not found"
section .bss
    str1 resb 25
    str2 resb 25
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
    dec eax
    mov byte[str1+eax],0
    mov esi, eax
    mov eax, 4
    mov ebx, 1
    mov ecx, msg2
    mov edx, 8
    int 0x80
    mov eax, 3
    mov ebx, 0
    mov ecx, str2
    mov edx, 25
    int 0x80
    dec eax
    mov byte[str2+eax],0
    mov edi, eax
    mov ebx, 0
.loop1:
    mov eax, esi
    sub eax, edi
    cmp ebx, eax
    jg .not_found
    mov ecx, 0
.loop:
    cmp ecx, edi
    jge .found
    mov al, [str1 + ebx + ecx]  
    mov dl, [str2 + ecx]
    cmp al, dl  
    jne .mismatch
    inc ecx
    jmp .loop
.mismatch:
    inc ebx
    jmp .loop1
.found:
    mov eax, 4
    mov ebx, 1
    mov ecx, msg3
    mov edx, 5
    int 0x80
    jmp .done
.not_found:
    mov eax, 4
    mov ebx, 1
    mov ecx, msg4
    mov edx, 9
    int 0x80
.done:
    mov eax, 1
    mov ebx, 0
    int 0x80