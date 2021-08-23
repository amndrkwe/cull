# Cull

```c
// C
// Utilities for
// Lazy
// Losers
```

## Remember:

All usable functions and types are prefixed with the filename associated.
Reserved types or functions are prefixed with the an underscore.

## ```cstr.h```:

It defines a bunch of really useful functions for c-style string manipulation. Be them completely new functions or just reimplementations of the functions already in the C standard.

Here's a list of them:

**functions**:

- ```int cstr_compare(const char* str1, const char* str2)```: takes two strings and compares them, case sensitive, returns ```1``` if they are equal.
- ```const char* cstr_clone(const char* str)```: copy contents of a given string to a buffer and return a pointer to it, returns ```NULL``` if it fails.
- ```const char* cstr_lstrip(const char* str)```: strip leftmost whitespace of the given string and return a pointer to it, returns ```NULL``` if it fails.
- ```const char* cstr_rstrip(const char* str)```: strip rightmost whitespace of the given string and return a pointer to it, returns ```NULL``` if it fails.
- ```const char* cstr_strip(const char* str)```: strip leftmost and rightmost whitespace of the given string and return a pointer to a newly allocated string, returns ```NULL``` if it fails.
- ```const char* cstr_upper(const char* str)```: convert string to uppercase and return a pointer to the buffer containing the new string.
- ```const char* cstr_lower(const char* str)```: convert a string to lowercase and store it into a new buffer, returns a pointer to the buffer, returns ```NULL``` if it fails.
- ```const char* cstr_concat(const char* str1, const char* str2)```: concatenates the two given strings into a buffer and returns a pointer to it, returns ```NULL``` if it fails.
- ```const char* cstr_truncate(const char* str, const uint delim)```: truncate the contents of the given string following the delimeter and returns a pointer to it, returns ```NULL``` if it fails.
- ```const char** cstr_tokenize(const char* str, uint buff_size)```: tokenize string, store the resulting strings into a buffer and return a pointer to it, returns ```NULL``` if it fails.
- ```int cstr_find(const char* str, const char* substr)```: find given substring inside the given string, returns the character where the substring starts, returns -1 if it fails.
- ```const char* cstr_substr(const char* str, uint start, uint end)```: get substring from given string and returns a buffer with that substring stored, returns ```NULL``` if it fails.
- ```const char* cstr_format(const char* str, ...)```: formats string as if it was printf statement, stores it into a buffer and returns it, returns ```NULL``` if it fails.
- ```const char* cstr_fry(const char* string str)```: stir fries string.

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

