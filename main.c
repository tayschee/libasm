#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct  s_list
{
    void          *data;
    struct s_list *next;
}				t_list;


int ft_strlen(char *txt);
int ft_strcmp(char *s1, char *s2);
char *ft_strcpy(char *dest, char *source);
int  ft_read(int fd, char *buf, int buffer_size);
int ft_write(int fd, char *buf, size_t count);
int ft_atoi_base(char *nb, char *base);
char *ft_strdup(char *txt);

void	test_strdup()
{
    char txt[300];
    char c[2] = "y";
    int d;
        
    printf("ft_strdup est prototypé de la manière suivante :\nchar    *ft_strdup(char *txt)\n\n");  
    while (c[0] == 'y')
    {
        printf("Entre ta chaine de caractère : ");
        fgets(txt, 300, stdin);
        printf("\n");
		if (!strcmp(txt, "NULL"))
			printf("Sortie ft_strdup : %s\n", ft_strdup(NULL));
		else
        	printf("Sortie ft_strdup : %s\n", ft_strdup(txt));
        printf("Veux tu tester ft_strdup avec une autre chaine ? y/n ");
        fgets(c, 3, stdin);
        printf("%s\n", c);
		printf("%s\n", txt);
       
    }
}

void	 test_strlen()
{
    char txt[300];
    char c[2] = "y";
    int d;
        
    printf("ft_strlen est prototypé de la manière suivante :\nint    ft_strlen(char *txt)\n\n");  
    while ( c[0] == 'y')
    {
        printf("Entre ta chaine de caractère : ");
        fgets(txt, 300, stdin);
        printf("\n");
        if (!strcmp(txt, "NULL"))
        {
            printf("Sortie ft_strlen : %d\n", ft_strlen(NULL));
            printf("strlen segfault avec une chaine pointant sur NULL\n\n");
        }
        else
        {
            printf("Sortie ft_strlen : %d\n", ft_strlen(txt));
            printf("Sortie strlen : %ld\n\n", strlen(txt));
        }
        printf("Veux tu tester ft_strlen avec une autre chaine ? y/n ");
        fgets(c, 3, stdin);
        printf("\n");   
    }
}

void	test_strcmp()
{
    char txt[300];
    char txt2[300];
    char c[2] = "y";
    
    printf("ft_strcmp est prototypé de la manière suivante :\nint    ft_strcmp(char *s1, char *s2)\n\n");  
    while ( c[0] == 'y')
    {
        printf("Entre ta chaine de caractère s1 : ");
        fgets(txt, 300, stdin);
        printf("\n");
        printf("Entre ta chaine de caractère s2 : ");
        fgets(txt2, 300, stdin);
        printf("\n");
        if (!strcmp(txt, "NULL") && !strcmp(txt2, "NULL"))
        {
            printf("Sortie ft_strcmp : %d\n", ft_strcmp(NULL, NULL));
            printf("strcmp segfault\n\n");
        }
        if (!strcmp(txt, "NULL") && strcmp(txt2, "NULL"))
        {
            printf("Sortie ft_strcmp : %d\n", ft_strcmp(NULL, txt2));
            printf("strcmp segfault\n\n");
        }	
        if (strcmp(txt, "NULL") && !strcmp(txt2, "NULL"))
        {
            printf("Sortie ft_strcmp : %d\n", ft_strcmp(txt, NULL));
            printf("strcmp segfault\n\n");
        }        
        else
        {
            printf("Sortie ft_strcmp : %d\n", ft_strcmp(txt, txt2));
            printf("Sortie strcmp : %d\n\n", strcmp(txt, txt2));
        }
        printf("Veux tu tester ft_strcmp avec d'autres chaines ? y/n ");
        fgets(c, 3, stdin);
        printf("\n");
       
    }
}

void	test_strcpy()
{
    char txt[300];
    char txt2[300];
    char *dest2;
    char *dest;
    char c[2] = "y";
    int i;
    
    printf("ft_strcpy est prototypé de la manière suivante :\nchar    *ft_strcpy(char *dest, char *source)\n\n");  
    while ( c[0] == 'y')
    {
        printf("Entre ta chaine de caractère source : ");
        fgets(txt, 300, stdin);
        printf("\n");
        printf("Entre ta chaine de caractères dest : ");
        fgets(txt2, 300, stdin);
        printf("\n");
        i = ft_strlen(txt2);
        if (!strcmp(txt, "NULL"))
            i = -1;
        if (i >= 0)
        {
            if(!(dest = malloc(sizeof(char) * (i + 1))))
                break ;
            dest[i + 1] = '\0';
            if(!(dest2 = malloc(sizeof(char) * (i + 1))))
                break ;
            dest2[i + 1] = '\0';
        }
        if (!strcmp(txt, "NULL") && i < 0)
        {
            printf("Sortie ft_strcpy : %s\n", ft_strcpy(NULL, NULL));
            printf("strcpy segfault\n\n");
        }
        else if (strcmp(txt, "NULL") && i < 0)
        {

            printf("Sortie ft_strcpy : %s\n", ft_strcpy(txt, NULL));
            printf("ft_strcpy source: %s\n", txt);
            printf("strcpy segfault\n\n");
        }
        else if (!strcmp(txt, "NULL"))
        {
            printf("Sortie ft_strcpy : %s\n", ft_strcpy(txt, NULL));	
            printf("ft_strcpy source: %s\n", txt);
            printf("strcpy segfault\n\n");
        }        
        else
        {
            strcpy(dest, txt2);
            strcpy(dest2, txt2);
            printf("Sortie ft_strcpy : %s\n", ft_strcpy(dest, txt));
            printf("ft_strcpy source: %s\n", txt);
            printf("Sortie strcpy : %s\n", strcpy(dest2, txt));
            printf("strcpy source: %s\n\n", txt);
        }
        printf("Veux tu tester ft_strcpy avec d'autres chaines ? y/n ");
        fgets(c, 3, stdin);
        printf("\n");
        if (i < 0)
        {
            free(dest);
            free(dest2);
        }
    }
}

void	test_read()
{
    char txt[300];
    char txt2[300];
    char *buf;
    int fd;
    int i;
    int j;
    char c[2] = "y";
    
    printf("ft_read est prototypé de la manière suivante :\nint    ft_read(int fd, char *buf, int buffer_size)\n\n");  
    while ( c[0] == 'y')
    {
        printf("Je t'es mis à disposition quelques fichier à lire :\nread/lecture\nread/letter\nread/text\nread/word\nEn plus de l'entrée standard\n\nDonc quel fichier souhaiterais tu lire ? ");
        fgets(txt, 300, stdin);
        printf("\n");
        printf("Entre la taille de ton buffer_size : ");
        fgets(txt2, 300, stdin);
        printf("\n");
        i = atoi(txt2);
        if (i > 0)
        {
            if (!(buf = malloc(sizeof(char) * (i + 1))))
                break;
            buf[i + 1] = 0;
        }
        if (txt[0] == '0')
        {
            j = ft_read(0, buf, i);
            buf[i + 1] = 0;
            printf("%d : %s\n", j, buf);
        }
        else
        {
            fd = open(txt, O_RDONLY);
            while((j = ft_read(fd, buf, i)) > 0)
            {
                buf[i + 1] = 0;
                printf("%d : %s\n", j, buf);
            }
            printf("%d : %s\n", j, buf);
            close(fd);
        }
        printf("Veux tu tester ft_read avec un autres fichier ? y/n ");
        fgets(c, 3, stdin);
        printf("\n");
       
    }
}

void	test_write()
{
    char txt[300];
    char txt2[300];
    char txt3[300];
    int fd;
    int i;
    int j;
    char c[2] = "y";
    
    printf("ft_write est prototypé de la manière suivante :\nint    ft_write(int fd, char *buf, int count)\n\n");  
    while ( c[0] == 'y')
    {
        printf("Je t'es mis à disposition quelques fichier sur lesquels :\nwrite/write_here\nwrite/write_here2\nwrite_here3\nwrite/here4\nEn plus de l'entrée standard\n\nDonc sur quel fichier souhaiterais tu écrire ? ");
        fgets(txt, 300, stdin);
        printf("\n");
        printf("Chaine de caractère à écrire : ");
        fgets(txt2, 300, stdin);
        printf("\n");
        printf("Entre le nombre de caractère à écrire : ");
        fgets(txt3, 300, stdin);
        printf("\n");
        i = atoi(txt3);
        if (txt[0] == '0')
        {
            j = ft_write(0, txt2, i);
            printf(" : %d ft_write\n", j);
            j = write(0, txt2, i);
            printf(" : %d write\n", j);
        }
        else
        {
            printf("txt : %s\n", txt);
            fd = open(txt, O_APPEND);
            j = ft_write(fd, txt2, i);
            printf(": %d\n", j);
            close(fd);
        }
        printf("Veux tu tester ft_write avec un autres fichier ? y/n ");
        fgets(c, 3, stdin);
        printf("\n");
       
    }
}

void	test_atoi()
{
    char txt[300];
    char txt2[300];
    char c[2] = "y";
    
    printf("ft_atoi_base est prototypé de la manière suivante :\nint    ft_atoi_base(char *nb, char *base)\n\n");  
    while ( c[0] == 'y')
    {
        printf("Entre le nombre que tu veux convertir : ");
        fgets(txt, 300, stdin);
        printf("\n");
        printf("Entre la base : ");
        fgets(txt2, 300, stdin);
        printf("\n");
        if (!strcmp(txt, "NULL") && !strcmp(txt2, "NULL"))
        {
            printf("Sortie ft_atoi_base : %d\n", ft_atoi_base(NULL, NULL));
        }
        if (!strcmp(txt, "NULL") && strcmp(txt2, "NULL"))
        {
            printf("Sortie ft_atoi_base : %d\n", ft_atoi_base(NULL, txt2));
        }
        if (strcmp(txt, "NULL") && !strcmp(txt2, "NULL"))
        {
            printf("Sortie ft_atoi_base : %d\n", ft_atoi_base(txt, NULL));
        }        
        else
        {
            printf("Sortie ft_atoi_base : %d\n", ft_atoi_base(txt, txt2)); 
            if (!strcmp(txt2, "0123456789abcdef"))
                printf("Sortie printf %%x : %x\n\n", ft_atoi_base(txt, txt2));
        }
        printf("Veux tu tester ft_strcmp avec d'autres chaines ? y/n ");
        fgets(c, 3, stdin);
        printf("\n");
       
    }
}

int main(int argc, const char *argv[])
{
    char c[300];
        
    while (1)
    {
        printf("1 : ft_strlen\n2 : ft_strcmp\n3 : ft_strcpy\n4 : ft_read\n5 : ft_write\n6 : ft_strdup\n7 : ft_atoi_base\n\n0 : Arreter le programme\n\nAppuie sur la touche correspondant à la fonction que tu veux tester : ");
        fgets(c, 300, stdin);
        printf("\n");
        switch(atoi(c))
        {
            case 0 : exit(0);
            case 1 : test_strlen(); break;
            case 2 : test_strcmp(); break;
            case 3 : test_strcpy(); break;
            case 4 : test_read(); break;
            case 5 : test_write(); break;
            case 6 : test_strdup(); break;
            case 7 : test_atoi(); break;
            case 8 : printf("test_lst_push_front"); break;
            case 9 : printf("ft_lst_size\n"); break;
            default  : printf("Cela ne fait pas partie des propositions valides.\n");
        }
    }
    return 0;
}
