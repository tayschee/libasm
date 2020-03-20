section .text
    global ft_strcmp

ft_strcmp :
    mov rcx, 0
    mov dl, 0
    cmp rdi, 0
    je end
    cmp rsi, 0
    je end
    jmp while

while :
    mov dl, byte [rdi + rcx]
    sub dl, byte [rsi + rcx]    ;dl - rsi[rcx] (dl is neccary to have unsigned)
    cmp dl, 0
    jne end
    cmp byte [rdi + rcx], 0
    je end
    cmp byte [rsi + rcx], 0
    je end
    inc rcx
    jmp while

end :
    movsx rax, dl
    ret
