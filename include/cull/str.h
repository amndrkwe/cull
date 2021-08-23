#pragma once

#include <stdbool.h> // for bools
#include <stdint.h> // for size_t
#include <stdlib.h> // for calloc
#include <string.h> // for strncpy, memcmp etc...

#ifndef CULL_FUNC
    #define CULL_FUNC inline static
#endif

#define CULL_MAX_CSTR_LEN 256

#ifndef CULL_MAX
    #define CULL_MAX(n, m) (n < m) ? n : m
#endif

#define str(cstring) tostr(cstring)

typedef struct 
{
    size_t len; // length in characters
    char* data; // actual string
} str;

str tostr(char* cstring)
{
    str string;
    string.data = cstring;
    string.len = strlen(cstring);

    return string;
}

// create string from c-style source string
CULL_FUNC
str* str_create(const char* source)
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
void str_destroy(const str* string)
{
    if (string == NULL) return;

    free(string->data);
    free(string);
}

// copy string
CULL_FUNC
str* str_copy(const str* string)
{
    if (string == NULL) return;

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
    return (string->len == 0);
}

CULL_FUNC
bool str_len(str* string)
{
    return (string->len);
}

// concatonate two strings into a new one
CULL_FUNC
str* str_concat(str* s1, str* s2);

// truncate string
CULL_FUNC
void str_trunc(str* string);

// set string to uppercase
CULL_FUNC
void str_upper(str* string);

// set string to lowercase
CULL_FUNC
void str_lower(str* string);

// searches the string for a substring and returns the initial character from where it was found, returns -1 if it fails
CULL_FUNC
int str_find(const str* string, const str* substring);

// formats string following vprintf formatting
CULL_FUNC
void str_format(str* string, ...);

// get int from string
CULL_FUNC
int str_int(const str* string);

// get unsigned int from string
CULL_FUNC
uint32_t str_uint(const str* string);

// get float from string
CULL_FUNC
float str_float(const str* string);

// get double from string
CULL_FUNC
double str_double(const str* string);

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
