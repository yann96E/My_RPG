/*
65;6002;1c** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

// Library functions
void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
void freeif(void *thing);
char flag_cmp(char const crt, char const *fl);
char strcmp_crt(char const *s1, char const *s2, char const crt);
int my_strcmp(char const *s1, char const *s2);
int my_strlen(char const *str);
int my_strlen_crt(char const *str, char const end);
int my_strlen_end(char const *str, char const *flag);
int count_nbr_line(char const * const *array);
int my_strlen_cmp(char const *str, char const *end);
char cmp_extension(char const *str, char const *extension);
char strcmp_crt_number(char const *s1, char const *s2, char const crt);
char *my_strcat_end(char *str1, char *str2, char const end);

int get_fd(char *filename);
char *read_file(int fd, int rdsize);
char **parse(char *str, char sep);
char *my_strdup(char *str);
char *my_strndup(char *str, int n);
char *my_strcat(char *dest, char *src);
char *my_strcat_nf(char *dest, char *src);
char *my_strncat(char *dest, char *src, int nb);
int my_tablen(char **tab);
int count_files(char *path);
char *my_itoa(int nb, int malloc_size);
char *my_strcpy_m(char const *src);

// Library functions my_printf
int my_printf(char *, ...);
int check_format(char);
void my_put_binary(int);
void my_put_hexa(int);
void my_put_octal(int);
void my_put_unsigned_nbr(unsigned int);
void display_char(va_list);
void display_str(va_list);
void display_int(va_list);
void display_unsigned_int(va_list);
void display_octal(va_list);
void display_hexa(va_list);
void display_binary(va_list);
void display_pointer(va_list);

#endif /*MY_H_*/
