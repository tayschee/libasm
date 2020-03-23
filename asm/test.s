section .text
    global test

test :
    mov rcx, 1
    cmp rdi, 0
    je no_push
    push rcx
    jmp func

no_push :
    jmp func

func :
    cmp rsp, 0
    jge end
    mov rax, 0
    ret

end :
    pop rax
    ;mov rax, 0
    ret
