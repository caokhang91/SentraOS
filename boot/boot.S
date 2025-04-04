[BITS 64]
[GLOBAL _start]

section .rodata
align 4096
limine_request:
    .quad 0            ; Request array terminator

section .bss
align 16
stack_space: resb 4096
stack_top:

section .text
_start:
    cli
    mov rsp, stack_top
    call kernel_main
    hlt

kernel_main:
    mov rax, 0xb8000
    mov byte [rax], 'K'
    mov byte [rax+1], 0x07
    jmp $
