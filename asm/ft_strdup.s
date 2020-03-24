section	.text
			global	ft_strdup
			extern	malloc
			extern	ft_strcpy
			extern	ft_strlen

ft_strdup:
        mov     rax, rdi
        cmp     rdi, 0
        je      end
        jmp    allocate_memory

allocate_memory :
		call	ft_strlen
		inc		rax
		push	rdi
		mov		rdi, rax
		call 	malloc
        pop     rsi
        cmp     rax, 0
		je		end
		mov		rdi, rax
		call	ft_strcpy
		jmp     end
end:
		ret
		
