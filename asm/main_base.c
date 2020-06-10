#include <stdio.h>

int ft_atoi_base(char *nb, char *base);
int test(int c);

int main(int c, char **v)
{
    char *txt;
    char *base;

    txt = v[1];
    base = v[2];
    //printf("ft_atoi_base : %d\n", test(atoi(v[1])));
    printf("EN BASE 10 : %d\n", ft_atoi_base(txt, base));
    //printf("txt : %s\n", txt);
    //printf("base : %s\n", base);
    return 0;
}
