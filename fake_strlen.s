segment .text
    extern strlen
    global ft_strlen

ft_strlen:
    call strlen 
    ret
