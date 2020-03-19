section .text                   ;start function
    global ft_strlen            ;declaration ft_strlen(*txt) / *txt == rdi

ft_strlen :
    mov rcx, 0                  ;rcx = 0
    cmp rdi, 0                  ;if (rdi == 0)
    je end                      ;   -> call end
    jmp while                   ;call while

while :
    cmp byte [rdi + rcx], 0     ;if (rdi[rcx] == 0)
    je end                      ;   -> call end
    inc rcx                     ;rcx++;
    jmp while                   ;call while

end :
    mov rax, rcx                ;rax = rcx
    ret                         ;return rax
