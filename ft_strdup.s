section .text
    global ft_strdup
    extern ft_strlen
    extern ft_strcpy
    extern malloc

ft_strdup :
    mov rax, 0
    cmp rdi, 0
    je end
    call ft_strlen
    jmp allocation

allocation :
    inc rax
    push rdi
    mov rdi, rax
    call malloc
    cmp rax, 0
    je end
    pop rdi
    ret
    ;jmp dup

;dup :
    ;mov rdi, rax
    ;mov rsi, rdx
    ;call ft_strcpy
    ;jmp end


end :
    ret
