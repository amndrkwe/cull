#pragma once

#include <stdbool.h> // for booleans
#include <stdint.h> // for size_t
#include <stdlib.h> // for calloc etc
#include <string.h> // for strncpy, memcmp etc...
#include <ctype.h> // toupper / tolower
#include <stdarg.h> // va_lists etc
#include <stdio.h> // sprintf etc
#include <signal.h> // for raise

#ifndef CULL_FUNC
    #define CULL_FUNC inline static
#endif

#ifndef CULL_STRTYPE
    #define CULL_STRTYPE str_t
#endif

#ifndef CULL_STRLISTTYPE
    #define CULL_STRLISTTYPE strlist_t
#endif

#ifndef CULL_MAX
    #define CULL_MAX(n, m) (n < m) ? n : m
#endif

#define CULL_UNIMPLEMENTED printf("%s is not implemented yet!\n", __func__); raise(SIGILL)

// string, wrapper around a char*
typedef struct 
{
    char* data; // actual string
    size_t len; // length in characters
} cull_str;

// list of strings, wrapper around cull_str**
typedef struct
{
    cull_str** data; // actual strings
    size_t count; // string count
} cull_strlist;

// create string from c-style source string
CULL_FUNC
cull_str* str_create(char* source)
{
    if (source == NULL) return NULL;

    size_t srclen = strlen(source);

    cull_str* string = calloc(1, sizeof(cull_str));
    char* data = calloc(srclen + 1, sizeof(char));

    if (string == NULL || data == NULL)
    {
        goto error;
    }

    data = strcpy(data, source);

    string->data = data;
    string->len = srclen;

    return (string);

error:
    free(string);
    free(data);

    return NULL;
}

// free string
CULL_FUNC
void str_destroy(cull_str* string)
{
    if (string == NULL) return;
    if (string->data == NULL) return;
    if (string->len == 0) return;

    free(string->data);
    free(string);
}
// create strlist of given size
CULL_FUNC
cull_strlist* strlist_create(size_t count)
{
    if (count <= 0) goto error;
    
    cull_strlist* list = calloc(count, sizeof(cull_strlist));
    list->data = calloc(count, sizeof(cull_str));

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

    free(list);

    return NULL;

}

// free strlist
void strlist_destroy(cull_strlist* list)
{
    if (list == NULL) return;

    for (size_t i = 0; i < list->count; i++)
    {
        str_destroy(list->data[i]);
    }

    free(list);
}

// create a new_string based on another.
CULL_FUNC
cull_str* str_copy(const cull_str* string)
{
    if (string == NULL) return NULL;

    cull_str* new_str = str_create(string->data);
    return new_str;
}

// compare two strings, case sensitive
CULL_FUNC
bool str_compare(const cull_str* s1, const cull_str* s2)
{
    if (s1 == NULL || s2 == NULL) return false;    

    bool result = memcmp(s1->data, s2->data, CULL_MAX(s1->len, s2->len));

    return (result == 0);
}

size_t str_getsize(cull_str* string)
{
    
}

// resize string
CULL_FUNC
bool str_resize(cull_str* string, size_t size)
{
    cull_str* new_string = NULL;
    new_string->data = calloc(size, sizeof(char));

    if (new_string == NULL) return false;

    strncpy(new_string->data, string->data, string->len);
    new_string->len = size - 1;

    str_destroy(string);
    string = new_string;

    return true;
}

// fill string with spaces
CULL_FUNC
void str_clear(cull_str* string)
{
    if (string == NULL) return;

    if (string->len == 0)
        return;
    
    memset(string->data, 0, string->len);
}

// check if string is empty
CULL_FUNC
bool str_is_empty(cull_str* string)
{
    return (string->len <= 1);
}

// concatenate two strings into a new one
CULL_FUNC
cull_str* str_concat(cull_str* s1, cull_str* s2)
{
    if (s1 == NULL || s2 == NULL)
    {
        return NULL;
    }
    
    cull_str* buffer = str_copy(s1);

    if (buffer == NULL) 
    {
        str_destroy(buffer);
        return NULL;
    }

    buffer->len += s2->len;

    strcat(buffer->data, s2->data);

    return (buffer);
}

// truncate string to new length
CULL_FUNC
void str_trunc(cull_str* string, uint32_t len)
{
    if (string == NULL) return;

    if (len > string->len) return;

    string->data[len - 1] = 0; // null terminator
    string->len = len;
}

// set string to uppercase
CULL_FUNC
void str_upper(cull_str* string)
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
void str_lower(cull_str* string)
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
char* str_find(const cull_str* string, const cull_str* substring)
{
    if (string == NULL || substring == NULL) return NULL;

    char* location = strstr(string->data, substring->data);
    return location;
}

// get int from string
CULL_FUNC
int str_int(const cull_str* string)
{
    return (int)(strtol(string->data, NULL, 0));
}

// get unsigned int from string
CULL_FUNC
uint32_t str_uint(const cull_str* string)
{
    return (uint32_t)(strtoul(string->data, NULL, 0));
}

// get float from string
CULL_FUNC
float str_float(const cull_str* string)
{
    return (strtof(string->data, NULL));
}

// get double from string
CULL_FUNC
double str_double(const cull_str* string)
{
    return (strtod(string->data, NULL));
}

// tokenize string and return cull_strlist containing it
CULL_FUNC
cull_strlist* str_tokenize(const cull_str* string, char* delims)
{
    if (string == NULL) return NULL;

    cull_strlist* list = strlist_create(string->len);
    if (list == NULL) goto error;

    unsigned int i = 0;
    cull_str* new_string ;
    char* s = strtok (string->data, delims);
    while(s != NULL)
    {
        new_string = str_create(s);
        if (new_string == NULL) goto error;

        list->data[i++] = new_string;
        s = strtok(NULL, delims);
    }

    list->count = i;

    return (list);

error:
    printf("ERROR\n");
    strlist_destroy(list);

    return NULL;

}

// strip string of trailing whitespace
CULL_FUNC
void str_strip(cull_str* string)
{
    CULL_UNIMPLEMENTED;
} 

typedef cull_str CULL_STRTYPE;
typedef cull_strlist CULL_STRLISTTYPE;  