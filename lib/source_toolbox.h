/*
** EPITECH PROJECT, 2018
** source_toolbox.h
** File description:
** ressources for lib
*/

#ifndef SOURCE_TOOLBOX_H
    #define SOURCE_TOOLBOX_H
    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdarg.h>
    #include <dirent.h>
    #include <time.h>
    #include <pwd.h>
    #include <grp.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <sys/sysmacros.h>
    #include <sys/wait.h>
    #include <fcntl.h>

    int my_getnbr(char const *str);
    char *my_nb_to_str(long nb);
    int my_put_nbr(long  nb);
    int my_put_nbr_uint(long nb);
    int my_put_nbr_base(long nb, char *base);
    int my_put_nbr_base_uns(long nb, char *base);
    void my_putchar(char c);
    void my_putchar_error(char c);
    int my_putstr(char const *str);
    int my_puttab(char const **tab);
    int my_putstr_error(char const *str);
    int my_compute_power_it(int nb, int p);
    char *my_revstr(char *str);
    int my_atoi(char *str);
    char *my_strcpy(char *dest, char const *src);
    char *my_strcat(char *dest, char const *src);
    int my_strlen(char const *str);
    int my_tablen(char const **tab);
    int my_strlen_delim(char const *str, char delimiter);
    int my_compare_str(char *str1, char *str2);
    int my_str_isnum(int ac, char **str);
    int my_isnum(char *str);
    char **my_str_to_word_array(char const *str, char delimiter);
    char **my_str_to_word_array_mod(char const *str, char delimiter);

    int my_printf(char *str, ...);
    void hexadec_maj(va_list args);
    void hexadec_min(va_list args);
    void integer(va_list args);
    void string(va_list args);
    void character(va_list args);
    void uns_int(va_list args);
    void percent(va_list args);
    void binary(va_list args);
    void octal(va_list args);
    void pointer(va_list args);
    void non_printable(va_list args);
#endif

#ifndef PRINT_STRUCT
    #define PRINT_STRUCT
    typedef struct flags
    {
        char to_print;
        void (*functionptr)(va_list);
    } flags_t;
#endif