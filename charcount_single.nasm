section .data 
    msg1 db "String:"
    msg2 db "character:"
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
    mov byte[str1+eax-1],0
    mov eax, 4
    mov ebx, 1
    mov ecx, msg2
    mov edx, 10
    int 0x80
    mov eax, 3
    mov ebx, 0
    mov ecx, chr
    mov edx, 1
    int 0x80
    mov esi, str1
    mov dl, [chr]
    mov ecx, 0
.loop:
    mov al,[esi]
    cmp al,0
    je .done
    cmp al,dl
    jne .skip
    inc ecx
.skip:
    inc esi
    jmp .loop
.done:
    mov eax, ecx
    add al, '0'
    mov [count],al
    mov eax, 4
    mov ebx, 1
    mov ecx, count
    mov edx, 1
    int 0x80
    mov eax, 1
    mov ebx, 0
    int 0x80