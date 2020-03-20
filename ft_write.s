section .text
    global ft_write

ft_write :
    mov rax, 1
    syscall
    cmp rax, -1
    jnge error
    ret

error :
    mov rax, -1
    ret
