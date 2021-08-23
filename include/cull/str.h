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

#define CULL_UNIMPLEMENTED { return; }

#define CULL_DEBUG_STRING(str) printf("'%s' len: %llu\n", str->data, str->len)

// string, wrapper around a char*
typedef struct 
{
    size_t len; // length in characters
    char* data; // actual string
} str;

// list of strings, wrapper around str**
typedef struct
{
    size_t count; // string count
    str** data; // actual strings
} strlist;

// create string from c-style source string
CULL_FUNC
str* str_create(char* source)
{
    if (source == NULL) return NULL;

    size_t srclen = strlen(source);

    str* string = calloc(1, sizeof(str));
    char* data = calloc(srclen + 1, sizeof(char));

    if (string == NULL)
    {
        return NULL;
    }

    if (data == NULL)
    {
        free(string);
        return NULL;
    }

    data = strcpy(data, source);

    string->data = data;
    string->len = srclen;

    return (string);
}

// free string
CULL_FUNC
void str_destroy(str* string)
{
    if (string == NULL) return;
    if (string->data == NULL) return;
    if (string->len == 0) return;

    free(string->data);
    free(string);
}
// create strlist
CULL_FUNC
strlist* strlist_create(size_t count)
{
    if (count <= 0) goto error;
    
    strlist* list = calloc(count, sizeof(strlist));
    list->data = calloc(count, sizeof(str));

    if (list == NULL) goto error;

    list->count = count;

    // initialize list
    for (size_t i = 0; i < count; i++)
    {
        list->data[i] = str_create(" ");
    }

    return list;

error:
    for (size_t i = 0; i < list->count; i++)
    {
        if (list->data[i] == NULL) continue;
        str_destroy(list->data[i]);

    }
    if (list != NULL) free(list);

    return NULL;

}

// free strlist
void strlist_destroy(strlist* list)
{
    if (list == NULL) return;

    for (size_t i = 0; i < list->count; i++)
    {
        if (list->data[i] == NULL) continue;
        str_destroy(list->data[i]);
    }

    free(list);
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

    str_destroy(string);
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
    return (strtod(string->data, NULL));
}

// tokenize string and return strlist containing it
CULL_FUNC
strlist* str_tokenize(const str* string, char* delims)
{
    if (string == NULL) return NULL;

    strlist* list = strlist_create(string->len);
    if (list == NULL) goto error;

    unsigned int i = 0;
    char* s = strtok (string->data, delims);
    while(s != NULL)
    {
        list->data[i++] = str_create(s);
        s = strtok(NULL, delims);
    }

    list->count = i;

    return (list);

error:
    printf("ERROR\n");
    if (list != NULL) strlist_destroy(list);

    return NULL;

}

// strip string of trailing whitespace
CULL_FUNC
void str_strip(str* string) CULL_UNIMPLEMENTED
