section .text
    global ft_read

ft_read :
    mov rax, 3
    mov rbx, rdi
    mov rcx, rsi
    syscall
    cmp rax, -1
    jnge error
    ret

error :
    mov rax, -1
    ret
