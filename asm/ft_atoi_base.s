section .text
    global ft_atoi_base
    extern ft_strlen

ft_atoi_base :
    cmp rdi, 0          ;nb == null ?
    je error
    cmp rsi, 0          ;base == null ?
    je error
    push rdi            ; rdi push
    mov rdi, rsi        ; base on rdi
    call ft_strlen      ; define size base
    pop rdi             ; pop rdi
    cmp rax, 1          ; if size base < 1 
    jng error
    mov rbx, rax
    mov rax, 0
    mov rcx, 0
    push rcx
    jmp check_base      

check_base :
    pop rcx
    mov dl, [rsi + rcx] ; dl = rsi[rcx]rcx
    cmp dl, '+'         ; dl == + ?
    je error            ;   -> error
    cmp dl, '-'         ;
    je error
    cmp dl, ' '
    je error
    inc rcx
    push rcx
    cmp dl, 0
    jne n_elem
    pop rcx
    jmp sign

n_elem :
    cmp byte [rsi + rcx], 0
    je check_base
    cmp dl, byte [rsi + rcx]
    je perror
    inc rcx
    jmp n_elem

sign:
    mov rdx, 1
    mov rcx, 0
    cmp byte [rdi + rcx], '-'
    je neg
    cmp byte [rdi + rcx], '+'
    je pos
    push rdx
    jmp int
    
neg :
    mov rdx, -1
    inc rcx
    push rdx
    jmp int

pos :
    inc rcx
    push rdx
    jmp int

int :
    cmp byte [rdi + rcx], 0
    je return
    mov dl, [rdi + rcx]
    inc rcx
    push rcx
    mov rcx, 0
    jmp while

while :
    cmp byte [rsi + rcx], 0
    je returnerror
    cmp dl, byte [rsi + rcx]
    je after
    inc rcx
    jmp while

after :
    mul rbx
    add rax, rcx
    pop rcx
    jmp int

returnerror :
    pop rcx
    jmp return

return :
    pop rcx
    imul rcx
    ret  

perror :
    pop rcx
    jmp error
    
error :
    mov rax, 0
    ret
