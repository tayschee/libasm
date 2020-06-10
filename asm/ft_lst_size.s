section .text
    global ft_lst_size

ft_lst_size :
    mov rax, 0
    cmp rdi, 0
    je end
    jmp while

while :
    inc rax
    cmp qword [rdi + 8], 0
    je end
    mov rdi, [rdi + 8]
    jmp while


end :
    ret
