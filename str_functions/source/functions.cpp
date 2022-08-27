#include <stdio.h>
#include <assert.h>
#include <errno.h>
#include <stdlib.h>
#include "../headers/str_func.h"

int my_puts(const char *str) 
{
    assert(str);
    char c = 0;

    if (str == NULL) {
        return EOF;
    }

    for(int i = 0; (c = str[i]) != '\0'; i++)
        fputc(c, stdout);

    fputc('\n', stdout);

    return 0;
}

char * my_strchr(const char * str, int symbol) 
{
    assert(str);
    char temp_symbol = (char) symbol;
    char c = 0;

    for(int i = 0; (c = str[i]) != '\0'; i ++) 
        if (c == temp_symbol)
            return (char * ) str + i;

    return NULL;
}

size_t my_strlen(const char * str) 
{
    assert(str);
    size_t len = 0;
    assert(str);
    for(len = 0; str[len] != 0; len++);

    return len;
}

char *my_strcpy (char *dst, const char *src) 
{
    assert(dst);
    assert(src);

    int i = 0;

    for(i = 0; src[i] != 0; i++) 
        dst[i] = src[i];
    
    dst[i] = src[i];

    return dst;
}

char *my_strncpy (char *dst, const char *src, size_t len) 
{
    assert(dst);
    assert(src);
    assert(len > 0);

    size_t src_len = my_strlen(src);
    size_t dst_len = my_strlen(dst);

    if (src_len >= len) 
    {
        for(size_t i = 0; i < len; i++) 
            dst[i] = src[i];

    } else 
    {
        my_strcpy(dst, src);

        for(size_t i = dst_len; i < len; i++) 
            dst[i] = '\0';
    }

    return dst;
}

char * my_strcat(char * destptr, const char * srcptr) 
{
    assert(destptr);
    assert(srcptr);

    size_t dest_len = my_strlen(destptr);
    size_t src_len = my_strlen(srcptr);
    
    my_strcpy(destptr + dest_len, srcptr);

    return destptr;
}

char * my_strncat (char *destptr, const char *srcptr, size_t len)
{
    assert(destptr);
    assert(srcptr);
    assert(len > 0);

    size_t dest_len = my_strlen(destptr);
    
    my_strncpy(destptr + dest_len, srcptr, len);

    return destptr;
}

char * my_fgets(char * str, int num, FILE * filestream) 
{
    assert(str);
    char c = 0;

    for(size_t i = 0; ((c = fgetc(filestream)) != 0) && (c != EOF) && (c != '\n') && (i < num); i++)
        str[i] = c;
    
    if (!ferror(filestream))
        return NULL;

    return str;
}

char * my_strdup (const char *src) 
{
    size_t src_len = my_strlen(src);
    char * ptr = (char *) malloc((src_len + 1) * sizeof(char));

    ptr = my_strcpy(ptr, src);

    return ptr;
}

