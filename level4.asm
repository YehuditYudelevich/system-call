section .data
    filename db 'level4.txt', 0
    msg db 'Can we write to a file?', 0xA
    msg_len equ $ - msg

section .text
    global _start

_start:
    mov eax, 5
    mov ebx, filename
    mov ecx, 577
    mov edx, 0644
    int 0x80

    mov ebx, eax

    mov eax, 63
    mov ecx, 1
    int 0x80

    mov eax, 4
    mov ebx, 1
    mov ecx, msg
    mov edx, msg_len
    int 0x80

    mov eax, 1
    xor ebx, ebx
    int 0x80



