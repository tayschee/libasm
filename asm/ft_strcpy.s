section .txt
    global ft_strcpy
    
ft_strcpy :
    mov rcx, 0                      ;rcx = 0
    cmp rdi, 0                      ;if (rdi == 0)
    je end                          ;   -> call end
    cmp rsi, 0                      ;if (rsi == 0)
    je end                          ;   -> call end
    jmp while                       ;call while

while :
    cmp byte [rdi + rcx], 0         ;if (rdi[rcx] == 0)
    je end                          ;   -> call end
    mov dl, [rsi + rcx]        ;(partie basse rdx)dl(8bits) = rsi[rcx]
    mov [rdi + rcx], dl
    cmp byte [rsi + rcx], 0         ;if (rsi[rcx] == 0)
    je end                          ;   -> call end
    inc rcx                         ;rcx++
    jmp while                       ;call while                   
        
end :
    mov rax, rdi                    ;rax = rdi
    ret                             ;return rax

