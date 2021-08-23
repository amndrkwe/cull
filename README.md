# Cull

```c
// C
// Utilities for
// Lazy
// Losers
```

## ```str.h```:

It defines a new string wrapper called str and a bunch of really useful functions for string manipulation. Be them completely new functions or just reimplementations of the functions already in the C standard.

**macros**:
- ```CULL_STRTYPE```: defines how the new string type will be named, if no value is defined it defaults to ```str```.
- ```CULL_STRLISTTYPE```: defines how the new string list type will be named, if no value is defined it defaults to ```strlist```.

**types** (following default names):
- ```typedef struct str```: string, wrapper around a char*.
- ```typedef struct strlist```: list of strings, wrapper around str**.

**functions** (following default names):
- ```str* str_create(char* source)```: create string from c-style source string.
- ```void str_destroy(str* string)```: free string.

- ```strlist* strlist_create(size_t count)```: create strlist of given size.
- ```void strlist_destroy(strlist* list)```: free strlist.

- ```str* str_copy(const str* string)```: create a new_string based on another.
- ```bool str_compare(const str* s1, const str* s2)```: compare two strings, case sensitive.
- ```void str_resize(str* string, size_t size)```: resize string.
- ```void str_clear(str* string)```: fill string with spaces.
- ```bool str_is_empty(str* string)```: check if string is empty.
- ```str* str_concat(str* s1, str* s2)```: concatenate two strings into a new one.
- ```void str_trunc(str* string, uint32_t len)```: truncate given string to new length.
- ```void str_upper(str* string)```: set string to uppercase.
- ```void str_lower(str* string)```: set string to lowercase.
- ```char* str_find(const str* string, const str* substring)```: searches the string for a substring and returns a pointer to the character where it was found, returns -1 if it fails.
- ```int str_int(const str* string)```: get int from string, wrapper for ```strtol```.
- ```uint32_t str_uint(const str* string)```: get unsigned int from string.
- ```float str_float(const str* string)```: get float from string.
- ```double str_double(const str* string)```: get double from string
- ```strlist* str_tokenize(const str* string, char* delims)```: tokenize string and return strlist containing it.
