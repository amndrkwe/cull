#pragma once

#include <stdbool.h> // for booleans
#include <stdint.h> // for size_t
#include <stdlib.h> // for calloc etc
#include <string.h> // for strncpy, memcmp etc...
#include <ctype.h> // toupper / tolower
#include <stdarg.h> // va_lists etc
#include <stdio.h> // sprintf etc

#ifndef CULL_FUNC
    #define CULL_FUNC inline static
#endif

#ifndef CULL_STRTYPE
    #define CULL_STRTYPE str
#endif

#ifndef CULL_STRLISTTYPE
    #define CULL_STRLISTTYPE strlist
#endif

#ifndef CULL_MAX
    #define CULL_MAX(n, m) (n < m) ? n : m
#endif

#define _CULL_UNIMPLEMENTED { return; }

// string, wrapper around a char*
typedef struct 
{
    char* data; // actual string
    size_t len; // length in characters
} _cullstr;

// list of strings, wrapper around _cullstr**
typedef struct
{
    _cullstr** data; // actual strings
    size_t count; // string count
} _cullstrlist;

// create string from c-style source string
CULL_FUNC
_cullstr* str_create(char* source)
{
    if (source == NULL) return NULL;

    size_t srclen = strlen(source);

    _cullstr* string = calloc(1, sizeof(_cullstr));
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
void str_destroy(_cullstr* string)
{
    if (string == NULL) return;
    if (string->data == NULL) return;
    if (string->len == 0) return;

    free(string->data);
    free(string);
}
// create strlist of given size
CULL_FUNC
_cullstrlist* strlist_create(size_t count)
{
    if (count <= 0) goto error;
    
    _cullstrlist* list = calloc(count, sizeof(_cullstrlist));
    list->data = calloc(count, sizeof(_cullstr));

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
void strlist_destroy(_cullstrlist* list)
{
    if (list == NULL) return;

    for (size_t i = 0; i < list->count; i++)
    {
        if (list->data[i] == NULL) continue;
        str_destroy(list->data[i]);
    }

    free(list);
}

// create a new_string based on another.
CULL_FUNC
_cullstr* str_copy(const _cullstr* string)
{
    if (string == NULL) return NULL;

    _cullstr* new_str = str_create(string->data);
    return new_str;
}

// compare two strings, case sensitive
CULL_FUNC
bool str_compare(const _cullstr* s1, const _cullstr* s2)
{
    if (s1 == NULL || s2 == NULL) return false;    

    bool result = memcmp(s1->data, s2->data, CULL_MAX(s1->len, s2->len));

    return (result == 0);
}

// resize string
CULL_FUNC
void str_resize(_cullstr* string, size_t size)
{
    _cullstr* new_string = NULL;
    new_string->data = calloc(size, sizeof(char));
    strncpy(new_string->data, string->data, string->len);

    new_string->len = size - 1;

    str_destroy(string);
    string = new_string;
}

// fill string with spaces
CULL_FUNC
void str_clear(_cullstr* string)
{
    if (string == NULL) return;

    if (string->len == 0)
        return;
    
    memset(string->data, 0, string->len);
}

// check if string is empty
CULL_FUNC
bool str_is_empty(_cullstr* string)
{
    return (string->len <= 1);
}

// concatenate two strings into a new one
CULL_FUNC
_cullstr* str_concat(_cullstr* s1, _cullstr* s2)
{
    if (s1 == NULL || s2 == NULL)
    {
        return NULL;
    }
    
    _cullstr* buffer;

    buffer = str_copy(s1);
    buffer->len += s2->len;

    strcat(buffer->data, s2->data);

    return (buffer);
}

// truncate string to new length
CULL_FUNC
void str_trunc(_cullstr* string, uint32_t len)
{
    if (string == NULL) return;

    if (len > string->len) return;

    string->data[len - 1] = 0; // null terminator
    string->len = len;
}

// set string to uppercase
CULL_FUNC
void str_upper(_cullstr* string)
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
void str_lower(_cullstr* string)
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
char* str_find(const _cullstr* string, const _cullstr* substring)
{
    if (string == NULL || substring == NULL) return NULL;

    char* location = strstr(string->data, substring->data);
    return location;
}

// get int from string
CULL_FUNC
int str_int(const _cullstr* string)
{
    return (int)(strtol(string->data, NULL, 0));
}

// get unsigned int from string
CULL_FUNC
uint32_t str_uint(const _cullstr* string)
{
    return (uint32_t)(strtoul(string->data, NULL, 0));
}

// get float from string
CULL_FUNC
float str_float(const _cullstr* string)
{
    return (strtof(string->data, NULL));
}

// get double from string
CULL_FUNC
double str_double(const _cullstr* string)
{
    return (strtod(string->data, NULL));
}

// tokenize string and return _cullstrlist containing it
CULL_FUNC
_cullstrlist* str_tokenize(const _cullstr* string, char* delims)
{
    if (string == NULL) return NULL;

    _cullstrlist* list = strlist_create(string->len);
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
void str_strip(_cullstr* string) _CULL_UNIMPLEMENTED

typedef _cullstr CULL_STRTYPE;
typedef _cullstrlist CULL_STRLISTTYPE;