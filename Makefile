NAME = libasm.a

asm  = asm/

SRCS = $(asm)ft_strlen.s $(asm)ft_read.s $(asm)ft_write.s $(asm)ft_strcpy.s $(asm)ft_strdup.s $(asm)ft_strcmp.s $(asm)ft_atoi_base.s

OBJS = $(SRCS:.s=.o)

.s.o : $(SRCS)
	nasm -f elf64 $<

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

all : $(NAME)
	

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all


