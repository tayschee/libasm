#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int ft_strlen(char *txt);
int call(char *txt);
char *ft_strcpy(char *dest, char *src);
int ft_strcmp(char *s1, char *s2);
int ft_write(int fd, char *txt, int size);
int ft_read(int fd, char *buffer, int buffer_size);
char *ft_strdup(char *txt);
int mal(int c);

int main(int c, char **v)
{
    int  fd;
    char buf[10];
    char *txt;
    char *txt2;

    fd = open("test", O_RDONLY);
    printf("test\n");
    txt = NULL;
    txt2 = NULL;
    if (c >= 2)
        txt = v[1];
    if (c == 3)
        txt2 = v[2];
    if (c == 4)
        txt = NULL;
    printf("ft_strlen : %d\n", ft_strlen(txt));
    //printf("ft_strcpy : %s\n", ft_strcpy(txt, txt2));
    
    printf("ft_strcmp : %d\n", ft_strcmp(txt, txt2));
    //printf("strcmp : %d\n", strcmp(txt, txt2));
    printf(" : %d ft_write\n", ft_write(14, "test2", 3));
    printf(" : %ld write\n", write(14, "test2", 3));
    printf("read [%d]: %s\n", read(-1, buf, 10), buf);
    printf("ft_read [%d] : %s\n", ft_read(-1, buf, 9), buf);
    printf("call : %d\n", call(txt));
    printf("mal: %d\n", mal(12));
    //printf("ft_strdup : %s\n", ft_strdup(txt));
    return 0;
}
