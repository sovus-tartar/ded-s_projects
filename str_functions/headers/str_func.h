#include <stdio.h>

//TODO: puts, strchr, strlen, strcpy, 
//strncpy, strcat, strncat, fgets, strdup, getline
//Using: putchar, getchar, getc, putc

int my_puts(const char *str);

char * my_strchr(const char * string, int symbol);

size_t my_strlen(const char * str);

char * my_strcpy (char *dst, const char *src);

char * my_strncpy (char *dst, const char *src, size_t len);

char * my_strcat(char * destptr, const char * srcptr);

char * my_strncat (char *dstptr, const char *srcptr, size_t len);

char * my_fgets(char * str, int num, FILE * filestream);

char * my_strdup (const char *src);