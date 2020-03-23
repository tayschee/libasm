#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
    void    *data;
    struct s_list *next;
}               t_list;

t_list  *ft_create_element(t_list *list, void *data)

int main()
{
    t_list *test;
    char c = 'c';

    if(!(test = malloc(sizeof(t_list))))
        return 1;
    printf("sizeof : %d\n", sizeof(test->data));
    printf("sizeof : %d\n", sizeof(test->next));   
    printf("sizeof : %d\n", sizeof(t_list));
    printf("data : %p", ft_create_element(test, &c));
    return 0;  
}
