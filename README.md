# **This is the dev branch!** *Nothing here is finished!*
## don't use whatever is in here, but you are welcome to suggest changes and point out dumb errors.

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
- ```bool str_compare(const str_t* s1, const str_t* s2)```: compare two strings, case sensitive.
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


## ```os.h```:

Header useful for making os-independent code of any kind.

**functions**:

```const char* os_hostname()```: get hostname, returns ```NULL``` if it fails.
```const char* os_username()```: get current username, returns ```NULL``` if it fails.
```int os_system(const char* cmd)```: portable alternative to the ```system()``` function, returns ```0``` if it fails.
```void os_sleep(uint ms)```: portable alternative to the ```sleep()``` function.
```long os_total_physmem()```: returns total physical mem in MB of the machine.
```long os_avail_physmem()```: returns total available mem in MB of the machine.

## ```cnsl.h```:

Header essential for making os-independent command line applications. Great for developing windows compatible code without sacrificing your sanity having to deal with the Windows default API.



## ```int.h```:

Alternative typedef format, this mostly replaces the declarations in ```stdint.h```:

**macros**:

- ```#define U8_SIZE 1```: u8 size in bytes
- ```#define U16_SIZE 2```: u16 size in bytes
- ```#define U32_SIZE 4```: u32 size in bytes
- ```#define U64_SIZE 8```: u64 size in bytes

- ```#define UINT_SIZE 4```: u8 size in bytes

- ```#define I8_SIZE 1```: i8 size in bytes
- ```#define I16_SIZE 2```: i16 size in bytes
- ```#define I32_SIZE 4```: i32 size in bytes
- ```#define I64_SIZE 8```: i64 size in bytes

**types**

- ```typedef u8``` same as uint8_t
- ```typedef u16``` same as uint16_t
- ```typedef u32``` same as uint32_t
- ```typedef u64``` same as uint64_t

- ```typedef uint``` same as uint32_t

- ```typedef i8``` same as int8_t
- ```typedef i16``` same as int16_t
- ```typedef i32``` same as int32_t
- ```typedef i64``` same as int64_t

## ```math.h```:

Defines data structures and functions useful for mathematics.

**macros**:

- ```#define VEC2_SIZE 1```: math_vec2d size in bytes
- ```#define VEC3_SIZE 2```: math_vec3d size in bytes
- ```#define VEC4_SIZE 4```: math_vec4d size in bytes
- 
**types**:

- ```typedef math_vec2d```: 2 dimensional vector composed of two floats ```x, y```.
- ```typedef math_vec3d```: 3 dimensional vector composed of three floats ```x, y, z```.
- ```typedef math_vec4d```: 4 dimensional vector composed of four floats ```x, y, z, w```.

**functions**:

## ```args.h```

A header for argument parsing, extremely useful for applications of any kind.

