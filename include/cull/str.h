#pragma once

#include <stdbool.h> // for bools
#include <stdint.h> // for size_t
#include <stdlib.h> // for calloc
#include <string.h> // for strncpy, memcmp etc...
#include <ctype.h> // toupper / tolower
#include <stdarg.h> // va_lists etc
#include <stdio.h> // sprintf

#ifndef CULL_FUNC
    #define CULL_FUNC inline static
#endif

#ifndef CULL_MAX_CSTR_LEN
    #define CULL_MAX_CSTR_LEN 256
#endif

#ifndef CULL_BUFFER_SIZE
    #define CULL_BUFFER_SIZE 1024
#endif
#ifndef CULL_MAX
    #define CULL_MAX(n, m) (n < m) ? n : m
#endif

#define CULL_DEBUG_STRING(str) printf("'%s' len: %llu\n", str->data, str->len)

typedef struct 
{
    size_t len; // length in characters
    char* data; // actual string
} str;

// create string from c-style source string
CULL_FUNC
str* str_create(char* source)
{
    if (source == NULL) return NULL;

    size_t srclen = strlen(source);

    str* string = calloc(1, sizeof(str));
    char* data = calloc(srclen, sizeof(char));

    data = strncpy(data, source, srclen);

    string->data = data;
    string->len = srclen;

    return (string);
}

// free string
CULL_FUNC
void str_destroy(str* string)
{
    if (string == NULL) return;

    free(string->data);
    free(string);
}

// copy string
CULL_FUNC
str* str_copy(const str* string)
{
    if (string == NULL) return NULL;

    str* new_str = str_create(string->data);
    return new_str;
}

// compare two strings, case sensitive
CULL_FUNC
bool str_compare(const str* s1, const str* s2)
{
    if (s1 == NULL || s2 == NULL) return false;    

    bool result = memcmp(s1->data, s2->data, CULL_MAX(s1->len, s2->len));

    return (result == 0);
}

CULL_FUNC
void str_resize(str* string, size_t size)
{
    str* new_string = NULL;
    new_string->data = calloc(size, sizeof(char));
    strncpy(new_string->data, string->data, string->len);

    new_string->len = size - 1;

    CULL_DEBUG_STRING(new_string);

    free(string);
    string = new_string;
}

// empty given string
CULL_FUNC
void str_clear(str* string)
{
    if (string == NULL) return;

    if (string->len == 0)
        return;
    
    memset(string->data, 0, string->len);
    string->len = 0;
}

// check if string is empty
CULL_FUNC
bool str_is_empty(str* string)
{
    return (string->len <= 1);
}

// concatonate two strings into a new one
CULL_FUNC
str* str_concat(str* s1, str* s2)
{
    if (s1 == NULL || s2 == NULL)
    {
        return NULL;
    }
    
    str* buffer;

    buffer = str_copy(s1);
    buffer->len += s2->len;

    strcat(buffer->data, s2->data);

    return (buffer);
}

// truncate string to new length
CULL_FUNC
void str_trunc(str* string, uint32_t len)
{
    if (string == NULL) return;

    if (len > string->len) return;

    string->data[len - 1] = 0; // null terminator
    string->len = len;
}

// set string to uppercase
CULL_FUNC
void str_upper(str* string)
{
    if (string == NULL) return;
    
    char* c;
    for (uint32_t i = 0; i < string->len; i++)
    {
        string->data[i] = toupper(string->data[i]);
    }
}

// set string to lowercase
CULL_FUNC
void str_lower(str* string)
{
    if (string == NULL) return;
    
    char* c;
    for (uint32_t i = 0; i < string->len; i++)
    {
        string->data[i] = tolower(string->data[i]);
    }
}

// searches the string for a substring and returns a pointer to the string at the location specified, returns -1 if it fails
CULL_FUNC
char* str_find(const str* string, const str* substring)
{
    if (string == NULL || substring == NULL) return NULL;

    char* location = strstr(string->data, substring->data);
    return location;
}

// get int from string
CULL_FUNC
int str_int(const str* string)
{
    return (int)(strtol(string->data, NULL, 0));
}

// get unsigned int from string
CULL_FUNC
uint32_t str_uint(const str* string)
{
    return (uint32_t)(strtoul(string->data, NULL, 0));
}

// get float from string
CULL_FUNC
float str_float(const str* string)
{
    return (strtof(string->data, NULL));
}

// get double from string
CULL_FUNC
double str_double(const str* string)
{
    return strtod(string->data, NULL);
}

// tokenize string and store to buffer
CULL_FUNC
bool str_tokenize(const str* string, str** buffer, size_t buffer_size);

// splits string following delimeter and store to buffer
CULL_FUNC
bool str_split(const str* string, const char delim, str** buffer, str** buffer_size);

// strip string of leftmost whitespace
CULL_FUNC
void str_lstrip(str* string);

// strip string of leftmost whitespace
CULL_FUNC
void str_lstrip(str* string);
