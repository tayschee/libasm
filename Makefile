NAME : libasm.a

SRCS : ft_strlen.s

OBJS : $(SRCS:.s=.o)

%.o : %.s
	nasm -f elf64 $< -o $@

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all


