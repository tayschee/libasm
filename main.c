#include <stdio.h>
#include <string.h>

int ft_strlen(char *txt);

int main()
{
    printf("strlen : %d\n", strlen("12"));
    printf("si il y a pas ecrit la meme chose en dessous c'est pas bon\n");
    printf("ft_strlen : %d\n", ft_strlen("12"));
    return 0;
}