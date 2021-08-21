# Cull

```c
// C language
// U tilities for
// L azy*
// L osers*
```

## Remember:

All usable functions and types are prefixed with the filename associated.
Reserved types or functions are prefixed with the an underscore.

## ```str.h```:

It defines a bunch of really useful functions for string manipulation.

Here's a list of them:

- ```bool str_compare(const char* str1, const char* str2)```: takes two strings and compares them, case sensitive, returns ```true``` if they are equal.
- ```const char* str_clone(const char* str)```: copy contents of a given string to a buffer and return a pointer to it, returns ```NULL``` if it fails.
- ```const char* str_lstrip(const char* str)```: strip leftmost whitespace of the given string and return a pointer to it, returns ```NULL``` if it fails.
- ```const char* str_rstrip(const char* str)```: strip rightmost whitespace of the given string and return a pointer to it, returns ```NULL``` if it fails.
- ```const char* str_strip(const char* str)```: strip leftmost and rightmost whitespace of the given string and return a pointer to a newly allocated string, returns ```NULL``` if it fails.
- ```const char* str_upper(const char* str)```: converts the given string to uppercase and return a pointer to it, returns ```NULL``` if it fails.
- ```const char* str_concat(const char* str1, const char* str2)```: concatenates the two given strings into a buffer and returns a pointer to it, returns ```NULL``` if it fails.
- ```const char* str_truncate(const char* str, const uint delim)```: truncate the contents of the given string following the delimeter and returns a pointer to it, returns ```NULL``` if it fails.
- ```int str_find(const char* str, const char* substr)```: find given substring inside the given string, returns the character where the substring starts, returns -1 if it fails.
- ```const char* str_substr(const char* string, uint start, uint end)```: get substring from given string and returns a buffer with that substring stored, returns ```NULL``` if it fails.
- ```const char* str_vprintf(const char* string, ...)```: formats string as if it was printf statement, stores it into a buffer and returns it, returns ```NULL``` if it fails.