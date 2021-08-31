# Cull

```c
// C
// Utilities for
// Lazy
// Losers
```

Compatible with C99-C17

## ```str.h```:

It defines a new string wrapper called str and a bunch of really useful functions for string manipulation. Be them completely new functions or just reimplementations of the functions already in the C standard.

**macros**:
- ```CULL_STRTYPE```: defines how the new string type will be named, if no value is defined it defaults to ```str_t```.
- ```CULL_STRLISTTYPE```: defines how the new string list type will be named, if no value is defined it defaults to ```strlist_t```.

**types** (following default names):
- ```typedef struct str_t```: string, wrapper around a char*.
- ```typedef struct strlist_t```: list of strings, wrapper around str_t**.

**functions** (following default names):
- ```str_t* str_create(char* source)```: create string from c-style source string.
- ```void str_destroy(str_t* string)```: free string.

- ```strlist_t* strlist_create(size_t count)```: create strlist of given size.
- ```void strlist_destroy(strlist_t* list)```: free strlist.

- ```str_t* str_copy(const str_t* string)```: create a new_string based on another.
- ```bool str_compare(const str_t* s1, const str_t* s2)```: compare two strings and returns true if they are equal, case sensitive.
- ```void str_resize(str_t* string, size_t size)```: resize string.
- ```void str_clear(str_t* string)```: fill string with spaces.
- ```bool str_is_empty(str_t* string)```: check if string is empty.
- ```str_t* str_concat(str_t* s1, str_t* s2)```: concatenate two strings into a new one.
- ```void str_trunc(str_t* string, uint32_t len)```: truncate given string to new length.
- ```void str_upper(str_t* string)```: set string to uppercase.
- ```void str_lower(str_t* string)```: set string to lowercase.
- ```char* str_find(const str_t* string, const str_t* substring)```: searches the string for a substring and returns a pointer to the character where it was found, returns -1 if it fails.
- ```int str_int(const str_t* string)```: get int from string, wrapper for ```strtol```.
- ```uint32_t str_uint(const str_t* string)```: get unsigned int from string.
- ```float str_float(const str_t* string)```: get float from string.
- ```double str_double(const str_t* string)```: get double from string
- ```strlist_t* str_tokenize(const str_t* string, char* delims)```: tokenize string following delims and return strlist containing the tokens.
