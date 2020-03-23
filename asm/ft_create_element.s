section .text
    global ft_create_element
    extern malloc

ft_create_element :
    mov [rdi], rsi
    mov byte [rdi + 8], 0
    mov rax, rdi
    ret
    
