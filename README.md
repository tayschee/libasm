# libasm
![42](https://img.shields.io/static/v1?label=&labelColor=000000e&logo=42&message=project&color=000000&style=flate)
![Stars](https://img.shields.io/github/stars/tayschee/libasm?style=social)

## Summary
- [About The Project](#about-the-project)
- [Getting Started](#getting-started)
  - [Installation](#installation)
  - [Use Library](#use-library)

## About The Project
[libasm](https://cdn.intra.42.fr/pdf/pdf/32882/fr.subject.pdf) is project of 42Paris to learn assembly \
Like the previous project libft is consist to create library with commom C funtion code in assembly like strlen

## Getting Started
### Installation
Clone and move into clone directory:
```
git clone https://github.com/tayschee/libasm.git libasm
cd libasm
```

### Compilation
To compile run:
```
make
```
OR
```
make bonus
```
To add linked list functions in your library

### Use Library

To use one of those containers in your C code, add prototype of [functions](#available-function) in your C project. \
then add to your link edition (ex: gcc -o):
```
 -L path/to/libasm.a/directory -l libasm.a
 ```

## Available Function

int ft_strlen(char *txt); \
int ft_strcmp(char *s1, char *s2); \
char *ft_strcpy(char *dest, char *source); \
int  ft_read(int fd, char *buf, int buffer_size); \
int ft_write(int fd, char *buf, size_t count); \
int ft_atoi_base(char *nb, char *base); \
char *ft_strdup(char *txt);
