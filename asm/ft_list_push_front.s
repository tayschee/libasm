section .text
    global ft_list_push_front
    global malloc

ft_list_push_front :
    cmp rdi, 0
    je create_element
    jmp pass_list

pass_list :
