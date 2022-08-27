#include "../headers/str_func.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
    char test_str[100] = "This is test str\0bla";
    char dest_str[100] = "";
    char str1[100] = "This is str1";
    char str2[100] = "This is str2";
    char str3[100] = "This is str3";
    char str[100];
    char * ptr1;

    printf("My_puts function:\n");
    my_puts(test_str);

    printf("My_strchr:\n");
    char * ptr = my_strchr(test_str, 'r');
    printf("%c\n", *ptr);
    
    printf("My_strlen:\n%s\nsymbols: %lu\n", test_str, my_strlen(test_str));

    printf("My_strcpy:\n");
    my_strcpy(dest_str, test_str);
    printf("test_str: %s\ndest_str: %s\n", test_str, dest_str);

    printf("My_strncpy:\n");
    printf("str1: %s\n", str1);
    my_strncpy(str1, "STRNCPY_TEST", 5);
    printf("str1: %s\n", str1);

    printf("My_strcat:\nstr1: %s\nstr2: %s\n", str1, str2);
    my_strcat(str1, str2);
    printf("str: %s\n", str1);

    
    printf("My_strncat:\nstr3: %s\nstr2: %s\n", str3, str2);
    my_strncat(str3, str2, 6);
    printf("str: %s\n", str3);
    
    my_fgets(str, 5, stdin);
    my_puts(str);

    printf("My_strdup:\n");
    ptr1 = my_strdup(test_str);
    my_puts(ptr1);
    free(ptr1);

    return 0;
}