section .text
    global ft_write

ft_write :
    mov rax, 4
    mov rbx, rdi
    mov rcx, rsi
    syscall
    cmp rax, -1
    jnge error
    ret

error :
    mov rax, -1
    ret
